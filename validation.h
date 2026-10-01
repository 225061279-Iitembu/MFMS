/* validation.h
   Reusable validation functions used across the MFMS project. */

int isValidPositiveAmount(float amount);
int isValidBudget(float amount);
int isNonEmptyString(char str[]);
int isValidMenuChoice(int choice, int min, int max);
void stripNewline(char str[]);
