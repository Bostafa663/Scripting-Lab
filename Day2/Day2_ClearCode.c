#include <stdio.h>

#define MAX_EMPLOYEES 100

// Define a structure to store employee details
typedef struct {
    char name[50];          // Employee name
    float hoursWorked;      // Hours worked by the employee
    float hourlyRate;       // Hourly rate of the employee
    float basicSalary;      // Basic salary calculated as hoursWorked * hourlyRate
    float incentives;       // Incentives calculated as 52% of basicSalary
    float netSalary;        // Net salary after deducting tax
} Employee;

Employee employees[MAX_EMPLOYEES]; // Array to store employee data
int employeeCount = 0;              // Counter to keep track of the number of employees

// Function to calculate tax based on salary ranges
float calculateTax(float salary) {
    float tax = 0.0;
    if ((salary <= 14999) && (salary >= 0)) {
        tax = 0 + ((salary - 0) * 0.15);
    } else if ((salary <= 29999) && (salary >= 15000)) {
        tax = 2250 + ((salary - 15000) * 0.16);
    } else if ((salary <= 49999) && (salary >= 30000)) {
        tax = 4650 + ((salary - 30000) * 0.18);
    } else if ((salary <= 79999) && (salary >= 50000)) {
        tax = 8250 + ((salary - 50000) * 0.20);
    } else if ((salary <= 150000) && (salary >= 80000)) {
        tax = 14250 + ((salary - 80000) * 0.25);
    } else {
        return -1; // Return -1 if salary is out of range
    }
    return tax;
}

// Function to add a new employee
void addEmployee() {
    if (employeeCount >= MAX_EMPLOYEES) {
        printf("Cannot add more employees.\n");
        return;
    }

    Employee newEmployee;
    printf("Enter employee name: ");
    scanf("%s", newEmployee.name);
    printf("Enter hours worked: ");
    scanf("%f", &newEmployee.hoursWorked);
    printf("Enter hourly rate: ");
    scanf("%f", &newEmployee.hourlyRate);

    // Calculate basic salary, incentives, and gross salary
    newEmployee.basicSalary = newEmployee.hoursWorked * newEmployee.hourlyRate;
    newEmployee.incentives = newEmployee.basicSalary * 0.52; // Incentives = 52% of basic salary

    float grossSalary = newEmployee.basicSalary + newEmployee.incentives;
    float tax = calculateTax(grossSalary);

    // Check if salary is out of range
    if (tax == -1) {
        goto label; // Jump to the label if salary is out of range
    }

    newEmployee.netSalary = grossSalary - tax;

    // Add the new employee to the array
    employees[employeeCount++] = newEmployee;
    printf("Employee added successfully.\n");
    return;

label:
    printf("Error: Salary is out of range.\n\n");
}

// Function to display all employees
void displayEmployees() {
    for (int i = 0; i < employeeCount; i++) {
        printf("Name: %s\n", employees[i].name);
        printf("Hours Worked: %.2f, Hourly Rate: %.2f\n", employees[i].hoursWorked, employees[i].hourlyRate);
        printf("Basic Salary: %.2f, Incentives: %.2f, Net Salary: %.2f\n", employees[i].basicSalary, employees[i].incentives, employees[i].netSalary);
        printf("\n");
    }
}

// Function to save employee data to a file
void saveToFile() {
    FILE *file = fopen("employees.txt", "a"); // Open file in append mode
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    // Write employee data to the file
    for (int i = 0; i < employeeCount; i++) {
        fprintf(file, "%s %.2f %.2f %.2f %.2f %.2f\n", employees[i].name, employees[i].hoursWorked, employees[i].hourlyRate, employees[i].basicSalary, employees[i].incentives, employees[i].netSalary);
    }

    fclose(file); // Close the file
    printf("Data saved to file.\n");
}

// Function to load employee data from a file
void loadFromFile() {
    FILE *file = fopen("employees.txt", "r"); // Open file in read mode
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    // Read employee data from the file
    employeeCount = 0;
    while (fscanf(file, "%s %f %f %f %f %f", employees[employeeCount].name, &employees[employeeCount].hoursWorked, &employees[employeeCount].hourlyRate, &employees[employeeCount].basicSalary, &employees[employeeCount].incentives, &employees[employeeCount].netSalary) != EOF) {
        employeeCount++;
    }

    fclose(file); // Close the file
    printf("Data loaded from file.\n");
}

// Main function to run the program
int main() {
    int choice;
    do {
        // Display menu options
        printf("\n1. Add Employee\n2. Display Employees\n3. Save to File\n4. Load from File\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Perform actions based on user choice
        switch (choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                displayEmployees();
                break;
            case 3:
                saveToFile();
                break;
            case 4:
                loadFromFile();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5); // Continue until the user chooses to exit

    return 0;
}