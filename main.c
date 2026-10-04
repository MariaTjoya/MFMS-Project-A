#include <stdio.h>

void displayMenu()
{
    printf("\n");
    printf("====================================\n");
    printf("      MUNICIPAL FINANCIAL\n");
    printf("      MANAGEMENT SYSTEM\n");
    printf("========== MAIN MENU ===============\n");
    printf("1. Employee Management\n");
    printf("2. Budget Management\n");
    printf("3. Supplier Management\n");
    printf("4. Asset Management\n");
    printf("5. Reports\n");
    printf("0. Exit\n");
    printf("====================================\n");
    printf("Enter your choice: ");
}

int main()
{
    int choice;

    do
    {
        displayMenu();

        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("\nEmployee Management selected.\n");
                break;

            case 2:
                printf("\nBudget Management selected.\n");
                break;

            case 3:
                printf("\nSupplier Management selected.\n");
                break;

            case 4:
                printf("\nAsset Management selected.\n");
                break;

            case 5:
                printf("\nReports selected.\n");
                break;

            case 0:
                printf("\nExiting the system...\n");
                break;

            default:
                printf("\nInvalid choice. Please try again.\n");
        }

    } while (choice != 0);

    return 0;
}