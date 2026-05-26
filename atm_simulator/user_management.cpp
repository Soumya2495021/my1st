#include "user_management.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

namespace atm {

bool loadUsers(std::vector<User>& users, const std::string& fileName) {
    std::ifstream input(fileName);
    if (!input) {
        return false;
    }

    users.clear();
    std::string line;
    while (std::getline(input, line)) {
        if (line.empty()) {
            continue;
        }

        std::stringstream ss(line);
        std::string username;
        std::string password;
        std::string role;
        double balance = 0.0;

        if (!std::getline(ss, username, ',')) {
            continue;
        }
        if (!std::getline(ss, password, ',')) {
            continue;
        }
        if (!std::getline(ss, role, ',')) {
            continue;
        }

        ss >> balance;

        users.push_back({username, password, role, balance});
    }

    return true;
}

bool saveUsers(const std::vector<User>& users, const std::string& fileName) {
    std::ofstream output(fileName, std::ios::trunc);
    if (!output) {
        return false;
    }

    for (const User& user : users) {
        output << user.username << ',' << user.password << ',' << user.role << ',' << user.balance << '\n';
    }

    return true;
}

bool addUser(std::vector<User>& users, const std::string& fileName, const User& user) {
    users.push_back(user);
    return saveUsers(users, fileName);
}

int findUserIndex(const std::vector<User>& users, const std::string& username, const std::string& password) {
    for (size_t index = 0; index < users.size(); ++index) {
        if (users[index].username == username && users[index].password == password) {
            return static_cast<int>(index);
        }
    }
    return -1;
}

void printUser(const User& user) {
    std::cout << "Username : " << user.username << "\n";
    std::cout << "Role     : " << user.role << "\n";
    std::cout << "Balance  : " << user.balance << "\n";
}

void ensureDefaultUsers(const std::string& fileName) {
    std::ifstream existing(fileName);
    if (existing) {
        return;
    }

    std::vector<User> defaults = {
        {"admin", "admin123", "admin", 10000.0},
        {"common", "common123", "common", 2000.0}
    };

    saveUsers(defaults, fileName);
}

} // namespace atm
