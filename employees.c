#include <stdio.h>
#include <string.h>
#include "employees.h"
#include "validation.h"

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

    employees[employeeCount].employeeID =
        getValidInt("Enter Employee ID: ", 1, 1000000);

    /* Check for duplicate employee ID */
    for (int i = 0; i < employeeCount; i++)
    {
        if (employees[i].employeeID == employees[employeeCount].employeeID)
        {
            printf("Employee ID already exists.\n");
            return;
        }
    }

    getValidString("Enter Name: ",
                   employees[employeeCount].name,
                   sizeof(employees[employeeCount].name));

    getValidString("Enter Department: ",
                   employees[employeeCount].department,
                   sizeof(employees[employeeCount].department));

    employees[employeeCount].basicSalary =
        getValidDouble("Enter Basic Salary: ", 0.0);

    employees[employeeCount].housingAllowance =
        getValidDouble("Enter Housing Allowance: ", 0.0);

    employees[employeeCount].transportAllowance =
        getValidDouble("Enter Transport Allowance: ", 0.0);

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

    id = getValidInt("Enter Employee ID: ", 1, 1000000);

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

    id = getValidInt("Enter Employee ID: ", 1, 1000000);

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
