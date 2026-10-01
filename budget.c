#include <stdio.h>
#include <string.h>
#include "budget.h"

Budget budgets[MAX_BUDGETS];
int budgetCount = 0;

void addBudget(void)
{
    if (budgetCount >= MAX_BUDGETS)
    {
        printf("Budget list is full.\n");
        return;
    }

    printf("\n--- Add Department Budget ---\n");

    printf("Enter Department: ");
    scanf(" %[^\n]", budgets[budgetCount].department);

    printf("Enter Allocated Budget: ");
    scanf("%lf", &budgets[budgetCount].allocatedBudget);

    while (budgets[budgetCount].allocatedBudget < 0)
    {
        printf("Budget cannot be negative. Enter again: ");
        scanf("%lf", &budgets[budgetCount].allocatedBudget);
    }

    printf("Enter Expenditure: ");
    scanf("%lf", &budgets[budgetCount].expenditure);

    while (budgets[budgetCount].expenditure < 0)
    {
        printf("Expenditure cannot be negative. Enter again: ");
        scanf("%lf", &budgets[budgetCount].expenditure);
    }

    budgetCount++;

    printf("Budget added successfully.\n");
}

void displayBudgets(void)
{
    if (budgetCount == 0)
    {
        printf("\nNo budgets found.\n");
        return;
    }

    printf("\n--- Department Budgets ---\n");

    for (int i = 0; i < budgetCount; i++)
    {
        double remaining = budgets[i].allocatedBudget
                         - budgets[i].expenditure;

        printf("\nDepartment: %s\n", budgets[i].department);
        printf("Allocated Budget: %.2f\n", budgets[i].allocatedBudget);
        printf("Expenditure: %.2f\n", budgets[i].expenditure);
        printf("Remaining Budget: %.2f\n", remaining);

        if (budgets[i].expenditure <= budgets[i].allocatedBudget)
        {
            printf("Status: WITHIN BUDGET\n");
        }
        else
        {
            printf("Status: OVER BUDGET\n");
        }
    }
}

void calculateBudget(void)
{
    int found = 0;
    double totalAllocated = 0;
    double totalExpenditure = 0;
    double totalRemaining;

    printf("\n--- Budget Calculation ---\n");

    for (int i = 0; i < budgetCount; i++)
    {
        totalAllocated += budgets[i].allocatedBudget;
        totalExpenditure += budgets[i].expenditure;
    }

    totalRemaining = totalAllocated - totalExpenditure;

    printf("Total Allocated Budget: %.2f\n", totalAllocated);
    printf("Total Expenditure: %.2f\n", totalExpenditure);
    printf("Total Remaining Budget: %.2f\n", totalRemaining);

    printf("\nDepartments Over Budget:\n");

    for (int i = 0; i < budgetCount; i++)
    {
        if (budgets[i].expenditure > budgets[i].allocatedBudget)
        {
            printf("- %s\n", budgets[i].department);
            found = 1;
        }
    }

    if (found == 0)
    {
        printf("No departments are over budget.\n");
    }
}



