#include <stdio.h>
#include <string.h>
#include "suppliers.h"

static void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void addSupplier(Supplier suppliers[], int *count) {
    if (*count >= MAX_SUPPLIERS) {
        printf("\nSupplier list is full. Cannot add more.\n");
        return;
    }

    Supplier s;
    int duplicate = 0;

    printf("\n===== ADD NEW SUPPLIER =====\n");

    printf("Enter Supplier ID: ");
    while (scanf("%d", &s.id) != 1 || s.id <= 0) {
        printf("Invalid ID. Enter a positive number: ");
        clearBuffer();
    }
    clearBuffer();

    for (int i = 0; i < *count; i++) {
        if (suppliers[i].id == s.id) {
            duplicate = 1;
            break;
        }
    }
    if (duplicate) {
        printf("Supplier ID already exists. Add cancelled.\n");
        return;
    }

    printf("Enter Supplier Name: ");
    fgets(s.name, MAX_NAME, stdin);
    s.name[strcspn(s.name, "\n")] = '\0';

    if (strlen(s.name) == 0) {
        printf("Name cannot be empty. Add cancelled.\n");
        return;
    }

    printf("Enter Email: ");
    fgets(s.email, MAX_EMAIL, stdin);
    s.email[strcspn(s.email, "\n")] = '\0';

    printf("Enter Telephone: ");
    fgets(s.phone, MAX_PHONE, stdin);
    s.phone[strcspn(s.phone, "\n")] = '\0';

    printf("Enter Town/Location: ");
    fgets(s.town, MAX_TOWN, stdin);
    s.town[strcspn(s.town, "\n")] = '\0';

    suppliers[*count] = s;
    (*count)++;

    printf("\nSupplier added successfully!\n");
}

void displaySuppliers(Supplier suppliers[], int count) {
    if (count == 0) {
        printf("\nNo suppliers registered yet.\n");
        return;
    }

    printf("\n==================== SUPPLIER LIST ====================\n");
    printf("%-8s %-20s %-25s %-15s %-15s\n", "ID", "Name", "Email", "Phone", "Town");
    printf("---------------------------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%-8d %-20s %-25s %-15s %-15s\n",
               suppliers[i].id,
               suppliers[i].name,
               suppliers[i].email,
               suppliers[i].phone,
               suppliers[i].town);
    }
    printf("===============================================================\n");
}

void searchSupplier(Supplier suppliers[], int count) {
    if (count == 0) {
        printf("\nNo suppliers to search.\n");
        return;
    }

    int choice;
    printf("\nSearch by:\n");
    printf("1. Supplier ID\n");
    printf("2. Supplier Name\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    clearBuffer();

    int found = 0;

    if (choice == 1) {
        int id;
        printf("Enter Supplier ID: ");
        scanf("%d", &id);
        clearBuffer();

        for (int i = 0; i < count; i++) {
            if (suppliers[i].id == id) {
                printf("\n--- Supplier Found ---\n");
                printf("ID      : %d\n", suppliers[i].id);
                printf("Name    : %s\n", suppliers[i].name);
                printf("Email   : %s\n", suppliers[i].email);
                printf("Phone   : %s\n", suppliers[i].phone);
                printf("Town    : %s\n", suppliers[i].town);
                found = 1;
                break;
            }
        }
    }
    else if (choice == 2) {
        char name[MAX_NAME];
        printf("Enter Supplier Name (or part of name): ");
        fgets(name, MAX_NAME, stdin);
        name[strcspn(name, "\n")] = '\0';

        for (int i = 0; i < count; i++) {
            if (strstr(suppliers[i].name, name) != NULL) {
                printf("\n--- Supplier Found ---\n");
                printf("ID      : %d\n", suppliers[i].id);
                printf("Name    : %s\n", suppliers[i].name);
                printf("Email   : %s\n", suppliers[i].email);
                printf("Phone   : %s\n", suppliers[i].phone);
                printf("Town    : %s\n", suppliers[i].town);
                found = 1;
            }
        }
    }
    else {
        printf("Invalid choice.\n");
        return;
    }

    if (!found) {
        printf("\nNo matching supplier found.\n");
    }
}

void supplierMenu(Supplier suppliers[], int *count) {
    int choice;

    do {
        printf("\n===== SUPPLIER MANAGEMENT =====\n");
        printf("1. Add Supplier\n");
        printf("2. Display All Suppliers\n");
        printf("3. Search Supplier\n");
        printf("4. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearBuffer();

        switch (choice) {
            case 1:
                addSupplier(suppliers, count);
                break;
            case 2:
                displaySuppliers(suppliers, *count);
                break;
            case 3:
                searchSupplier(suppliers, *count);
                break;
            case 4:
                printf("Returning to main menu...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);
}