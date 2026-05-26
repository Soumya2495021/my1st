# my1st

## ATM Simulator Mini Project

This repository contains a simple procedure-oriented C++ ATM simulator implemented using multiple files and namespace-based organization.

### Features
- Login for two predefined user types:
  - `common`
  - `admin`
- File handling using `users.txt` to store user data
- Common user actions:
  - Check balance
  - Deposit money
  - Withdraw money
- Admin actions:
  - View all users
  - Add a new user
  - Show total balance

### Project Structure
- `atm_simulator/main.cpp` - application entry point
- `atm_simulator/user_management.h` / `.cpp` - user structure and file operations
- `atm_simulator/atm_operations.h` / `.cpp` - ATM actions and menus
- `atm_simulator/users.txt` - stored user records

### Build and Run
From the `atm_simulator` folder, compile with:

```bash
g++ main.cpp user_management.cpp atm_operations.cpp -o atm_simulator
```

Run the program:

```bash
./atm_simulator
```

### Default Users
- `admin` / `admin123`
- `common` / `common123`