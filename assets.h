#ifndef ASSETS_H
#define ASSETS_H

#define MAX_ASSETS 100

typedef struct {
    int id;
    char name[100];
    char category[50];
    char location[100];
    char purchaseDate[20];
    double purchaseValue;
    char status[30];
} Asset;

/* Main Asset Management menu */
void assetManagementMenu(void);

/* Asset operations */
void addAsset(void);
void viewAssets(void);
void searchAsset(void);
void updateAsset(void);
void deleteAsset(void);

/* Reports */
void calculateTotalAssetValue(void);

/* File handling */
void loadAssets(void);
void saveAssets(void);

#endif
