# Municipal Financial Management System (MFMS)

## PAP521S – Programming in Practice

### Project A

## About the Project

The Municipal Financial Management System (MFMS) is a console-based C program designed to help manage some of the basic financial and administrative activities of a municipality.

The system allows users to manage information about employees, budgets, suppliers and municipal assets. It also provides reports that can help users view and understand the information stored in the system.

This project was developed as part of the PAP521S – Programming in Practice course using ANSI C (C99).

## Group Members

| Name           | Student Number | Responsibility                          |
| -------------- | -------------- | --------------------------------------- |
| Collin         | 225114615      | Employee Management & Budget Management |
| Joaquim        | 225166135      | Supplier Management                     |
| IITEMBU        | 225061279      | Asset Management                        |
| Tangi          | 226135330      | Reports                                 |
| Johannes       | 223081787      | Integration & Validation                |
| Helena Iitembu | 225061279      | Testing & Documentation                 |

## Main Features

The system includes the following sections:

* Employee Management
* Budget Management
* Supplier Management
* Asset Management
* Reports
* Main Menu
* Input Validation

The program uses menus to make it easier for the user to navigate between the different secti
## Technologies Used

We used the following tools to develop the project:

* C (C99) – programming language
* GCC – compiler
* Visual Studio Code – development environment
* Git – version control
* GitHub – storing and collaborating on the project

## Project Files

The project is divided into different C source and header files so that each part of the system can be developed separately.

* `main.c` – contains the main menu and starts the program
* `employees.c` / `employees.h` – employee management
* `budget.c` / `budget.h` – budget management
* `suppliers.c` / `suppliers.h` – supplier management
* `assets.c` / `assets.h` – asset management
* `reports.c` / `reports.h` – reports
* `README.md` – project information and instructions

## How to Compile

Make sure GCC is installed and open the terminal in the project folder.

Run:

```bash
gcc main.c employees.c budget.c suppliers.c assets.c reports.c -o mfms
```

If there are no errors, the program will be compiled successfully.

## How to Run

### Windows

```bash
mfms.exe
```

### Linux/macOS

```bash
./mfms
```

## Project Status

The project is currently under development. Each group member is working on their assigned section, after which the different parts will be combined and tested as one system.
