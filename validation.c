/* validation.c - checks the input from the user */

#include <stdio.h>
#include <string.h>
#include "validation.h"

/* Reads a line of text into line and removes the Enter.
   If the user typed too much, the extra is thrown away and line becomes empty. */
void readLine(char line[], int size)
{
    int c;

    if (fgets(line, size, stdin) == NULL)
    {
        line[0] = '\0';
        return;
    }

    if (line[strlen(line) - 1] != '\n')
    {
        while ((c = getchar()) != '\n' && c != EOF)
        {
        }
        line[0] = '\0';
    }

    line[strcspn(line, "\n")] = '\0';
}

/* Asks until the user enters a whole number from min to max */
int getValidInt(char prompt[], int min, int max)
{
    char line[50];
    int number, i, valid, sign;

    do
    {
        printf("%s", prompt);
        readLine(line, sizeof(line));

        valid = 1;
        number = 0;
        sign = 1;
        i = 0;

        if (line[0] == '-')
        {
            sign = -1;
            i = 1;
        }

        /* empty, or too many digits */
        if (line[i] == '\0' || strlen(line) > 9)
        {
            valid = 0;
        }

        /* every character must be a digit */
        while (valid == 1 && line[i] != '\0')
        {
            if (line[i] >= '0' && line[i] <= '9')
            {
                number = number * 10 + (line[i] - '0');
            }
            else
            {
                valid = 0;
            }
            i++;
        }

        number = number * sign;

        if (valid == 0)
        {
            printf("Invalid input. Enter a whole number.\n");
        }
        else if (number < min || number > max)
        {
            printf("Enter a number from %d to %d.\n", min, max);
            valid = 0;
        }

    } while (valid == 0);

    return number;
}

/* Asks until the user enters a number (decimals allowed) that is not less than min */
double getValidDouble(char prompt[], double min)
{
    char line[50];
    double number, divisor;
    int i, valid, sign, dots, digits;

    do
    {
        printf("%s", prompt);
        readLine(line, sizeof(line));

        valid = 1;
        number = 0;
        divisor = 1;
        sign = 1;
        dots = 0;
        digits = 0;
        i = 0;

        if (line[0] == '-')
        {
            sign = -1;
            i = 1;
        }

        if (strlen(line) > 15)
        {
            valid = 0;
        }

        while (valid == 1 && line[i] != '\0')
        {
            if (line[i] >= '0' && line[i] <= '9')
            {
                number = number * 10 + (line[i] - '0');
                digits++;
                if (dots == 1)
                {
                    divisor = divisor * 10;   /* digit after the decimal point */
                }
            }
            else if (line[i] == '.')
            {
                dots++;
            }
            else
            {
                valid = 0;
            }
            i++;
        }

        if (digits == 0 || dots > 1)
        {
            valid = 0;
        }

        number = sign * number / divisor;

        if (valid == 0)
        {
            printf("Invalid input. Enter a number.\n");
        }
        else if (number < min)
        {
            printf("Value cannot be less than %.2f.\n", min);
            valid = 0;
        }

    } while (valid == 0);

    return number;
}

/* Asks until the user enters text that is not empty and fits in text[size] */
void getValidString(char prompt[], char text[], int size)
{
    char line[100];
    int i, valid, length;

    do
    {
        printf("%s", prompt);
        readLine(line, sizeof(line));

        length = strlen(line);
        valid = 0;

        /* must have at least one character that is not a space */
        for (i = 0; i < length; i++)
        {
            if (line[i] != ' ')
            {
                valid = 1;
            }
        }

        if (valid == 0)
        {
            printf("Input cannot be empty or too long.\n");
        }
        else if (length >= size)
        {
            printf("Too long. Maximum is %d characters.\n", size - 1);
            valid = 0;
        }

    } while (valid == 0);

    strcpy(text, line);
}

/* Returns 1 if the email has an @ and a dot after it (name@company.com) */
int isValidEmail(char email[])
{
    int i, at = -1, dot = -1;

    for (i = 0; email[i] != '\0'; i++)
    {
        if (email[i] == ' ')
        {
            return 0;
        }
        if (email[i] == '@')
        {
            at = i;
        }
        if (email[i] == '.')
        {
            dot = i;
        }
    }

    if (at < 1 || dot < at + 2 || email[dot + 1] == '\0')
    {
        return 0;
    }
    return 1;
}

/* Returns 1 if the phone only has digits, + - or spaces and 7 to 15 digits */
int isValidPhone(char phone[])
{
    int i, digits = 0;

    for (i = 0; phone[i] != '\0'; i++)
    {
        if (phone[i] >= '0' && phone[i] <= '9')
        {
            digits++;
        }
        else if (phone[i] != '+' && phone[i] != '-' && phone[i] != ' ')
        {
            return 0;
        }
    }

    if (digits >= 7 && digits <= 15)
    {
        return 1;
    }
    return 0;
}

