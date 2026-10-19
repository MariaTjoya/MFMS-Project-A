# Municipal Financial Management System (MFMS)

## 1. Project Overview

The Municipal Financial Management System (MFMS) is a C-based application developed to assist with managing municipal financial and administrative activities. The system provides separate modules for employee management, budget management, supplier management, asset management, and reports.

## 2. Group Information

**Group Number:** Group 2

### Group Members and Responsibilities

| Group Member | Student Number | Responsibility |
|---|---|---|
| Thomas David | 226066916 | Asset Management |
| Salmon Amakali | 226090027 | Reports Module |
| Elifas Herman | 226043347 | Supplier Management |
| Maukuhongo Kazapua | 226125467 | Budget Management |
| Emilia Shakela | 225036800 | Employee Management |
| Maria Tjoya | 225082470 | Main Menu, Integration, Testing, Documentation and GitHub Coordination |
| Lukas Amunkete | 223066192 | Test-Case Preparation and Results Recording |

## 3. System Features

- Employee Management: Manages employee records.
- Budget Management: Handles municipal budget information.
- Supplier Management: Manages supplier records.
- Asset Management: Manages municipal assets and their details.
- Reports Module: Provides reports for the different management modules.
- Main Menu: Allows users to navigate between system modules.
- Input Validation: Helps prevent invalid menu selections and incorrect input.
- Module Integration: Connects the different modules through the main menu.

## 4. Project Structure

The project is organized into the following source and header files:

```text
MFMS-Project-A/
├── main.c
├── employees.c
├── employees.h
├── budget.c
├── budget.h
├── suppliers.c
├── suppliers.h
├── assets.c
├── assets.h
├── reports.c
├── reports.h
└── README.md
```

## 5. Compilation Instructions

Ensure that GCC is installed on your computer.

Open the project folder in the VS Code terminal or Git Bash and compile the program using:

```bash
gcc main.c employees.c budget.c suppliers.c assets.c reports.c -o mfms.exe
```

If compilation succeeds, the executable file `mfms.exe` will be created.

## 6. How to Run the System

In Git Bash, enter:

```bash
./mfms.exe
```

In the VS Code PowerShell terminal, enter:

```powershell
.\mfms.exe
```

The main menu provides the following options:

1. Employee Management
2. Budget Management
3. Supplier Management
4. Asset Management
5. Reports
0. Exit

Enter the number corresponding to the module you want to access and follow the displayed instructions.

## 7. Reports Module

The Reports module provides access to reports for:

- Employee Management
- Budget Management
- Supplier Management
- Asset Management

The information displayed depends on the records available and the functionality implemented in each report.

## 8. GitHub and Version Control

GitHub is used to store and manage the project's source code and coordinate group contributions.

The repository is available at:

https://github.com/MariaTjoya/MFMS-Project-A

Group members contribute to the project by working on their assigned modules, committing changes, and pushing their work to GitHub. Changes are integrated into the main branch to maintain a shared version of the project.

## 9. Testing

The system is tested by compiling and running the application, navigating through the main menu, accessing the different modules, checking input validation, and verifying the available reports.

Test cases and their results are recorded to document the system's behaviour and identify issues that require correction.

## 10. Conclusion

The MFMS project demonstrates the use of C programming, modular design, input validation, integration, testing, and GitHub version control to develop a municipal management application.
