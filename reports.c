#include <stdio.h>
#include "reports.h"
#include "employees.h"
#include "budget.h"
void reportsMenu(void)
{
    int choice;

    do
    {
        printf("\n====================================\n");
        printf("             REPORTS\n");
        printf("====================================\n");
        printf("1. Employee Report\n");
        printf("2. Budget Report\n");
        printf("3.Supplier Report\n");
        printf("4. Back to Main Menu\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input. Please enter a number.\n");

            while (getchar() != '\n');

            continue;
        }

        while (getchar() != '\n');

        switch (choice)
        {
            case 1:
                employeeReport();
                break;

            case 2:
                budgetReport();
                break;
            case 3:
                supplierReport();

            case 4:
                printf("Returning to main menu...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 4);
}


void employeeReport(void)
{
    printf("\n====================================\n");
    printf("          EMPLOYEE REPORT\n");
    printf("====================================\n");

    if (getEmployeeCount() == 0)
    {
        printf("No employee records available.\n");
        return;
    }

    printf("Total Employees: %d\n", getEmployeeCount());
    printf("Average Basic Salary: N$%.2f\n", getAverageSalary());
    printf("Highest Basic Salary: N$%.2f\n", getHighestSalary());
    printf("Lowest Basic Salary: N$%.2f\n", getLowestSalary());

    printf("====================================\n");
}


void budgetReport(void)
{
    double totalAllocated = 0.0;
    double totalExpenditure = 0.0;
    double totalRemaining = 0.0;
    int overBudgetCount = 0;

    printf("\n====================================\n");
    printf("            BUDGET REPORT\n");
    printf("====================================\n");

    if (budgetCount == 0)
    {
        printf("No budget records available.\n");
        return;
    }

    for (int i = 0; i < budgetCount; i++)
    {
        totalAllocated += budgets[i].allocatedBudget;
        totalExpenditure += budgets[i].expenditure;
        totalRemaining += budgets[i].remainingBudget;

        if (budgets[i].expenditure > budgets[i].allocatedBudget)
        {
            overBudgetCount++;
        }
    }

    printf("Total Allocated Budget: N$%.2f\n", totalAllocated);
    printf("Total Expenditure:      N$%.2f\n", totalExpenditure);
    printf("Total Remaining Budget: N$%.2f\n", totalRemaining);

    printf("\nDepartments Over Budget: %d\n", overBudgetCount);

    if (overBudgetCount > 0)
    {
        printf("\n--- Departments Exceeding Budget ---\n");

        for (int i = 0; i < budgetCount; i++)
        {
            if (budgets[i].expenditure > budgets[i].allocatedBudget)
            {
                printf("Department: %s\n", budgets[i].department);
                printf("Allocated: N$%.2f\n", budgets[i].allocatedBudget);
                printf("Expenditure: N$%.2f\n", budgets[i].expenditure);
                printf("Amount Exceeded: N$%.2f\n\n",
                       budgets[i].expenditure - budgets[i].allocatedBudget);
            }
        }
    }
    else
    {
        printf("No departments have exceeded their budget.\n");
    }

    printf("====================================\n");
}
#include <stdio.h>
#include "reports.h"
#include "employees.h"
#include "budget.h"
#include "suppliers.h"
void supplierReport(void)
{
    printf("\n====================================\n");
    printf("          SUPPLIER REPORT\n");
    printf("====================================\n");

    if (supplierCount == 0)
    {
        printf("No supplier records available.\n");
        return;
    }

    printf("Total Suppliers: %d\n", supplierCount);

    printf("\n----------- SUPPLIER INFORMATION -----------\n");

    for (int i = 0; i < supplierCount; i++)
    {
        printf("\nSupplier %d\n", i + 1);
        printf("------------------------------------\n");
        printf("Supplier ID: %s\n", suppliers[i].supplierID);
        printf("Name:        %s\n", suppliers[i].supplierName);
        printf("Email:       %s\n", suppliers[i].email);
        printf("Telephone:   %s\n", suppliers[i].telephone);
        printf("Town:        %s\n", suppliers[i].town);
    }

    printf("====================================\n");
}