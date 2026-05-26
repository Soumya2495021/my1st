#include "atm_operations.h"

#include <iomanip>
#include <iostream>
#include <limits>
#include <string>

namespace atm {

void deposit(User& user, double amount) {
    if (amount <= 0) {
        std::cout << "Deposit amount must be positive.\n";
        return;
    }

    user.balance += amount;
    std::cout << "Deposit successful. New balance: " << user.balance << "\n";
}

bool withdraw(User& user, double amount) {
    if (amount <= 0) {
        std::cout << "Withdraw amount must be positive.\n";
        return false;
    }

    if (amount > user.balance) {
        std::cout << "Insufficient balance.\n";
        return false;
    }

    user.balance -= amount;
    std::cout << "Withdrawal successful. New balance: " << user.balance << "\n";
    return true;
}

void commonMenu(std::vector<User>& users, const std::string& fileName, const std::string& username, const std::string& password) {
    int index = findUserIndex(users, username, password);
    if (index == -1) {
        std::cout << "Authentication failed.\n";
        return;
    }

    char choice = '0';
    while (choice != '4') {
        std::cout << "\n--- Common User Menu ---\n";
        std::cout << "1. Check balance\n";
        std::cout << "2. Deposit\n";
        std::cout << "3. Withdraw\n";
        std::cout << "4. Exit\n";
        std::cout << "Choose option: ";
        std::cin >> choice;

        if (choice == '1') {
            std::cout << std::fixed << std::setprecision(2);
            std::cout << "Balance: " << users[index].balance << "\n";
        } else if (choice == '2') {
            double amount = 0.0;
            std::cout << "Enter deposit amount: ";
            std::cin >> amount;
            deposit(users[index], amount);
            saveUsers(users, fileName);
        } else if (choice == '3') {
            double amount = 0.0;
            std::cout << "Enter withdraw amount: ";
            std::cin >> amount;
            if (withdraw(users[index], amount)) {
                saveUsers(users, fileName);
            }
        } else if (choice != '4') {
            std::cout << "Invalid option.\n";
        }
    }
}

void adminMenu(std::vector<User>& users, const std::string& fileName) {
    char choice = '0';
    while (choice != '4') {
        std::cout << "\n--- Admin Menu ---\n";
        std::cout << "1. View all users\n";
        std::cout << "2. Add user\n";
        std::cout << "3. Show total balance\n";
        std::cout << "4. Logout\n";
        std::cout << "Choose option: ";
        std::cin >> choice;

        if (choice == '1') {
            for (const User& user : users) {
                printUser(user);
                std::cout << "--------------------\n";
            }
        } else if (choice == '2') {
            User newUser;
            std::cout << "Username: ";
            std::cin >> newUser.username;
            std::cout << "Password: ";
            std::cin >> newUser.password;
            std::cout << "Role (common/admin): ";
            std::cin >> newUser.role;
            std::cout << "Initial balance: ";
            std::cin >> newUser.balance;

            if (newUser.role != "common" && newUser.role != "admin") {
                std::cout << "Role must be common or admin.\n";
                continue;
            }

            addUser(users, fileName, newUser);
            std::cout << "User added successfully.\n";
        } else if (choice == '3') {
            double total = 0.0;
            for (const User& user : users) {
                total += user.balance;
            }
            std::cout << std::fixed << std::setprecision(2);
            std::cout << "Total balance: " << total << "\n";
        } else if (choice != '4') {
            std::cout << "Invalid option.\n";
        }
    }
}

} // namespace atm
