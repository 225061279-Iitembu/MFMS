#include <stdio.h>
#include "reports.h"
#include "employees.h"
#include "budget.h"
#include "assets.h"
#include "suppliers.h"
#include "validation.h"

/*
 * Access the data stored in the other modules.
 */
extern Employee employees[MAX_EMPLOYEES];
extern int employeeCount;

extern Budget budgets[MAX_BUDGETS];
extern int budgetCount;

extern int supplierCount;
extern double amountOwed[MAX_SUPPLIERS];

extern int assetCount;


/* ================= EMPLOYEE REPORT ================= */

void generateEmployeeReport(void)
{
    int i;
    double totalSalary = 0.0;
    double averageSalary;
    double highestSalary = 0.0;
    double lowestSalary = 0.0;
    double salary;

    printf("\n-----------------------------------------\n");
    printf("        EMPLOYEE MANAGEMENT REPORT\n");
    printf("-----------------------------------------\n");

    if (employeeCount == 0)
    {
        printf("No employees registered.\n");
        printf("-----------------------------------------\n");
        return;
    }

    for (i = 0; i < employeeCount; i++)
    {
        salary = employees[i].basicSalary
               + employees[i].housingAllowance
               + employees[i].transportAllowance;

        totalSalary += salary;

        if (i == 0)
        {
            highestSalary = salary;
            lowestSalary = salary;
        }
        else
        {
            if (salary > highestSalary)
            {
                highestSalary = salary;
            }

            if (salary < lowestSalary)
            {
                lowestSalary = salary;
            }
        }
    }

    averageSalary = totalSalary / employeeCount;

    printf("Total employees: %d\n", employeeCount);
    printf("Total salary cost: N$ %.2f\n", totalSalary);
    printf("Average salary: N$ %.2f\n", averageSalary);
    printf("Highest salary: N$ %.2f\n", highestSalary);
    printf("Lowest salary: N$ %.2f\n", lowestSalary);

    printf("-----------------------------------------\n");
}


/* ================= BUDGET REPORT ================= */

void generateBudgetReport(void)
{
    int i;
    int overBudget = 0;
    double totalAllocated = 0.0;
    double totalExpenditure = 0.0;
    double remainingBudget;

    printf("\n-----------------------------------------\n");
    printf("             BUDGET REPORT\n");
    printf("-----------------------------------------\n");

    if (budgetCount == 0)
    {
        printf("No budgets registered.\n");
        printf("-----------------------------------------\n");
        return;
    }

    for (i = 0; i < budgetCount; i++)
    {
        totalAllocated += budgets[i].allocatedBudget;
        totalExpenditure += budgets[i].expenditure;

        if (budgets[i].expenditure > budgets[i].allocatedBudget)
        {
            overBudget++;
        }
    }

    remainingBudget = totalAllocated - totalExpenditure;

    printf("Total departments: %d\n", budgetCount);
    printf("Total allocated budget: N$ %.2f\n", totalAllocated);
    printf("Total expenditure: N$ %.2f\n", totalExpenditure);
    printf("Remaining budget: N$ %.2f\n", remainingBudget);
    printf("Departments exceeding budget: %d\n", overBudget);

    if (overBudget > 0)
    {
        printf("\nDepartments over budget:\n");

        for (i = 0; i < budgetCount; i++)
        {
            if (budgets[i].expenditure > budgets[i].allocatedBudget)
            {
                printf("- %s\n", budgets[i].department);
            }
        }
    }

    printf("-----------------------------------------\n");
}


/* ================= SUPPLIER REPORT ================= */

void generateSupplierReport(void)
{
    int i;
    double totalOwed = 0.0;
    int outstanding = 0;
    int paid = 0;

    printf("\n-----------------------------------------\n");
    printf("            SUPPLIER REPORT\n");
    printf("-----------------------------------------\n");

    if (supplierCount == 0)
    {
        printf("No suppliers registered.\n");
        printf("-----------------------------------------\n");
        return;
    }

    for (i = 0; i < supplierCount; i++)
    {
        totalOwed += amountOwed[i];

        if (amountOwed[i] > 0)
        {
            outstanding++;
        }
        else
        {
            paid++;
        }
    }

    printf("Suppliers registered: %d\n", supplierCount);
    printf("Suppliers paid: %d\n", paid);
    printf("Suppliers with outstanding payments: %d\n", outstanding);
    printf("Total amount owed: N$ %.2f\n", totalOwed);

    printf("-----------------------------------------\n");
}


/* ================= ASSET REPORT ================= */

void generateAssetsReport(void)
{
    printf("\n-----------------------------------------\n");
    printf("              ASSET REPORT\n");
    printf("-----------------------------------------\n");

    printf("Registered municipal assets: %d\n", assetCount);

    if (assetCount == 0)
    {
        printf("No assets registered.\n");
    }

    printf("-----------------------------------------\n");
}


/* ================= FINANCIAL REPORT ================= */

void generateFinancialReport(void)
{
    int i;
    double totalAllocated = 0.0;
    double totalExpenditure = 0.0;
    double remainingBudget;
    double totalSalary = 0.0;
    double totalSupplierOwed = 0.0;

    printf("\n-----------------------------------------\n");
    printf("            FINANCIAL REPORT\n");
    printf("-----------------------------------------\n");

    for (i = 0; i < budgetCount; i++)
    {
        totalAllocated += budgets[i].allocatedBudget;
        totalExpenditure += budgets[i].expenditure;
    }

    remainingBudget = totalAllocated - totalExpenditure;

    for (i = 0; i < employeeCount; i++)
    {
        totalSalary += employees[i].basicSalary
                     + employees[i].housingAllowance
                     + employees[i].transportAllowance;
    }

    for (i = 0; i < supplierCount; i++)
    {
        totalSupplierOwed += amountOwed[i];
    }

    printf("Total allocated budget: N$ %.2f\n", totalAllocated);
    printf("Total expenditure: N$ %.2f\n", totalExpenditure);
    printf("Remaining budget: N$ %.2f\n", remainingBudget);
    printf("Total employee salary cost: N$ %.2f\n", totalSalary);
    printf("Total supplier amount owed: N$ %.2f\n", totalSupplierOwed);
    printf("Registered assets: %d\n", assetCount);

    if (remainingBudget >= 0)
    {
        printf("Overall budget status: WITHIN BUDGET\n");
    }
    else
    {
        printf("Overall budget status: OVER BUDGET\n");
    }

    printf("-----------------------------------------\n");
}


/* ================= ALL REPORTS ================= */

void generateAllReports(void)
{
    generateEmployeeReport();
    generateBudgetReport();
    generateSupplierReport();
    generateAssetsReport();
    generateFinancialReport();

    printf("\nAll reports displayed successfully.\n");
}


/* ================= REPORT MENU ================= */

void reportsMenu(void)
{
    int choice;

    do
    {
        printf("\n=========================================\n");
        printf("              REPORTS MENU\n");
        printf("=========================================\n");
        printf("1. Employee Report\n");
        printf("2. Budget Report\n");
        printf("3. Supplier Report\n");
        printf("4. Asset Report\n");
        printf("5. Financial Report\n");
        printf("6. Display All Reports\n");
        printf("7. Back to Main Menu\n");

        choice = getValidInt("Enter your choice: ", 1, 7);

        switch (choice)
        {
            case 1:
                generateEmployeeReport();
                break;

            case 2:
                generateBudgetReport();
                break;

            case 3:
                generateSupplierReport();
                break;

            case 4:
                generateAssetsReport();
                break;

            case 5:
                generateFinancialReport();
                break;

            case 6:
                generateAllReports();
                break;

            case 7:
                printf("Returning to main menu...\n");
                break;
        }

    } while (choice != 7);
}