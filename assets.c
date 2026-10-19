#include <stdio.h>
#include "assets.h"

#define MAX_ASSETS 100

typedef struct {
    int id;
    char name[100];
    char type[50];
    double purchaseValue;
    char department[100];
    char condition[50];
} Asset;

static Asset assets[MAX_ASSETS];
static int assetCount = 0;

void addAsset(void)
{
    Asset a;

    if (assetCount >= MAX_ASSETS) {
        printf("Asset storage is full.\n");
        return;
    }

    printf("Enter asset ID: ");
    if (scanf("%d", &a.id) != 1 || a.id <= 0) {
        printf("Invalid ID.\n");
        while (getchar() != '\n');
        return;
    }

    for (int i = 0; i < assetCount; i++) {
        if (assets[i].id == a.id) {
            printf("Asset ID already exists.\n");
            return;
        }
    }

    printf("Enter asset name: ");
    scanf(" %99[^\n]", a.name);

    printf("Enter asset type: ");
    scanf(" %49[^\n]", a.type);

    printf("Enter purchase value: ");
    if (scanf("%lf", &a.purchaseValue) != 1 ||
        a.purchaseValue < 0) {
        printf("Invalid purchase value.\n");
        while (getchar() != '\n');
        return;
    }

    printf("Enter department: ");
    scanf(" %99[^\n]", a.department);

    printf("Enter condition: ");
    scanf(" %49[^\n]", a.condition);

    assets[assetCount++] = a;
    printf("Asset added successfully.\n");
}

void displayAssets(void)
{
    if (assetCount == 0) {
        printf("No assets recorded.\n");
        return;
    }

    for (int i = 0; i < assetCount; i++) {
        printf("\nID: %d\nName: %s\nType: %s\n"
               "Purchase value: N$ %.2f\nDepartment: %s\n"
               "Condition: %s\n",
               assets[i].id, assets[i].name, assets[i].type,
               assets[i].purchaseValue, assets[i].department,
               assets[i].condition);
    }
}

void searchAsset(void)
{
    int id;

    printf("Enter asset ID to search: ");
    if (scanf("%d", &id) != 1) {
        printf("Invalid ID.\n");
        while (getchar() != '\n');
        return;
    }

    for (int i = 0; i < assetCount; i++) {
        if (assets[i].id == id) {
            printf("\nID: %d\nName: %s\nType: %s\n"
                   "Purchase value: N$ %.2f\nDepartment: %s\n"
                   "Condition: %s\n",
                   assets[i].id, assets[i].name, assets[i].type,
                   assets[i].purchaseValue, assets[i].department,
                   assets[i].condition);
            return;
        }
    }

    printf("Asset not found.\n");
}

void displayAssetReport(void)
{
    double totalValue = 0;

    printf("\n========== ASSET REPORT ==========\n");
    printf("Total assets: %d\n", assetCount);

    for (int i = 0; i < assetCount; i++) {
        totalValue += assets[i].purchaseValue;
    }

    printf("Total asset value: N$ %.2f\n", totalValue);
    printf("\nAsset details:\n");
    displayAssets();
}

void assetMenu(void)
{
    int choice;

    do {
        printf("\n--- Asset Management ---\n");
        printf("1. Add Asset\n");
        printf("2. Display Assets\n");
        printf("3. Search Asset\n");
        printf("0. Return to Main Menu\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid choice.\n");
            while (getchar() != '\n');
            choice = -1;
            continue;
        }

        switch (choice) {
            case 1: addAsset(); break;
            case 2: displayAssets(); break;
            case 3: searchAsset(); break;
            case 0: break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 0);
}