
#include <stdio.h>
#include "employees.h"
#include "budget.h"
#include "suppliers.h"
#include "assets.h"
#include "reports.h"

int main(void)
{
    int choice;

    Supplier suppliers[MAX_SUPPLIERS] = {0};
    int supplierCount = 0;

    do {
        printf("\n====================================\n");
        printf(" MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
        printf("============= MAIN MENU =============\n");
        printf("1. Employee Management\n");
        printf("2. Budget Management\n");
        printf("3. Supplier Management\n");
        printf("4. Asset Management\n");
        printf("5. Reports\n");
        printf("0. Exit\n");
        printf("====================================\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Enter a number.\n");

            while (getchar() != '\n');

            choice = -1;
            continue;
        }

        switch (choice) {
            case 1:
                employeeMenu();
                break;

            case 2:
                budgetMenu();
                break;

            case 3:
                supplierMenu(suppliers, &supplierCount);
                break;

            case 4:
                assetMenu();
                break;

            case 5:
                reportsMenu(suppliers, supplierCount);
                break;

            case 0:
                printf("Exiting MFMS. Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }

    } while (choice != 0);

    return 0;
}
