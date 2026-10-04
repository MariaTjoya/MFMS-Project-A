#ifndef BUDGET_H
#define BUDGET_H

#define MAX_DEPARTMENT 50

typedef struct {
    char  department[50];
    double allocatedBudget;
    double expenditure;
    double remainingBudget;} Budget;

    void budgetMenu(void);
    void addBudget(Budget budget[],int *count);
    void displayBudgets(Budget budgets[], int count);
    void  calculateBudget(Budget budgets[], int count);
    void displayExceededBudgets(Budget budgets[], int count);
    extern Budget budgets[MAX_DEPARTMENT];
    extern int budgetCount;
    #endif
