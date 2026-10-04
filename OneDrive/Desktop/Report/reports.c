#include <stdio.h>
#include "reports.h"
#include "employees.h"
#include "budget.h"
#include "assets.h"

 void 
assetReport(void)
{
printf("\n================================
====\n");
printf(" ASSET REPORT\n");
printf("==================================
==\n");
if (assetCount == 0)
{
printf("No asset records available.\n");
return;
}
double totalAssetValue = 0.0;
printf("Total Assets: %d\n", assetCount);
printf("\n----------- ASSET INFORMATION 
-----------\n");
for (int i = 0; i < assetCount; i++)
{
printf("\nAsset %d\n", i + 1);
printf("------------------------------------\n");
printf("Asset ID: %s\n", assets[i].assetID);
printf("Asset Name: %s\n", assets[i].assetName);
printf("Asset Type: %s\n", assets[i].assetType);
printf("Purchase Value: N$`%.2f\n", 
assets[i].purchaseValue);
printf("Department: %s\n", assets[i].department);
printf("Condition: %s\n", assets[i].condition);
totalAssetValue += assets[i].purchaseValue;
}
printf("\nTotal Asset Value: N`$%.2f\n", 
totalAssetValue);
printf("==================================
==\n");
}
while(choice !=5);