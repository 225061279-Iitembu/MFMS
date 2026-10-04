#include <stdio.h>
#include <string.h>
#include "assets.h"
#include "validation.h"

#define MAX_ASSETS 100

typedef struct {
    int id;
    char name[50];
    char type[30];
    float value;
    char status[20];
} Asset;

Asset assets[MAX_ASSETS];
int assetCount = 0;

void addAsset(void)
{
    if (assetCount >= MAX_ASSETS) {
        printf("Asset storage is full.\n");
        return;
    }

    printf("\n--- Add Asset ---\n");

    assets[assetCount].id =
        getValidInt("Enter asset ID: ", 1, 1000000);

    getValidString("Enter asset name: ",
                   assets[assetCount].name,
                   sizeof(assets[assetCount].name));

    getValidString("Enter asset type: ",
                   assets[assetCount].type,
                   sizeof(assets[assetCount].type));

    assets[assetCount].value =
        (float)getValidDouble("Enter asset value: ", 0.0);

    getValidString(
        "Enter asset status (Available/In Use/Under Repair): ",
        assets[assetCount].status,
        sizeof(assets[assetCount].status)
    );

    assetCount++;

    printf("Asset added successfully.\n");
}

void viewAssets(void)
{
    int i;

    printf("\n--- Asset List ---\n");

    if (assetCount == 0) {
        printf("No assets have been added yet.\n");
        return;
    }

    for (i = 0; i < assetCount; i++) {
        printf("\nAsset ID: %d\n", assets[i].id);
        printf("Name: %s\n", assets[i].name);
        printf("Type: %s\n", assets[i].type);
        printf("Value: %.2f\n", assets[i].value);
        printf("Status: %s\n", assets[i].status);
    }
}

void searchAsset(void)
{
    int id;
    int i;
    int found = 0;

    printf("\n--- Search Asset ---\n");

    id = getValidInt("Enter asset ID to search: ", 1, 1000000);

    for (i = 0; i < assetCount; i++) {
        if (assets[i].id == id) {
            printf("\nAsset found!\n");
            printf("Asset ID: %d\n", assets[i].id);
            printf("Name: %s\n", assets[i].name);
            printf("Type: %s\n", assets[i].type);
            printf("Value: %.2f\n", assets[i].value);
            printf("Status: %s\n", assets[i].status);

            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Asset with ID %d was not found.\n", id);
    }
}

void assetMenu(void)
{
    int choice;

    do {
        printf("\n===== ASSET MANAGEMENT =====\n");
        printf("1. Add Asset\n");
        printf("2. View Assets\n");
        printf("3. Search Asset\n");
        printf("4. Return to Main Menu\n");
        choice = getValidInt("Enter your choice: ", 1, 4);

        switch (choice) {
            case 1:
                addAsset();
                break;

            case 2:
                viewAssets();
                break;

            case 3:
                searchAsset();
                break;

            case 4:
                printf("Returning to main menu...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 4);
}

