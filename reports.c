
#include <stdio.h>
#include "reports.h"
#include "employees.h"
#include "budget.h"
#include "suppliers.h"
#include "assets.h"

void employeeReport(void)
{
    printf("\n--- EMPLOYEE REPORT ---\n");
    printf("Employee report selected.\n");
    printf("Employee totals and salary statistics are not yet connected.\n");
}

void budgetReport(void)
{
    printf("\n--- BUDGET REPORT ---\n");
    printf("Budget report selected.\n");
    printf("Budget allocations, expenditure and balances are not yet connected.\n");
}

void supplierReport(Supplier suppliers[], int supplierCount)
{
    printf("\n--- SUPPLIER REPORT ---\n");
    displaySupplierReport(suppliers, supplierCount);
}

void assetReport(void)
{
    printf("\n--- ASSET REPORT ---\n");
    displayAssetReport();
}

void reportsMenu(Supplier suppliers[], int supplierCount)
{
    int choice;

    do {
        printf("\n========== REPORTS ==========\n");
        printf("1. Employee Report\n");
        printf("2. Budget Report\n");
        printf("3. Supplier Report\n");
        printf("4. Asset Report\n");
        printf("0. Back to Main Menu\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Enter a number.\n");

            while (getchar() != '\n');

            choice = -1;
            continue;
        }

        switch (choice) {
            case 1:
                employeeReport();
                break;

            case 2:
                budgetReport();
                break;

            case 3:
                supplierReport(suppliers, supplierCount);
                break;

            case 4:
                assetReport();
                break;

            case 0:
                printf("Returning to main menu...\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }

    } while (choice != 0);
}
