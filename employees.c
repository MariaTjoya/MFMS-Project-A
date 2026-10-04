#include <stdio.h>
#include <string.h>
#include "employees.h"

// Database record parallel tracking arrays
char empIDs[MAX_EMPLOYEES][MAX_STRING_LEN];
char empNames[MAX_EMPLOYEES][MAX_STRING_LEN];
char empDepts[MAX_EMPLOYEES][MAX_STRING_LEN];
char empNotes[MAX_EMPLOYEES][MAX_STRING_LEN]; 
double basicSalaries[MAX_EMPLOYEES];
double housingAllowances[MAX_EMPLOYEES];
double transportAllowances[MAX_EMPLOYEES];
int employeeCount = 0; 

// Helper routine to strip trailing carriage newline artifacts safely
void readString(char *buffer, int maxLen) {
    fgets(buffer, maxLen, stdin);
    buffer[strcspn(buffer, "\r\n")] = 0; 
}

// Module management sub-menu routine
void employeeMenu(void) {
    int choice;
    do {
        printf("\n----------------------------------------\n");
        printf("          EMPLOYEE MANAGEMENT           \n");
        printf("----------------------------------------\n");
        printf("1. Add Employee\n");
        printf("2. Display All Employees\n");
        printf("3. Search Employee by ID\n");
        printf("4. Calculate Salary Information\n");
        printf("5. Back to Main Menu\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); 
            continue;
        }
        while (getchar() != '\n'); 
        switch (choice) {
            case 1: addEmployee(); break;
            case 2: displayEmployees(); break;
            case 3: searchEmployee(); break;
            case 4: calculateSalary(); break;
            case 5: printf("Returning to main menu...\n"); break;
            default: printf("Invalid choice! Try again.\n");
        }
    } while (choice != 5);
}

// 1. Database record insertion routine with post-test value tracking validation
void addEmployee(void) {
    if (employeeCount >= MAX_EMPLOYEES) {
        printf("\nError: Maximum employee storage capacity reached!\n");
        return;
    }
    printf("\nEnter Employee ID: ");
    readString(empIDs[employeeCount], MAX_STRING_LEN);
    printf("Enter Employee Name: ");
    readString(empNames[employeeCount], MAX_STRING_LEN);
    printf("Enter Department: ");
    readString(empDepts[employeeCount], MAX_STRING_LEN);
    printf("Enter Designation / Other Info: ");
    readString(empNotes[employeeCount], MAX_STRING_LEN);

    // Enforce bound verification logic for salary entries
    do {
        printf("Enter Basic Salary (N$): ");
        if (scanf("%lf", &basicSalaries[employeeCount]) != 1 || basicSalaries[employeeCount] < 0) {
            printf("Invalid Input! Salary cannot be negative. Try again.\n");
            while (getchar() != '\n');
            basicSalaries[employeeCount] = -1; 
        }
    } while (basicSalaries[employeeCount] < 0);

    // Enforce bound verification logic for housing allowances
    do {
        printf("Enter Housing Allowance (N$): ");
        if (scanf("%lf", &housingAllowances[employeeCount]) != 1 || housingAllowances[employeeCount] < 0) {
            printf("Invalid Input! Allowance cannot be negative. Try again.\n");
            while (getchar() != '\n');
            housingAllowances[employeeCount] = -1;
        }
    } while (housingAllowances[employeeCount] < 0);

    // Enforce bound verification logic for transport allowances
    do {
        printf("Enter Transport Allowance (N$): ");
        if (scanf("%lf", &transportAllowances[employeeCount]) != 1 || transportAllowances[employeeCount] < 0) {
            printf("Invalid Input! Allowance cannot be negative. Try again.\n");
            while (getchar() != '\n');
            transportAllowances[employeeCount] = -1;
        }
    } while (transportAllowances[employeeCount] < 0);
    while (getchar() != '\n'); 
    employeeCount++;
    printf("Employee added successfully!\n");
}

// 2. Tabular report printing display routine
void displayEmployees(void) {
    if (employeeCount == 0) {
        printf("\nNo records available. The system is empty.\n");
        return;
    }
    printf("\n%-10s %-20s %-15s %-15s %-12s\n", "ID", "Name", "Department", "Designation", "Basic Salary");
    printf("----------------------------------------------------------------------------\n");
    for (int i = 0; i < employeeCount; i++) {
        printf("%-10s %-20s %-15s %-15s N$%.2f\n", empIDs[i], empNames[i], empDepts[i], empNotes[i], basicSalaries[i]);
    }
}

// 3. Sequential index scan query using string array matching routines
void searchEmployee(void) {
    char searchID[MAX_STRING_LEN];
    int found = 0;
    if (employeeCount == 0) {
        printf("\nNo data records available to search.\n");
        return;
    }
    printf("\nEnter Employee ID to search: ");
    readString(searchID, MAX_STRING_LEN);
    for (int i = 0; i < employeeCount; i++) {
        if (strcmp(empIDs[i], searchID) == 0) { 
            printf("\n--- Match Found ---\n");
            printf("ID:                %s\n", empIDs[i]);
            printf("Name:              %s\n", empNames[i]);
            printf("Department:        %s\n", empDepts[i]);
            printf("Other Information: %s\n", empNotes[i]);
            printf("Basic Salary:      N$%.2f\n", basicSalaries[i]);
            printf("Housing Allowance: N$%.2f\n", housingAllowances[i]);
            printf("Transport Allowance:N$%.2f\n", transportAllowances[i]);
            found = 1;
            break;
        }
    }
    if (!found) printf("Employee with ID '%s' was not found.\n", searchID);
}

// 4. Financial aggregator calculations display routine
void calculateSalary(void) {
    char searchID[MAX_STRING_LEN];
    int found = 0;
    if (employeeCount == 0) {
        printf("\nNo data records available for calculation.\n");
        return;
    }
    printf("\nEnter Employee ID for gross salary calculation: ");
    readString(searchID, MAX_STRING_LEN);
    for (int i = 0; i < employeeCount; i++) {
        if (strcmp(empIDs[i], searchID) == 0) {
            double grossSalary = basicSalaries[i] + housingAllowances[i] + transportAllowances[i];
            printf("\n--- Financial Breakdown for %s ---\n", empNames[i]);
            printf("Basic Salary:         N$%.2f\n", basicSalaries[i]);
            printf("Housing Allowance:    N$%.2f\n", housingAllowances[i]);
            printf("Transport Allowance:  N$%.2f\n", transportAllowances[i]);
            printf("----------------------------------------\n");
            printf("Total Gross Earnings: N$%.2f\n", grossSalary);
            found = 1;
            break;
        }
    }
    if (!found) printf("Employee with ID '%s' was not found.\n", searchID);
}

// Shared statistical mapping modules for tracking reporting analytics
int getEmployeeCount(void) { return employeeCount; }
double getAverageSalary(void) {
    if (employeeCount == 0) return 0.0;
    double total = 0;
    for (int i = 0; i < employeeCount; i++) total += basicSalaries[i];
    return total / employeeCount;
}
double getHighestSalary(void) {
    if (employeeCount == 0) return 0.0;
    double highest = basicSalaries[0];
    for (int i = 1; i < employeeCount; i++) if (basicSalaries[i] > highest) highest = basicSalaries[i];
    return highest;
}
double getLowestSalary(void) {
    if (employeeCount == 0) return 0.0;
    double lowest = basicSalaries[0];
    for (int i = 1; i < employeeCount; i++) if (basicSalaries[i] < lowest) lowest = basicSalaries[i];
    return lowest;
}
