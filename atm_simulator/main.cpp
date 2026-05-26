#include <iostream>
#include <string>
#include <vector>

#include "atm_operations.h"
#include "user_management.h"

namespace atm {

int mainMenu() {
    int choice = 0;
    std::cout << "\nATM Simulation System\n";
    std::cout << "1. Login\n";
    std::cout << "2. Exit\n";
    std::cout << "Choose option: ";
    std::cin >> choice;
    return choice;
}

} // namespace atm

int main() {
    const std::string fileName = "users.txt";
    std::vector<atm::User> users;

    atm::ensureDefaultUsers(fileName);

    if (!atm::loadUsers(users, fileName)) {
        std::cout << "Unable to load user data.\n";
        return 1;
    }

    int choice = atm::mainMenu();
    if (choice == 1) {
        std::string username;
        std::string password;
        std::cout << "Username: ";
        std::cin >> username;
        std::cout << "Password: ";
        std::cin >> password;

        int index = atm::findUserIndex(users, username, password);
        if (index == -1) {
            std::cout << "Invalid credentials.\n";
            return 0;
        }

        if (users[index].role == "admin") {
            atm::adminMenu(users, fileName);
        } else {
            atm::commonMenu(users, fileName, username, password);
        }
    } else {
        std::cout << "Thank you for using ATM Simulation.\n";
    }

    return 0;
}
