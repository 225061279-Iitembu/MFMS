#include <stdio.h>
#include "employees.h"
#include "budget.h"

void displayMenu(void)
{
    printf("\n====================================\n");
    printf(" MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
    printf("====================================\n");
    printf("1. Employee Management\n");
    printf("2. Budget Management\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
}

int main(void)
{
    int choice;

    do
    {
        displayMenu();
        scanf("%d", &choice);

        switch (choice)
        {
           case 1:
{
    int employeeChoice;

    do
    {
        printf("\n--- Employee Management ---\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Search Employee\n");
        printf("4. Calculate Salary\n");
        printf("5. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &employeeChoice);

        switch (employeeChoice)
        {
            case 1:
                addEmployee();
                break;

            case 2:
                displayEmployees();
                break;

            case 3:
                searchEmployee();
                break;

            case 4:
                calculateSalary();
                break;

            case 5:
                printf("Returning to main menu...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (employeeChoice != 5);

    break;
}
case 2:
{
    int budgetChoice;

    do
    {
        printf("\n--- Budget Management ---\n");
        printf("1. Add Department Budget\n");
        printf("2. Display Budgets\n");
        printf("3. Calculate Budget\n");
        printf("4. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &budgetChoice);

        switch (budgetChoice)
        {
            case 1:
                addBudget();
                break;

            case 2:
                displayBudgets();
                break;

            case 3:
                calculateBudget();
                break;

            case 4:
                printf("Returning to main menu...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (budgetChoice != 4);

    break;
}

            case 3:
                printf("\nExiting program...\n");
                break;

            default:
                printf("\nInvalid choice. Please try again.\n");
        }

    } while (choice != 3);

    return 0;
}