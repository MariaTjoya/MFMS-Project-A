#include <stdio.h>
#include "budget.h"

/* Add departmental budget */
void addBudget(Budget budgets[], int*count)
{
    if(*count >= MAX_DEPARTMENT)
    {
        printf("\nMaximum number of departments reached.\n");
        return;
    }
    printf("\nEnter department name: ");
    scanf(" %49[^\n]", budgets[*count].department);

    do
    {
        printf("Enter allocated budget (N$): ");
        scanf("%lf", &budgets[*count].allocatedBudget);

        if (budgets[*count].allocatedBudget < 0)
        {
            printf("Budget cannot be negative.\n");
        }
    } while (budgets[*count].allocatedBudget < 0);

    do
    {
        printf("Enter expenditure (N$): ");
        scanf("%lf",&budgets[*count].expenditure);
        if (budgets[*count].expenditure < 0)
        {
            printf("Expenditure cannot be negative.\n");
        }
    } while (budgets[*count].expenditure < 0);
    budgets[*count].remainingBudget = budgets[*count].allocatedBudget - budgets[*count].expenditure;
    (*count)++;
    printf("\nBudget added successfully!\n");
}

/* Display Budget information */
void displayBudgets(Budget budgets[], int count)
{
    int i;
    if (count == 0)
    {
        printf("\nNo budget information available.\n");
        return;
    }

    printf("\n============== Budget Information ==============\n");
    for (i = 0; i < count; i++)
    {
        printf("\nDepartment: %s\n", budgets[i].department);
        printf("Allocated Budget: N$%.2lf\n", budgets[i].allocatedBudget);
        printf("Expenditure: N$%.2lf\n", budgets[i].expenditure);
        printf("Remaining budget: N%.2lf\n", budgets[i].remainingBudget);

        if (budgets[i].expenditure <= budgets[i].allocatedBudget); 
        {
            printf("Status: within budget\n");
        }
        
        {
            printf("status: exceeded budget\n");
        }
    }
}
/* calculate remaining budget */
void calculateBudget(Budget budgets[], int count)
{
    int i;

    for (i = 0; i < count; i++)
    {
        budgets[i].remainingBudget = budgets[i].allocatedBudget - budgets[i].expenditure;
    }

    printf("\nBudget calculations completed.\n");
}
/* Display departnents that exceeded their budget */
void displayExceededBudgets(Budget budgets[], int count)
{
    int i;
    int found = 0;
    printf("\n===== DEPARTMENTS EXCEEDING BUDGET =====\n");
    for (i = 0; i < count; i++)
    {
        if (budgets[i].expenditure > budgets[i].allocatedBudget);
        {
            printf("\nDepartment: %s\n",budgets[i].department);
            printf("Allocated Budget: N$%.2f\n",budgets[i].allocatedBudget);
            printf("Expenditure: N$.2f\n",budgets[i].expenditure);
            printf("Amount Exceeded: N$.2f\n",budgets[i].expenditure - budgets[i].allocatedBudget);
            
            found = 1;
            
        }
    }
    if (found == 0)
    {
        printf("No departments have exceeeded their budget.\n");
    }
}


    