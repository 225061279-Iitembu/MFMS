#ifndef EMPLOYEES_H
#define EMPLOYEES_H

#define MAX_EMPLOYEES 100

typedef struct
{
    int employeeID;
    char name[100];
    char department[50];
    double basicSalary;
    double housingAllowance;
    double transportAllowance;
} Employee;

void addEmployee(void);
void displayEmployees(void);
void searchEmployee(void);
void calculateSalary(void);

#endif