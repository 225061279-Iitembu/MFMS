#include <stdio.h>
#include <string.h>
#include "suppliers.h"
#include "validation.h"

int supplierID[MAX_SUPPLIERS];

char supplierName[MAX_SUPPLIERS][100];
char supplierEmail[MAX_SUPPLIERS][100];
char supplierContactNumber[MAX_SUPPLIERS][30];
char supplierLocation[MAX_SUPPLIERS][50];
char supplierCategory[MAX_SUPPLIERS][50];

double amountOwed[MAX_SUPPLIERS];

int supplierCount = 0;

void supplierMenu(void)
{
    int choice;

    do
    {
        printf("\n--- SUPPLIER MANAGEMENT ---\n");
        printf("1. Add Supplier\n");
        printf("2. Display Suppliers\n");
        printf("3. Search Supplier\n");
        printf("4. Compare Suppliers\n");
        printf("5. Return to Main Menu\n");

        choice = getValidInt("Enter your choice: ", 1, 5);

        switch (choice)
        {
            case 1:
                addSupplier();
                break;

            case 2:
                displaySuppliers();
                break;

            case 3:
                searchSupplier();
                break;

            case 4:
                compareSuppliers();
                break;

            case 5:
                break;
        }

    } while (choice != 5);
}

void addSupplier(void)
{
    int i;
    int duplicate;

    if (supplierCount >= MAX_SUPPLIERS)
    {
        printf("Supplier storage is full.\n");
        return;
    }

    /* Supplier ID */

    do
    {
        duplicate = 0;

        supplierID[supplierCount] =
            getValidInt("\nEnter Supplier ID: ", 1000, 999999999);


        /* Check for duplicate Supplier ID */

        for (i = 0; i < supplierCount; i++)
        {
            if (supplierID[i] == supplierID[supplierCount])
            {
                printf("Supplier ID already exists. Enter another ID.\n");
                duplicate = 1;
                break;
            }
        }

    } while (duplicate == 1);

    /* Supplier Name */
    getValidString(
        "Enter Supplier Name: ",
        supplierName[supplierCount],
        sizeof(supplierName[supplierCount])
    );

    /* Supplier Email */
    do
    {
        getValidString(
            "Enter Email: ",
            supplierEmail[supplierCount],
            sizeof(supplierEmail[supplierCount])
        );

        if (!isValidEmail(supplierEmail[supplierCount]))
        {
            printf("Invalid email. Enter a valid email address.\n");
        }

    } while (!isValidEmail(supplierEmail[supplierCount]));

    /* Supplier Contact Number */
    do
    {
        getValidString(
            "Enter Contact Number: ",
            supplierContactNumber[supplierCount],
            sizeof(supplierContactNumber[supplierCount])
        );

        if (!isValidPhone(supplierContactNumber[supplierCount]))
        {
            printf("Invalid contact number. Enter again.\n");
        }

    } while (!isValidPhone(supplierContactNumber[supplierCount]));

    /* Supplier Location */
    getValidString(
        "Enter Location: ",
        supplierLocation[supplierCount],
        sizeof(supplierLocation[supplierCount])
    );

    /* Supplier Category */
    getValidString(
        "Enter Supplier Category: ",
        supplierCategory[supplierCount],
        sizeof(supplierCategory[supplierCount])
    );

    /* The Amount Owed  */
    amountOwed[supplierCount] =
        getValidDouble("Enter Amount Owed: N$", 0.00);

    supplierCount++;

    printf("Supplier added successfully.\n");
}

void displaySuppliers(void)
{
    int i;

    if (supplierCount == 0)
    {
        printf("\nNo suppliers registered.\n");
        return;
    }

    printf("\n--- SUPPLIER LIST ---\n");

    for (i = 0; i < supplierCount; i++)
    {
        printf("\nSupplier ID: %d\n", supplierID[i]);
        printf("Supplier Name: %s\n", supplierName[i]);
        printf("Email: %s\n", supplierEmail[i]);
        printf("Contact Number: %s\n", supplierContactNumber[i]);
        printf("Location: %s\n", supplierLocation[i]);
        printf("Supplier Category: %s\n", supplierCategory[i]);
        printf("Amount Owed: N$%.2f\n", amountOwed[i]);


        /* Payment Status */
        if (amountOwed[i] == 0)
        {
            printf("Payment Status: PAID\n");
        }
        else
        {
            printf("Payment Status: OUTSTANDING\n");
        }
    }
}

void searchSupplier(void)
{
    char name[100];
    int found = 0;
    int i;

    if (supplierCount == 0)
    {
        printf("\nNo suppliers registered.\n");
        return;
    }


    getValidString(
        "\nEnter Supplier Name to search: ",
        name,
        sizeof(name)
    );

    for (i = 0; i < supplierCount; i++)
    {
        if (strcmp(supplierName[i], name) == 0)
        {
            printf("\nSupplier found.\n");

            printf("Supplier ID: %d\n", supplierID[i]);
            printf("Supplier Name: %s\n", supplierName[i]);
            printf("Email: %s\n", supplierEmail[i]);
            printf("Contact Number: %s\n", supplierContactNumber[i]);
            printf("Location: %s\n", supplierLocation[i]);
            printf("Supplier Category: %s\n", supplierCategory[i]);
            printf("Amount Owed: N$%.2f\n", amountOwed[i]);


            if (amountOwed[i] == 0)
            {
                printf("Payment Status: PAID\n");
            }
            else
            {
                printf("Payment Status: OUTSTANDING\n");
            }

            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Supplier not found.\n");
    }
}

void compareSuppliers(void)
{
    int firstID;
    int secondID;

    int firstIndex = -1;
    int secondIndex = -1;

    int i;

    if (supplierCount < 2)
    {
        printf("At least two suppliers are required.\n");
        return;
    }

    firstID =
        getValidInt("\nEnter first Supplier ID: ", 1000, 999999999);

    secondID =
        getValidInt("Enter second Supplier ID: ", 1000, 999999999);

    /* Finding suppliers */
    for (i = 0; i < supplierCount; i++)
    {
        if (supplierID[i] == firstID)
        {
            firstIndex = i;
        }

        if (supplierID[i] == secondID)
        {
            secondIndex = i;
        }
    }

    if (firstIndex == -1 || secondIndex == -1)
    {
        printf("One or both suppliers were not found.\n");
        return;
    }

    printf("\n%s is owed N$%.2f\n",
           supplierName[firstIndex],
           amountOwed[firstIndex]);

    printf("%s is owed N$%.2f\n",
           supplierName[secondIndex],
           amountOwed[secondIndex]);

    /* Comparing the Amount Owed */
    if (amountOwed[firstIndex] > amountOwed[secondIndex])
    {
        printf("%s is owed more money.\n",
               supplierName[firstIndex]);
    }

    else if (amountOwed[secondIndex] > amountOwed[firstIndex])
    {
        printf("%s is owed more money.\n",
               supplierName[secondIndex]);
    }

    else
    {
        printf("Both suppliers are owed the same amount.\n");
    }

    /* Comparing the Supplier Category */
    if (strcmp(
            supplierCategory[firstIndex],
            supplierCategory[secondIndex]
        ) == 0)
    {
        printf("Both suppliers are in the same category.\n");
    }
    else
    {
        printf("The suppliers are in different categories.\n");
    }
}