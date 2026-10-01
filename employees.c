#include <stdio.h>
#include <string.h>
#include "employees.h"

Employee employees[MAX_EMPLOYEES];
int employeeCount = 0;

void addEmployee(void)
{
    if (employeeCount >= MAX_EMPLOYEES)
    {
        printf("Employee list is full.\n");
        return;
    }

    printf("\n--- Add Employee ---\n");
    printf("Enter Employee ID: ");
    scanf("%d", &employees[employeeCount].employeeID);
	
    /* Check for duplicate employee ID */
    for (int i = 0; i < employeeCount; i++)
    {
        if (employees[i].employeeID == employees[employeeCount].employeeID)
        {
            printf("Employee ID already exists.\n");
            return;
        }
    }

    printf("Enter Name: ");
    scanf(" %[^\n]", employees[employeeCount].name);

    if (strlen(employees[employeeCount].name) == 0)
    {
        printf("Name cannot be empty.\n");
        return;
    }

    printf("Enter Department: ");
    scanf(" %[^\n]", employees[employeeCount].department);

    if (strlen(employees[employeeCount].department) == 0)
    {
        printf("Department cannot be empty.\n");
        return;
    }

    printf("Enter Basic Salary: ");
    scanf("%lf", &employees[employeeCount].basicSalary);

    while (employees[employeeCount].basicSalary < 0)
    {
        printf("Salary cannot be negative. Enter again: ");
        scanf("%lf", &employees[employeeCount].basicSalary);
    }

    printf("Enter Housing Allowance: ");
    scanf("%lf", &employees[employeeCount].housingAllowance);

    while (employees[employeeCount].housingAllowance < 0)
    {
        printf("Allowance cannot be negative. Enter again: ");
        scanf("%lf", &employees[employeeCount].housingAllowance);
    }

    printf("Enter Transport Allowance: ");
    scanf("%lf", &employees[employeeCount].transportAllowance);

    while (employees[employeeCount].transportAllowance < 0)
    {
        printf("Allowance cannot be negative. Enter again: ");
        scanf("%lf", &employees[employeeCount].transportAllowance);
    }

    employeeCount++;

    printf("Employee added successfully.\n");
}

void displayEmployees(void)
{
    if (employeeCount == 0)
    {
        printf("\nNo employees found.\n");
        return;
    }

    printf("\n--- Employee List ---\n");

    for (int i = 0; i < employeeCount; i++)
    {
        printf("\nEmployee ID: %d\n", employees[i].employeeID);
        printf("Name: %s\n", employees[i].name);
        printf("Department: %s\n", employees[i].department);
        printf("Basic Salary: %.2f\n", employees[i].basicSalary);
        printf("Housing Allowance: %.2f\n", employees[i].housingAllowance);
        printf("Transport Allowance: %.2f\n",
               employees[i].transportAllowance);
    }
}

void searchEmployee(void)
{
    int id;
    int found = 0;

    printf("\n--- Search Employee ---\n");
    printf("Enter Employee ID: ");
    scanf("%d", &id);

    for (int i = 0; i < employeeCount; i++)
    {
        if (employees[i].employeeID == id)
        {
            printf("\nEmployee found!\n");
            printf("Employee ID: %d\n", employees[i].employeeID);
            printf("Name: %s\n", employees[i].name);
            printf("Department: %s\n", employees[i].department);
            printf("Basic Salary: %.2f\n", employees[i].basicSalary);
            printf("Housing Allowance: %.2f\n",
                   employees[i].housingAllowance);
            printf("Transport Allowance: %.2f\n",
                   employees[i].transportAllowance);

            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("Employee not found.\n");
    }
}

void calculateSalary(void)
{
    int id;
    int found = 0;
    double totalSalary;

    printf("\n--- Salary Calculation ---\n");
    printf("Enter Employee ID: ");
    scanf("%d", &id);

    for (int i = 0; i < employeeCount; i++)
    {
        if (employees[i].employeeID == id)
        {
            totalSalary = employees[i].basicSalary
                        + employees[i].housingAllowance
                        + employees[i].transportAllowance;

            printf("\nEmployee: %s\n", employees[i].name);
            printf("Basic Salary: %.2f\n", employees[i].basicSalary);
            printf("Housing Allowance: %.2f\n",
                   employees[i].housingAllowance);
            printf("Transport Allowance: %.2f\n",
                   employees[i].transportAllowance);
            printf("Total Salary: %.2f\n", totalSalary);

            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("Employee not found.\n");
    }
}