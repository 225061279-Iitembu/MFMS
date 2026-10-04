#include <stdio.h>
#include "budget.h"
#include "validation.h"

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

    getValidString("Enter Department: ",
                   budgets[budgetCount].department,
                   sizeof(budgets[budgetCount].department));

    budgets[budgetCount].allocatedBudget =
        getValidDouble("Enter Allocated Budget: ", 0.0);

    budgets[budgetCount].expenditure =
        getValidDouble("Enter Expenditure: ", 0.0);

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