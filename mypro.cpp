#include <iostream>

int main() {
    int number;
    std::cin >> number;
    if (number % 2 == 0) {
        std::cout << "true";
    } else {
        std::cout << "false";
    }
    return 0;
}

