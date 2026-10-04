# MFMS Testing Documentation

## 1. Introduction

I tested the Municipal Financial Management System to make sure the different parts of the program are working properly.

I tested the program by running it and going through the different menus and functions.

## 2. Testing Results

| Test                  | Expected Result                      | Actual Result                               | Status  |
| --------------------- | ------------------------------------ | ------------------------------------------- | ------- |
| Main Menu             | Main menu should open                | Main menu opened                            | PASS    |
| Add Employee          | Employee should be added             | Employee was added successfully             | PASS    |
| Display Employee      | Employee details should show         | Employee details showed correctly           | PASS    |
| Search Employee       | Employee should be found using ID    | Employee was found                          | PASS    |
| Calculate Salary      | Salary should be calculated          | N$52,000 was calculated                     | PASS    |
| Add Department Budget | Budget should be added               | Budget was added successfully               | PASS    |
| Display Budgets       | Budgets should be displayed          | Budgets were displayed                      | PASS    |
| Calculate Budget      | System should show budget status     | Within budget and over budget were detected | PASS    |
| Add Supplier          | Supplier should be added             | Supplier was added successfully             | PASS    |
| Display Suppliers     | Suppliers should be displayed        | Suppliers were displayed                    | PASS    |
| Search Supplier       | Supplier should be found             | Flower Supplies was found                   | PASS    |
| Compare Suppliers     | Suppliers should be compared         | Suppliers were compared correctly           | PASS    |
| Add Asset             | Asset should be added                | Asset was added successfully                | PASS    |
| View Assets           | Asset details should show            | Asset details were displayed                | PASS    |
| Employee Report       | Employee report should display       | Report displayed                            | PARTIAL |
| Budget Report         | Budget information should display    | Shows loading...                            | PARTIAL |
| Supplier Report       | Supplier information should display  | Shows loading...                            | PARTIAL |
| Asset Report          | Asset information should display     | Shows loading...                            | PARTIAL |
| Financial Report      | Financial information should display | Shows loading...                            | PARTIAL |
| Display All Reports   | All reports should display           | All reports displayed                       | PASS    |
| Return to Main Menu   | Should return to main menu           | Returned successfully                       | PASS    |

## 3. Testing Environment

I tested the system using:

* Windows
* Visual Studio Code
* GCC
* ANSI C (C99)
* Git and GitHub

## 4. Compilation Test

I compiled the program using:

```bash
gcc main.c employees.c budget.c suppliers.c assets.c reports.c validation.c -o mfms
```

The program compiled successfully without any errors.

## 5. Problems Found

While testing the system, I found that the Reports module is not fully completed yet.

The Budget Report, Supplier Report, Asset Report and Financial Report display loading... instead of the actual information.

The Employee Report also displays fixed values instead of the actual employee information entered into the system.

The other main functions that I tested worked correctly.

## 6. Conclusion

Overall, most of the main functions of the MFMS are working correctly.

The Employee, Budget, Supplier and Asset Management sections were tested successfully.

The Reports section still needs some work so that it can display the actual information from the system instead of the placeholder values.
