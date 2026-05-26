#ifndef ATM_OPERATIONS_H
#define ATM_OPERATIONS_H

#include <string>
#include <vector>

#include "user_management.h"

namespace atm {

void commonMenu(std::vector<User>& users, const std::string& fileName, const std::string& username, const std::string& password);
void adminMenu(std::vector<User>& users, const std::string& fileName);
void deposit(User& user, double amount);
bool withdraw(User& user, double amount);

} // namespace atm

#endif
