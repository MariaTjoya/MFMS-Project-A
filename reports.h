
#ifndef REPORTS_H
#define REPORTS_H

#include "suppliers.h"

void reportsMenu(Supplier suppliers[], int supplierCount);
void employeeReport(void);
void budgetReport(void);
void supplierReport(Supplier suppliers[], int supplierCount);
void assetReport(void);

#endif
