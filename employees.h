#ifndef EMPLOYEES_H
#define EMPLOYEES_H

#define MAX_EMPLOYEES 50
#define MAX_STRING_LEN 50

// Core employee module interface routines
void employeeMenu(void);
void addEmployee(void);
void displayEmployees(void);
void searchEmployee(void);
void calculateSalary(void);

// Reporting module interface data metrics (Student 5 integration hooks)
int getEmployeeCount(void);
double getAverageSalary(void);
double getHighestSalary(void);
double getLowestSalary(void);

#endif
