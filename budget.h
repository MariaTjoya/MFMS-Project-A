#ifndef BUDGET_H
#define BUDGET_H

#define MAX_DEPARTMENT 50

typedef struct
{
    char department[50];
    double allocatedBudget;
    double expenditure;
    double remainingBudget;
} Budget;

/* Budget functions */
void addBudget(Budget budgets[], int *count);
void displayBudgets(Budget budgets[], int count);
void calculateBudget(Budget budgets[], int count);
void displayExceededBudgets(Budget budgets[], int count);
void budgetMenu(void);

/* Shared budget data */
extern Budget budgets[MAX_DEPARTMENT];
extern int budgetCount;

#endif