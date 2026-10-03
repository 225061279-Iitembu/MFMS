
#ifndef VALIDATION_H
#define VALIDATION_H

/* Input validation functions used by all MFMS modules.
   Use these instead of scanf. */

/* asks until the user enters a whole number from min to max */
int getValidInt(char prompt[], int min, int max);

/* asks until the user enters a number that is at least min */
double getValidDouble(char prompt[], double min);

/* asks until the user enters text that is not empty and fits in the array */
void getValidString(char prompt[], char text[], int size);

/* returns 1 if the email looks correct, otherwise 0 */
int isValidEmail(char email[]);

/* returns 1 if the phone number looks correct, otherwise 0 */
int isValidPhone(char phone[]);

#endif
