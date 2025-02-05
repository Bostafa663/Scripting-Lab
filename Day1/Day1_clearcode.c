#include <stdio.h>

// Function prototypes
int calculateArea(int length, int width);
int convertFahrenheitToCelsius(int fahrenheit);
void evaluateGrade(int score);
void printMultiplicationTable(int number);

int main() {
    int choice;
    int length, width, fahrenheit, score, number;

    while (1) {
        printf("Enter '1' for area, '2' for temperature, '3' for grade, '4' for multiplication, or '5' to exit: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Please enter the length and width: ");
            scanf("%d %d", &length, &width);
            int area = calculateArea(length, width);
            printf("The area is: %d\n", area);
        } 
        else if (choice == 2) {
            printf("Please enter the temperature in Fahrenheit: ");
            scanf("%d", &fahrenheit);
            int celsius = convertFahrenheitToCelsius(fahrenheit);
            printf("The temperature in Celsius is: %d\n", celsius);
        } 
        else if (choice == 3) {
            printf("Please enter your score: ");
            scanf("%d", &score);
            evaluateGrade(score);
        } 
        else if (choice == 4) {
            printf("Please enter the number for multiplication table: ");
            scanf("%d", &number);
            printMultiplicationTable(number);
        } 
        else if (choice == 5) {
            printf("Goodbye!\n");
            break;
        } 
        else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// Function to calculate the area of a rectangle
int calculateArea(int length, int width) {
    return length * width;
}

// Function to convert Fahrenheit to Celsius
int convertFahrenheitToCelsius(int fahrenheit) {
    return (5.0 / 9.0) * (fahrenheit - 32);
}

// Function to evaluate and print the grade based on the score
void evaluateGrade(int score) {
    // Check if the score is out of range
    if (score < 0 || score > 100) {
        printf("Error: Score is out of range. Please enter a score between 0 and 100.\n");
        return; // Exit the function early
    }

    // Evaluate the grade based on the score
    if (score >= 90) {
        printf("The grade is A.\n");
    } else if (score >= 70) {
        printf("The grade is B.\n");
    } else if (score >= 60) {
        printf("The grade is C.\n");
    } else {
        printf("The grade is F.\n");
    }
}

// Function to print the multiplication table of a number
void printMultiplicationTable(int number) {
    for (int i = 1; i <= 10; i++) {
        printf("%d * %d = %d\n", i, number, i * number);
    }
}