#include <stdio.h>
#include "budget.h"

Budget budgets[MAX_DEPARTMENT];
int budgetCount = 0;

/* Add departmental budget */
void addBudget(Budget budgets[], int *count)
{
    if (*count >= MAX_DEPARTMENT)
    {
        printf("\nMaximum number of departments reached.\n");
        return;
    }

    printf("\nEnter department name: ");
    scanf(" %49[^\n]", budgets[*count].department);

    do
    {
        printf("Enter allocated budget (N$): ");
        if (scanf("%lf", &budgets[*count].allocatedBudget) != 1)
        {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n');
            budgets[*count].allocatedBudget = -1;
        }

        if (budgets[*count].allocatedBudget < 0)
        {
            printf("Budget cannot be negative.\n");
        }

    } while (budgets[*count].allocatedBudget < 0);

    do
    {
        printf("Enter expenditure (N$): ");

        if (scanf("%lf", &budgets[*count].expenditure) != 1)
        {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n');
            budgets[*count].expenditure = -1;
        }

        if (budgets[*count].expenditure < 0)
        {
            printf("Expenditure cannot be negative.\n");
        }

    } while (budgets[*count].expenditure < 0);

    budgets[*count].remainingBudget =
        budgets[*count].allocatedBudget - budgets[*count].expenditure;

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
        printf("Allocated Budget: N$%.2f\n", budgets[i].allocatedBudget);
        printf("Expenditure: N$%.2f\n", budgets[i].expenditure);
        printf("Remaining Budget: N$%.2f\n", budgets[i].remainingBudget);

        if (budgets[i].expenditure <= budgets[i].allocatedBudget)
        {
            printf("Status: Within budget\n");
        }
        else
        {
            printf("Status: Exceeded budget\n");
        }
    }
}

/* Calculate remaining budget */
void calculateBudget(Budget budgets[], int count)
{
    int i;

    for (i = 0; i < count; i++)
    {
        budgets[i].remainingBudget =
            budgets[i].allocatedBudget - budgets[i].expenditure;
    }

    printf("\nBudget calculations completed.\n");
}

/* Display departments that exceeded their budget */
void displayExceededBudgets(Budget budgets[], int count)
{
    int i;
    int found = 0;

    printf("\n===== DEPARTMENTS EXCEEDING BUDGET =====\n");

    for (i = 0; i < count; i++)
    {
        if (budgets[i].expenditure > budgets[i].allocatedBudget)
        {
            printf("\nDepartment: %s\n", budgets[i].department);
            printf("Allocated Budget: N$%.2f\n",
                   budgets[i].allocatedBudget);
            printf("Expenditure: N$%.2f\n",
                   budgets[i].expenditure);
            printf("Amount Exceeded: N$%.2f\n",
                   budgets[i].expenditure -
                   budgets[i].allocatedBudget);

            found = 1;
        }
    }

    if (found == 0)
    {
        printf("No departments have exceeded their budget.\n");
    }
}

/* Budget Management Menu */
void budgetMenu(void)
{
    int choice;

    do
    {
        printf("\n====================================\n");
        printf("        BUDGET MANAGEMENT\n");
        printf("====================================\n");
        printf("1. Add Budget\n");
        printf("2. Display Budgets\n");
        printf("3. Calculate Budget\n");
        printf("4. Display Exceeded Budgets\n");
        printf("5. Back to Main Menu\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }

        while (getchar() != '\n');

        switch (choice)
        {
            case 1:
                addBudget(budgets, &budgetCount);
                break;

            case 2:
                displayBudgets(budgets, budgetCount);
                break;

            case 3:
                calculateBudget(budgets, budgetCount);
                break;

            case 4:
                displayExceededBudgets(budgets, budgetCount);
                break;

            case 5:
                printf("Returning to main menu...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 5);
}