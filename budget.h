#ifndef BUDGET_H
#define BUDGET_H

#define MAX_BUDGETS 50

typedef struct
{
    char department[50];
    double allocatedBudget;
    double expenditure;
} Budget;

void addBudget(void);
void displayBudgets(void);
void calculateBudget(void);

#endif