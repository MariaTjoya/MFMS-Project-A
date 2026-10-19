#include <stdio.h>
#include <string.h>
#include "suppliers.h"

static void clearBuffer(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void addSupplier(Supplier suppliers[], int *count)
{
    if (*count >= MAX_SUPPLIERS) {
        printf("Supplier list is full.\n");
        return;
    }

    Supplier s;

    printf("\n===== ADD NEW SUPPLIER =====\n");
    printf("Enter Supplier ID: ");

    if (scanf("%d", &s.id) != 1 || s.id <= 0) {
        printf("Invalid ID.\n");
        clearBuffer();
        return;
    }
    clearBuffer();

    for (int i = 0; i < *count; i++) {
        if (suppliers[i].id == s.id) {
            printf("Supplier ID already exists.\n");
            return;
        }
    }

    printf("Enter Supplier Name: ");
    if (fgets(s.name, MAX_NAME, stdin) == NULL) return;
    s.name[strcspn(s.name, "\n")] = '\0';

    if (strlen(s.name) == 0) {
        printf("Name cannot be empty.\n");
        return;
    }

    printf("Enter Email: ");
    if (fgets(s.email, MAX_EMAIL, stdin) == NULL) return;
    s.email[strcspn(s.email, "\n")] = '\0';

    printf("Enter Telephone: ");
    if (fgets(s.phone, MAX_PHONE, stdin) == NULL) return;
    s.phone[strcspn(s.phone, "\n")] = '\0';

    printf("Enter Town/Location: ");
    if (fgets(s.town, MAX_TOWN, stdin) == NULL) return;
    s.town[strcspn(s.town, "\n")] = '\0';

    suppliers[*count] = s;
    (*count)++;

    printf("Supplier added successfully.\n");
}

void displaySuppliers(Supplier suppliers[], int count)
{
    if (count == 0) {
        printf("No suppliers registered yet.\n");
        return;
    }

    printf("\n================ SUPPLIER LIST ================\n");
    printf("%-8s %-20s %-25s %-15s %-15s\n",
           "ID", "Name", "Email", "Phone", "Town");

    for (int i = 0; i < count; i++) {
        printf("%-8d %-20s %-25s %-15s %-15s\n",
               suppliers[i].id,
               suppliers[i].name,
               suppliers[i].email,
               suppliers[i].phone,
               suppliers[i].town);
    }
}

void searchSupplier(Supplier suppliers[], int count)
{
    if (count == 0) {
        printf("No suppliers to search.\n");
        return;
    }

    int choice;
    printf("\nSearch by:\n1. Supplier ID\n2. Supplier Name\n");
    printf("Enter choice: ");

    if (scanf("%d", &choice) != 1) {
        printf("Invalid choice.\n");
        clearBuffer();
        return;
    }
    clearBuffer();

    int found = 0;

    if (choice == 1) {
        int id;
        printf("Enter Supplier ID: ");

        if (scanf("%d", &id) != 1) {
            printf("Invalid ID.\n");
            clearBuffer();
            return;
        }
        clearBuffer();

        for (int i = 0; i < count; i++) {
            if (suppliers[i].id == id) {
                printf("\nID: %d\nName: %s\nEmail: %s\n"
                       "Phone: %s\nTown: %s\n",
                       suppliers[i].id, suppliers[i].name,
                       suppliers[i].email, suppliers[i].phone,
                       suppliers[i].town);
                found = 1;
                break;
            }
        }
    } else if (choice == 2) {
        char name[MAX_NAME];

        printf("Enter Supplier Name: ");
        if (fgets(name, MAX_NAME, stdin) == NULL) return;
        name[strcspn(name, "\n")] = '\0';

        for (int i = 0; i < count; i++) {
            if (strstr(suppliers[i].name, name) != NULL) {
                printf("\nID: %d\nName: %s\nEmail: %s\n"
                       "Phone: %s\nTown: %s\n",
                       suppliers[i].id, suppliers[i].name,
                       suppliers[i].email, suppliers[i].phone,
                       suppliers[i].town);
                found = 1;
            }
        }
    } else {
        printf("Invalid choice.\n");
        return;
    }

    if (!found) {
        printf("No matching supplier found.\n");
    }
}

void displaySupplierReport(Supplier suppliers[], int count)
{
    printf("\n========== SUPPLIER REPORT ==========\n");
    printf("Total suppliers: %d\n", count);
    displaySuppliers(suppliers, count);
}

void supplierMenu(Supplier suppliers[], int *count)
{
    int choice;

    do {
        printf("\n===== SUPPLIER MANAGEMENT =====\n");
        printf("1. Add Supplier\n");
        printf("2. Display All Suppliers\n");
        printf("3. Search Supplier\n");
        printf("4. Back to Main Menu\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid choice.\n");
            clearBuffer();
            continue;
        }
        clearBuffer();

        switch (choice) {
            case 1: addSupplier(suppliers, count); break;
            case 2: displaySuppliers(suppliers, *count); break;
            case 3: searchSupplier(suppliers, *count); break;
            case 4: printf("Returning to main menu...\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 4);
}