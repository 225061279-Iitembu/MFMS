#include <stdio.h>
#include <string.h>
#include "validation.h"

int isValidPositiveAmount(float amount)
{
    if (amount > 0)
    {
        return 1;
    }
    return 0;
}

int isValidBudget(float amount)
{
    if (amount >= 0)
    {
        return 1;
    }
    return 0;
}

int isNonEmptyString(char str[])
{
    if (strlen(str) == 0)
    {
        return 0;
    }
    return 1;
}

int isValidMenuChoice(int choice, int min, int max)
{
    if (choice >= min && choice <= max)
    {
        return 1;
    }
    return 0;
}

void stripNewline(char str[])
{
    str[strcspn(str, "\n")] = '\0';
}
