#ifndef USER_MANAGEMENT_H
#define USER_MANAGEMENT_H

#include <string>
#include <vector>

namespace atm {

struct User {
    std::string username;
    std::string password;
    std::string role;
    double balance;
};

bool loadUsers(std::vector<User>& users, const std::string& fileName);
bool saveUsers(const std::vector<User>& users, const std::string& fileName);
bool addUser(std::vector<User>& users, const std::string& fileName, const User& user);
int findUserIndex(const std::vector<User>& users, const std::string& username, const std::string& password);
void printUser(const User& user);
void ensureDefaultUsers(const std::string& fileName);

} // namespace atm

#endif
