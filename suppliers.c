#include <stdio.h>
#include <string.h>
#include "suppliers.h"

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
        printf("Enter your choice: ");

        scanf("%d", &choice);
        getchar();

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

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 5);
}

void addSupplier(void)
{
    int i;

    if (supplierCount >= MAX_SUPPLIERS)
    {
        printf("Supplier storage is full.\n");
        return;
    }

    /* Supplier ID */

    printf("\nEnter Supplier ID: ");
    scanf("%d", &supplierID[supplierCount]);

    while (supplierID[supplierCount] < 1000)
    {
        printf("Supplier ID must be at least 4 digits. Enter again: ");
        scanf("%d", &supplierID[supplierCount]);
    }

    getchar();

    /* Check for duplicate Supplier ID */

    for (i = 0; i < supplierCount; i++)
    {
        if (supplierID[i] == supplierID[supplierCount])
        {
            printf("Supplier ID already exists.\n");
            return;
        }
    }

    /* Supplier Name */

    printf("Enter Supplier Name: ");
    fgets(supplierName[supplierCount],
          sizeof(supplierName[supplierCount]), stdin);

    supplierName[supplierCount][
        strcspn(supplierName[supplierCount], "\n")
    ] = '\0';

    /* Email */

    printf("Enter Email: ");
    fgets(supplierEmail[supplierCount],
          sizeof(supplierEmail[supplierCount]), stdin);

    supplierEmail[supplierCount][
        strcspn(supplierEmail[supplierCount], "\n")
    ] = '\0';

    /* Contact Number */

    printf("Enter Contact Number: ");
    fgets(supplierContactNumber[supplierCount],
          sizeof(supplierContactNumber[supplierCount]), stdin);

    supplierContactNumber[supplierCount][
        strcspn(supplierContactNumber[supplierCount], "\n")
    ] = '\0';

    /* Location */

    printf("Enter Location: ");
    fgets(supplierLocation[supplierCount],
          sizeof(supplierLocation[supplierCount]), stdin);

    supplierLocation[supplierCount][
        strcspn(supplierLocation[supplierCount], "\n")
    ] = '\0';

    /* Supplier Category */

    printf("Enter Supplier Category: ");
    fgets(supplierCategory[supplierCount],
          sizeof(supplierCategory[supplierCount]), stdin);

    supplierCategory[supplierCount][
        strcspn(supplierCategory[supplierCount], "\n")
    ] = '\0';

    /* Amount Owed */

    printf("Enter Amount Owed: N$");
    scanf("%lf", &amountOwed[supplierCount]);

    while (amountOwed[supplierCount] < 0)
    {
        printf("Amount owed cannot be negative. Enter again: N$");
        scanf("%lf", &amountOwed[supplierCount]);
    }

    getchar();
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

    printf("\nEnter Supplier Name to search: ");

    fgets(name, sizeof(name), stdin);

    name[strcspn(name, "\n")] = '\0';

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

    printf("\nEnter first Supplier ID: ");
    scanf("%d", &firstID);

    printf("Enter second Supplier ID: ");
    scanf("%d", &secondID);

    getchar();

    /* Find both suppliers */

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


    /* Compare Amount Owed */

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

    /* Compare Supplier Category */

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