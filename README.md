MUNICIPAL FINANCIAL
MANAGEMENT SYSTEM
PROJECT A — README & PROJECT DOCUMENTATION

Course	PAP521S – Programming in Practice
Project	Project A: Municipal Financial Management System
Group	Group 2
Repository	https://github.com/MariaTjoya/MFMS-Project-A

GROUP MEMBERS
Full name	Student number	Responsibility
Thomas David	226066916	Asset Management
Salmon Amakali	226090027	Reports module
Elifas Herman	226043347	Supplier Management
Maukuhongo Kazapua	226125467	Budget Management
Emilia	225036800	Employee Management
Maria Tjoya	225082470	Main menu, integration, testing, documentation and GitHub coordination
Lukas Amunkete	223066192	Test case preparation and results recording

 Table of Contents
1. Project Description
2. System Features
   2.1 Main Menu
   2.2 Employee Management
   2.3 Budget Management
   2.4 Supplier Management
   2.5 Asset Management
   2.6 Reports
3. Requirements
4. Compilation Instructions
5. How to Run the System
6. Program Structure
7. Group Members and Responsibilities
8. Testing and Screenshots
9. GitHub Repository and Collaboration
10. Known Limitations and Remaining Work
11. Final Submission Checklist

 1. Project Description
The Municipal Financial Management System (MFMS) is a C-based, menu-driven application developed to support municipal financial and administrative management. It brings employee, budget, supplier and asset management into one program and provides a Reports menu.
The application uses a modular structure. C source files (.c) contain function implementations, while header files (.h) contain declarations and shared definitions. The main menu connects the modules and allows users to navigate between them.
2. System Features
2.1 Main Menu
The main menu provides access to Employee Management, Budget Management, Supplier Management, Asset Management and Reports. Option 0 exits the program.
2.2 Employee Management
The Employee Management module supports employee operations such as adding, displaying and searching employee records, and calculating salary information. The Employee Report currently displays a message indicating that totals and salary statistics are not yet connected.
2.3 Budget Management
The Budget Management module supports budget-related operations. The Budget Report currently displays a message indicating that allocations, expenditure and balances are not yet connected to the report.
2.4 Supplier Management
Supplier records include supplier ID, name, email, telephone number and town/location. The module supports supplier record management. The Supplier Report displays a supplier count and reports when no suppliers have been registered in the current program session.
2.5 Asset Management
Asset records include asset ID, name, type, purchase value, department and condition. The module supports asset operations. The Asset Report displays the number of recorded assets, total asset value and asset details; when no assets have been recorded, it reports zero assets and a total value of N$0.00.
2.6 Reports
The Reports menu provides Employee, Budget, Supplier and Asset Report options. Based on the latest observed test output, the Supplier and Asset Reports display their current report information, while Employee and Budget Reports remain placeholders and need further integration.
3. Requirements
•	A Windows computer with GCC installed, for example through MinGW/Git Bash.
•	Visual Studio Code or another text editor.
•	The project source and header files listed in Section 6.
•	A terminal opened in the MFMS-Project-A directory.
4. Compilation Instructions
In Git Bash, open the project directory and run:
gcc main.c employees.c budget.c suppliers.c assets.c reports.c -o mfms.exe
If compilation succeeds, GCC creates mfms.exe in the project directory. Fix any compiler errors before running the application.
5. How to Run the System
In Git Bash, run:
./mfms.exe
In PowerShell, run:
.\mfms.exe
Enter the number for the required menu option. Use 0 to return from a submenu or exit from the main menu, depending on the menu shown.
6. Program Structure
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
The main source and header files are kept at the project root. Each module focuses on a particular management area, while main.c provides navigation and reports.c provides report-menu functions.
7. Group Members and Responsibilities
The table below lists the names, student numbers and module responsibilities recorded in the group's documentation. The seventh member's assigned task is a straightforward supporting responsibility: prepare test cases and record the observed results. The student should complete and verify this work before claiming it as finished.
Full name	Student number	Responsibility
Thomas David	226066916	Asset Management
Salmon Amakali	226090027	Reports module
Elifas Herman	226043347	Supplier Management
Maukuhongo Kazapua	226125467	Budget Management
Emilia	225036800	Employee Management
Maria Tjoya	225082470	Main menu, integration, testing, documentation and GitHub coordination
Lukas Amunkete	223066192	Test case preparation and results recording
Individual responsibility summary
•	Thomas David — Asset Management: development of the asset module.
•	Salmon Amakali — Reports: reports.c and reports.h and report-menu functionality.
•	Elifas Herman — Supplier Management: suppliers.c and suppliers.h, supplier records and supplier operations.
•	Maukuhongo Kazapua — Budget Management: budget.c and budget.h and budget operations.
•	Emilia — Employee Management: employee records, employee operations and salary-related functionality.
•	Maria Tjoya — Main menu, integration and coordination, testing, documentation and GitHub coordination.
•	Lukas Amunkete — Test case preparation and results recording: prepare a simple test-case table, record expected and actual outcomes, and identify any failures for follow-up.
8. Testing and Screenshots
The screenshots below are evidence from development sessions. They show menu navigation, report output, Git merge resolution and successful synchronization with GitHub. The report screenshots show the program with no supplier or asset records entered in that session; they do not prove that reports have been tested with populated sample data.
 
Figure 1. Terminal output during report-menu testing.
 
Figure 2. Development terminal output during Git operations.
 
Figure 3. Git merge commit, push, and clean working-tree status.
Suggested test-case record
Test	Expected result	Observed result	Status
Compile all modules with GCC	Executable is created without compiler errors	Successful compile shown during testing	Passed for that run
Open main menu and choose Reports	Reports menu is displayed	Reports menu displayed	Passed
Supplier Report with no suppliers	Shows zero suppliers and a no-records message	Output showed 0 suppliers	Passed for empty-data case
Asset Report with no assets	Shows zero assets and N$0.00 total value	Output showed 0 assets and N$0.00	Passed for empty-data case
Employee and Budget Reports	Report data/statistics are displayed	Placeholder messages remain	Further work needed
Before final submission, test each module with sample records and invalid inputs, capture fresh screenshots of those results, and update this table to match what was actually observed.
9. GitHub Repository and Collaboration
Repository: https://github.com/MariaTjoya/MFMS-Project-A
The repository stores the project source files and commit history. Group members should commit their own changes and use the agreed branch workflow. Before pushing, check git status. When a merge conflict occurs, resolve the affected files, save them, stage the resolved files, complete the merge commit and push.
Useful commands:
git status
git add assets.c assets.h
git commit -m "Merge remote main and resolve asset conflicts"
git push origin main
The screenshot evidence records a successful merge commit and push, followed by a clean working tree. The repository should still be checked online before submission.
10. Known Limitations and Remaining Work
•	Connect the Employee Report to employee records and the intended salary statistics.
•	Connect the Budget Report to budget records, allocations, expenditure and remaining balances.
•	Test Supplier and Asset Reports with actual sample records, not only empty-data cases.
•	Test invalid input and boundary cases in all modules.
•	Confirm that each group member's responsibility and contribution evidence accurately reflects work completed.
•	Recompile and run the program after the final merge.
