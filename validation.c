
/* validation.c
   Input validation for the Municipal Financial Management System.
   Everything is read as a line of text with fgets and then checked
   one character at a time. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validation.h"

/* Reads one line from the keyboard into the array "line".
   Returns 1 if the line fitted in the array.
   Returns 0 if the user typed too much .
   (static means only this file can use this function) */
static int readLine(char line[], int size)
{
    int c;
    int length;

    if (fgets(line, size, stdin) == NULL)
    {
        printf("\nNo more input. Program closing.\n");
        exit(1);
    }

    length = strlen(line);

    /* if the last character is not Enter, the user typed too much */
    if (line[length - 1] != '\n')
    {
        while ((c = getchar()) != '\n' && c != EOF)
        {
            /* throw away the extra characters */
        }
        return 0;
    }

    /* remove the Enter at the end */
    line[strcspn(line, "\n")] = '\0';
    return 1;
}

/* Keeps asking until the user types a whole number between min and max */
int getValidInt(char prompt[], int min, int max)
{
    char line[50];
    int number;
    int sign;
    int digitCount;
    int i;
    int valid;
    int fitted;

    do
    {
        valid = 1;
        number = 0;
        sign = 1;
        digitCount = 0;
        i = 0;

        printf("%s", prompt);
        fitted = readLine(line, sizeof(line));

        if (fitted == 0)
        {
            printf("Input too long. Try again.\n");
            valid = 0;
        }
        else
        {
            /* a minus sign is only allowed at the start */
            if (line[0] == '-')
            {
                sign = -1;
                i = 1;
            }

            /* check every character is a digit and build the number */
            while (line[i] != '\0')
            {
                if (line[i] >= '0' && line[i] <= '9')
                {
                    if (digitCount < 9)
                    {
                        number = number * 10 + (line[i] - '0');
                    }
                    digitCount++;
                }
                else
                {
                    valid = 0;
                }
                i++;
            }

            if (digitCount == 0 || digitCount > 9)
            {
                valid = 0;
            }

            if (valid == 0)
            {
                printf("Invalid input. Please enter a whole number.\n");
            }
            else
            {
                number = number * sign;

                if (number < min || number > max)
                {
                    printf("Please enter a number between %d and %d.\n", min, max);
                    valid = 0;
                }
            }
        }

    } while (valid == 0);

    return number;
}

/* Keeps asking until the user types a number (decimals allowed)
   that is not less than min */
double getValidDouble(char prompt[], double min)
{
    char line[50];
    double number;
    double divisor;
    int sign;
    int digitCount;
    int dotCount;
    int i;
    int valid;
    int fitted;

    do
    {
        valid = 1;
        number = 0;
        divisor = 1;
        sign = 1;
        digitCount = 0;
        dotCount = 0;
        i = 0;

        printf("%s", prompt);
        fitted = readLine(line, sizeof(line));

        if (fitted == 0)
        {
            printf("Input too long. Try again.\n");
            valid = 0;
        }
        else
        {
            if (line[0] == '-')
            {
                sign = -1;
                i = 1;
            }

            /* check each character is a digit or one decimal point */
            while (line[i] != '\0')
            {
                if (line[i] >= '0' && line[i] <= '9')
                {
                    number = number * 10 + (line[i] - '0');
                    digitCount++;

                    /* after the decimal point, divide by 10 for each digit */
                    if (dotCount == 1)
                    {
                        divisor = divisor * 10;
                    }
                }
                else if (line[i] == '.')
                {
                    dotCount++;
                }
                else
                {
                    valid = 0;
                }
                i++;
            }

            if (digitCount == 0 || digitCount > 15 || dotCount > 1)
            {
                valid = 0;
            }

            if (valid == 0)
            {
                printf("Invalid input. Please enter a number.\n");
            }
            else
            {
                number = sign * number / divisor;

                if (number < min)
                {
                    printf("Value cannot be less than %.2f.\n", min);
                    valid = 0;
                }
            }
        }

    } while (valid == 0);

    return number;
}

/* Keeps asking until the user types text that is not empty
   and fits in the array "text" */
void getValidString(char prompt[], char text[], int size)
{
    char line[200];
    int i;
    int length;
    int valid;
    int fitted;
    int onlySpaces;

    do
    {
        valid = 1;

        printf("%s", prompt);
        fitted = readLine(line, sizeof(line));

        length = strlen(line);

        if (fitted == 0 || length >= size)
        {
            printf("Too long. Maximum is %d characters.\n", size - 1);
            valid = 0;
        }
        else
        {
            /* check the line is not empty or only spaces */
            onlySpaces = 1;
            for (i = 0; i < length; i++)
            {
                if (line[i] != ' ')
                {
                    onlySpaces = 0;
                }
            }

            if (onlySpaces == 1)
            {
                printf("Input cannot be empty.\n");
                valid = 0;
            }
        }

    } while (valid == 0);

    strcpy(text, line);
}

/* Returns 1 if the email has text, one @, and a dot after the @,
   with no spaces. For example: name@company.com */
int isValidEmail(char email[])
{
    int i;
    int length;
    int atCount = 0;
    int atPosition = -1;
    int lastDot = -1;

    length = strlen(email);

    for (i = 0; i < length; i++)
    {
        if (email[i] == ' ')
        {
            return 0;
        }
        if (email[i] == '@')
        {
            atCount++;
            atPosition = i;
        }
        if (email[i] == '.')
        {
            lastDot = i;
        }
    }

    if (atCount != 1)
    {
        return 0;
    }
    if (atPosition == 0)
    {
        return 0;               /* nothing before the @ */
    }
    if (lastDot < atPosition + 2)
    {
        return 0;               /* no dot after the @ */
    }
    if (lastDot == length - 1)
    {
        return 0;               /* nothing after the dot */
    }

    return 1;
}

/* Returns 1 if the phone number only has digits, +, - or spaces
   and has between 7 and 15 digits */
int isValidPhone(char phone[])
{
    int i;
    int length;
    int digitCount = 0;

    length = strlen(phone);

    for (i = 0; i < length; i++)
    {
        if (phone[i] >= '0' && phone[i] <= '9')
        {
            digitCount++;
        }
        else if (phone[i] != '+' && phone[i] != '-' && phone[i] != ' ')
        {
            return 0;
        }
    }

    if (digitCount >= 7 && digitCount <= 15)
    {
        return 1;
    }
    return 0;
}
