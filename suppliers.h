#ifndef SUPPLIERS_H
#define SUPPLIERS_H

#define MAX_SUPPLIERS 50
#define MAX_NAME 50
#define MAX_EMAIL 50
#define MAX_PHONE 20
#define MAX_TOWN 40

typedef struct {
    int id;
    char name[MAX_NAME];
    char email[MAX_EMAIL];
    char phone[MAX_PHONE];
    char town[MAX_TOWN];
} Supplier;

void supplierMenu(Supplier suppliers[], int *count);
void addSupplier(Supplier suppliers[], int *count);
void displaySuppliers(Supplier suppliers[], int count);
void searchSupplier(Supplier suppliers[], int count);
void displaySupplierReport(Supplier suppliers[], int count);

#endif