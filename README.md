# Municipal Financial Management System (MFMS)

## 1. Project Overview

The Municipal Financial Management System (MFMS) is a menu-driven application developed in C to support municipal administrative and financial management. It brings employee, budget, supplier, asset and reporting functions into one program.

## 2. Project Objectives

- Provide a main menu for navigating the system.
- Organise the system into separate modules.
- Support employee, budget, supplier and asset management.
- Provide reports for the available management modules.
- Practise modular programming, testing, debugging and GitHub collaboration.

## 3. System Features

### Employee Management
Provides employee-related operations, including employee records and salary-related functions.

### Budget Management
Provides budget-related operations for managing municipal financial information.

### Supplier Management
Supports supplier records containing supplier ID, name, email, telephone number and town or location.

### Asset Management
Supports asset records containing asset ID, name, type, purchase value, department and condition.

### Reports
Provides a submenu for Employee, Budget, Supplier and Asset Reports. Some report functions still require further integration.

## 4. Project Structure

- `main.c` — main menu and application entry point
- `employees.c` and `employees.h` — employee management
- `budget.c` and `budget.h` — budget management
- `suppliers.c` and `suppliers.h` — supplier management
- `assets.c` and `assets.h` — asset management
- `reports.c` and `reports.h` — reporting menu and report functions

## 5. Technologies Used

- C programming language
- GCC compiler
- Visual Studio Code
- Git and GitHub
- Git Bash

## 6. Compilation and Execution

Open Git Bash in the project folder and compile the application:

```bash
gcc main.c employees.c budget.c suppliers.c assets.c reports.c -o mfms.exe
```

Run the application:

```bash
./mfms.exe
```

## 7. Testing

The application has been compiled and run to test menu navigation and report outputs. Supplier and Asset Reports have been checked with no records registered. Further testing with populated records is recommended. Employee and Budget Reports also require additional integration.

## 8. Team Collaboration

The project was developed collaboratively using Git and GitHub. Source files were committed to the repository, and merge conflicts in the asset files were resolved before the updated `main` branch was pushed.

## 9. Repository

[MFMS-Project-A on GitHub](https://github.com/MariaTjoya/MFMS-Project-A)
