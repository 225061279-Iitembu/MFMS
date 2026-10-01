#include <stdio.h>
#include <stdlib.h>
#include "reports.h"
#include "budget.h"
#include "assets.h"

void generateEmployeeReport() {
  printf("\n-----------------------------------------\n");
  printf("Employee Management Report\n");
  printf("Total employees: 35\n");
  printf("Average salary: N$ 18500\n");
  printf("Highest salary: N$ 42000\n");
  printf("Lowest salary: N$ 8500\n");
  printf("\n----------End Of Report--------------------\n");
}

void generateBudgetReport() {
  printf("\n-------------------------------------------\n");
  printf("Budget Report\n");
  printf("Total allocated budget: loading...\n");
  printf("Total expenditure: loading...\n");
  printf("Remaining balance: loading...\n");
  printf("Departments exceeding budget: loading...\n");
  printf("\n---------End Of Report----------------------\n");
}
void generateSupplierReport() {
  printf("\n--------------------------------------------\n");
  printf("Supplier Report\n");
  printf("Suppliers registeredin system: loading...\n");
  printf("\n--------------End Of Report-----------------\n");
}
void generateAssetsReport() {
  printf("\n--------------------------------------------\n");
  printf("Asset Report\n");
  printf("Registered municipal asset: loading...\n");
  printf("--------------End Of Report---------------------\n");
}
void generateFinancialReport() {
  printf("\n----------------------------------------------\n");
  printf("Financial Report\n");
  printf("Current finacial state: loading\n");
  printf("-----------------End Of Report--------------------\n");
}
void generateAllReports() {
  generateEmployeeReport();
  generateBudgetReport();
  generateSupplierReport();
  generateAssetsReport();
  generateFinancialReport();
  printf("\n All reports shown\n");
}
void reportsMenu() {
  int choice;
  do {
    printf("\n---------------------------------------------\n");
    printf("Select required report\n");
    printf("1. Employee Report\n");
    printf("2. Budget Report\n");
    printf("3. Supplier Report\n");
    printf("4. Asset Report\n");
    printf("5. Financial Report\n");
    printf("6. Display All Reports\n");
    printf("0. Back to main menu\n");
    scanf("%d", &choice);
    switch(choice) {
      case 1: generateEmployeeReport();
      break;
      case 2: generateBudgetReport();
      break;
      case 3: generateSupplierReport();
      break;
      case 4: generateAssetsReport();
      break;
      case 5: generateFinancialReport();
      break;
      case 6: generateAllReports();
      break;
      case 0: break;
      default: printf("Invalid choice entered.\n");
    }
  } while(choice != 0);
}
  
  
