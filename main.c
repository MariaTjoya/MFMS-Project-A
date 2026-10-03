#include <stdio.h>
#include "suppliers.h"

int main() {
    Supplier suppliers[MAX_SUPPLIERS];
    int supplierCount = 0;
    int choice;

    do {
        printf("\n============================================\n");
        printf("   MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
        printf("============================================\n");
        printf("1. Employee Management\n");
        printf("2. Budget Management\n");
        printf("3. Supplier Management\n");
        printf("4. Asset Management\n");
        printf("5. Reports\n");
        printf("0. Exit\n");
        printf("============================================\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            printf("Invalid input. Please enter a number.\n");
            continue;
        }

        int c;
        while ((c = getchar()) != '\n' && c != EOF);

        switch (choice) {
            case 1:
                printf("\n[Employee Management module coming soon...]\n");
                break;
            case 2:
                printf("\n[Budget Management module coming soon...]\n");
                break;
            case 3:
                supplierMenu(suppliers, &supplierCount);
                break;
            case 4:
                printf("\n[Asset Management module coming soon...]\n");
                break;
            case 5:
                printf("\n[Reports module coming soon...]\n");
                break;
            case 0:
                printf("\nThank you for using the system. Exiting...\n");
                break;
            default:
                printf("\nInvalid choice! Please select 0 - 5.\n");
        }

    } while (choice != 0);

    return 0;
}