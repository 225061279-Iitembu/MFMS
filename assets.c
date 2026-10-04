#include <stdio.h>
#include <string.h>
#include "assets.h"

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

    printf("Enter asset ID: ");
    scanf("%d", &assets[assetCount].id);

    printf("Enter asset name: ");
    scanf(" %[^\n]", assets[assetCount].name);

    printf("Enter asset type: ");
    scanf(" %[^\n]", assets[assetCount].type);

    printf("Enter asset value: ");
    scanf("%f", &assets[assetCount].value);

    printf("Enter asset status (Available/In Use/Under Repair): ");
    scanf(" %[^\n]", assets[assetCount].status);

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

void assetMenu(void)
{
    int choice;

    do {
        printf("\n===== ASSET MANAGEMENT =====\n");
        printf("1. Add Asset\n");
        printf("2. View Assets\n");
        printf("3. Return to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addAsset();
                break;

            case 2:
                viewAssets();
                break;

            case 3:
                printf("Returning to main menu...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 3);
}
