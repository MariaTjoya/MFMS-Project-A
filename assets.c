#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "assets.h"

static Asset assets[MAX_ASSETS];
static int assetCount = 0;


/* ---------------------------------------------------------
   Helper function
   --------------------------------------------------------- */

static void clearInputBuffer(void)
{
    int c;

    while ((c = getchar()) != '\n' && c != EOF)
    {
        /* Clear input buffer */
    }
}


/* ---------------------------------------------------------
   Load assets from file
   --------------------------------------------------------- */

void loadAssets(void)
{
    FILE *file;

    file = fopen("assets.dat", "rb");

    if (file == NULL)
    {
        assetCount = 0;
        return;
    }

    fread(&assetCount, sizeof(int), 1, file);

    if (assetCount > MAX_ASSETS)
    {
        assetCount = MAX_ASSETS;
    }

    fread(assets, sizeof(Asset), assetCount, file);

    fclose(file);
}


/* ---------------------------------------------------------
   Save assets to file
   --------------------------------------------------------- */

void saveAssets(void)
{
    FILE *file;

    file = fopen("assets.dat", "wb");

    if (file == NULL)
    {
        printf("\nError: Could not save asset data.\n");
        return;
    }

    fwrite(&assetCount, sizeof(int), 1, file);
    fwrite(assets, sizeof(Asset), assetCount, file);

    fclose(file);
}


/* ---------------------------------------------------------
   Generate next Asset ID
   --------------------------------------------------------- */

static int generateAssetID(void)
{
    int highestID = 0;
    int i;

    for (i = 0; i < assetCount; i++)
    {
        if (assets[i].id > highestID)
        {
            highestID = assets[i].id;
        }
    }

    return highestID + 1;
}


/* ---------------------------------------------------------
   Add Asset
   --------------------------------------------------------- */

void addAsset(void)
{
    Asset newAsset;

    if (assetCount >= MAX_ASSETS)
    {
        printf("\nAsset storage is full.\n");
        return;
    }

    newAsset.id = generateAssetID();

    printf("\n========================================\n");
    printf("           ADD NEW ASSET\n");
    printf("========================================\n");

    printf("Asset Name: ");
    fgets(newAsset.name, sizeof(newAsset.name), stdin);
    newAsset.name[strcspn(newAsset.name, "\n")] = '\0';

    printf("Category: ");
    fgets(newAsset.category, sizeof(newAsset.category), stdin);
    newAsset.category[strcspn(newAsset.category, "\n")] = '\0';

    printf("Location: ");
    fgets(newAsset.location, sizeof(newAsset.location), stdin);
    newAsset.location[strcspn(newAsset.location, "\n")] = '\0';

    printf("Purchase Date (DD/MM/YYYY): ");
    fgets(newAsset.purchaseDate, sizeof(newAsset.purchaseDate), stdin);
    newAsset.purchaseDate[strcspn(newAsset.purchaseDate, "\n")] = '\0';

    printf("Purchase Value: N$ ");
    scanf("%lf", &newAsset.purchaseValue);
    clearInputBuffer();

    printf("Status (Active/Disposed/Maintenance): ");
    fgets(newAsset.status, sizeof(newAsset.status), stdin);
    newAsset.status[strcspn(newAsset.status, "\n")] = '\0';

    assets[assetCount] = newAsset;
    assetCount++;

    saveAssets();

    printf("\nAsset added successfully!\n");
    printf("Asset ID: %d\n", newAsset.id);
}


/* ---------------------------------------------------------
   View All Assets
   --------------------------------------------------------- */

void viewAssets(void)
{
    int i;

    if (assetCount == 0)
    {
        printf("\nNo assets have been registered.\n");
        return;
    }

    printf("\n================================================================================\n");
    printf("                           ASSET REGISTER\n");
    printf("================================================================================\n");

    printf("%-5s %-20s %-15s %-15s %-15s %-12s\n",
           "ID",
           "Name",
           "Category",
           "Location",
           "Value",
           "Status");

    printf("--------------------------------------------------------------------------------\n");

    for (i = 0; i < assetCount; i++)
    {
        printf("%-5d %-20s %-15s %-15s N$ %-10.2f %-12s\n",
               assets[i].id,
               assets[i].name,
               assets[i].category,
               assets[i].location,
               assets[i].purchaseValue,
               assets[i].status);
    }

    printf("================================================================================\n");
}


/* ---------------------------------------------------------
   Search Asset
   --------------------------------------------------------- */

void searchAsset(void)
{
    int id;
    int i;
    int found = 0;

    printf("\nEnter Asset ID to search: ");
    scanf("%d", &id);
    clearInputBuffer();

    for (i = 0; i < assetCount; i++)
    {
        if (assets[i].id == id)
        {
            printf("\n========================================\n");
            printf("             ASSET DETAILS\n");
            printf("========================================\n");

            printf("Asset ID       : %d\n", assets[i].id);
            printf("Name           : %s\n", assets[i].name);
            printf("Category       : %s\n", assets[i].category);
            printf("Location       : %s\n", assets[i].location);
            printf("Purchase Date  : %s\n", assets[i].purchaseDate);
            printf("Purchase Value : N$ %.2f\n",
                   assets[i].purchaseValue);
            printf("Status         : %s\n", assets[i].status);

            printf("========================================\n");

            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("\nAsset with ID %d was not found.\n", id);
    }
}


/* ---------------------------------------------------------
   Update Asset
   --------------------------------------------------------- */

void updateAsset(void)
{
    int id;
    int i;
    int found = 0;

    printf("\nEnter Asset ID to update: ");
    scanf("%d", &id);
    clearInputBuffer();

    for (i = 0; i < assetCount; i++)
    {
        if (assets[i].id == id)
        {
            printf("\nUpdating Asset: %s\n", assets[i].name);

            printf("\nNew Asset Name: ");
            fgets(assets[i].name, sizeof(assets[i].name), stdin);
            assets[i].name[strcspn(assets[i].name, "\n")] = '\0';

            printf("New Category: ");
            fgets(assets[i].category,
                  sizeof(assets[i].category),
                  stdin);
            assets[i].category[strcspn(assets[i].category, "\n")] = '\0';

            printf("New Location: ");
            fgets(assets[i].location,
                  sizeof(assets[i].location),
                  stdin);
            assets[i].location[strcspn(assets[i].location, "\n")] = '\0';

            printf("New Purchase Date: ");
            fgets(assets[i].purchaseDate,
                  sizeof(assets[i].purchaseDate),
                  stdin);
            assets[i].purchaseDate[
                strcspn(assets[i].purchaseDate, "\n")
            ] = '\0';

            printf("New Purchase Value: N$ ");
            scanf("%lf", &assets[i].purchaseValue);
            clearInputBuffer();

            printf("New Status: ");
            fgets(assets[i].status,
                  sizeof(assets[i].status),
                  stdin);
            assets[i].status[strcspn(assets[i].status, "\n")] = '\0';

            saveAssets();

            printf("\nAsset updated successfully!\n");

            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("\nAsset with ID %d was not found.\n", id);
    }
}


/* ---------------------------------------------------------
   Delete Asset
   --------------------------------------------------------- */

void deleteAsset(void)
{
    int id;
    int i;
    int j;
    int found = 0;

    printf("\nEnter Asset ID to delete: ");
    scanf("%d", &id);
    clearInputBuffer();

    for (i = 0; i < assetCount; i++)
    {
        if (assets[i].id == id)
        {
            found = 1;

            for (j = i; j < assetCount - 1; j++)
            {
                assets[j] = assets[j + 1];
            }

            assetCount--;

            saveAssets();

            printf("\nAsset deleted successfully.\n");

            break;
        }
    }

    if (!found)
    {
        printf("\nAsset with ID %d was not found.\n", id);
    }
}


/* ---------------------------------------------------------
   Calculate Total Asset Value
   --------------------------------------------------------- */

void calculateTotalAssetValue(void)
{
    double total = 0.0;
    int i;

    for (i = 0; i < assetCount; i++)
    {
        total += assets[i].purchaseValue;
    }

    printf("\n========================================\n");
    printf("          ASSET VALUE REPORT\n");
    printf("========================================\n");

    printf("Number of Assets : %d\n", assetCount);
    printf("Total Asset Value: N$ %.2f\n", total);

    printf("========================================\n");
}


/* ---------------------------------------------------------
   Asset Management Menu
   --------------------------------------------------------- */

void assetManagementMenu(void)
{
    int choice;

    loadAssets();

    do
    {
        printf("\n");
        printf("========================================\n");
        printf("          ASSET MANAGEMENT\n");
        printf("========================================\n");
        printf("1. Add Asset\n");
        printf("2. View All Assets\n");
        printf("3. Search Asset\n");
        printf("4. Update Asset\n");
        printf("5. Delete Asset\n");
        printf("6. Calculate Total Asset Value\n");
        printf("0. Return to Main Menu\n");
        printf("========================================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearInputBuffer();

        switch (choice)
        {
            case 1:
                addAsset();
                break;

            case 2:
                viewAssets();
                break;

            case 3:
                searchAsset();
                break;

            case 4:
                updateAsset();
                break;

            case 5:
                deleteAsset();
                break;

            case 6:
                calculateTotalAssetValue();
                break;

            case 0:
                printf("\nReturning to Main Menu...\n");
                break;

            default:
                printf("\nInvalid choice. Please try again.\n");
        }

    } while (choice != 0);
}
