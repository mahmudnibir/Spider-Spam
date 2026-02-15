/*
 * ========================================
 *   CHAPTER 19: HEADER FILES - PRACTICE ✏️
 * ========================================
 * 
 * Let's simulate a multi-file project!
 * (In real projects, these would be separate files)
 */

#include <stdio.h>
#include <string.h>

// ========================================
// utilities.h - General utilities
// ========================================
#ifndef UTILITIES_H
#define UTILITIES_H

void printHeader(const char *title);
void printLine(int length);
int getIntInput(const char *prompt);

#endif

// ========================================
// calculator.h - Calculator functions
// ========================================
#ifndef CALCULATOR_H
#define CALCULATOR_H

int calc_add(int a, int b);
int calc_subtract(int a, int b);
int calc_multiply(int a, int b);
float calc_divide(float a, float b);
void showCalculatorMenu();

#endif

// ========================================
// student.h - Student record functions
// ========================================
#ifndef STUDENT_H
#define STUDENT_H

typedef struct {
    char name[50];
    int rollNo;
    float marks;
} Student;

void displayStudent(Student s);
float calculateGrade(float marks);

#endif

// ========================================
// IMPLEMENTATIONS
// ========================================

// utilities.c implementation
void printHeader(const char *title) {
    int len = strlen(title);
    printLine(len + 4);
    printf("* %s *\n", title);
    printLine(len + 4);
}

void printLine(int length) {
    for (int i = 0; i < length; i++) {
        printf("=");
    }
    printf("\n");
}

int getIntInput(const char *prompt) {
    int value;
    printf("%s", prompt);
    scanf("%d", &value);
    return value;
}

// calculator.c implementation
int calc_add(int a, int b) {
    return a + b;
}

int calc_subtract(int a, int b) {
    return a - b;
}

int calc_multiply(int a, int b) {
    return a * b;
}

float calc_divide(float a, float b) {
    if (b != 0) {
        return a / b;
    }
    printf("Error: Division by zero!\n");
    return 0;
}

void showCalculatorMenu() {
    printf("\n1. Add\n");
    printf("2. Subtract\n");
    printf("3. Multiply\n");
    printf("4. Divide\n");
    printf("5. Exit\n");
}

// student.c implementation
void displayStudent(Student s) {
    printf("%-20s  Roll: %-8d  Marks: %-6.2f  Grade: %.2f%%\n",
           s.name, s.rollNo, s.marks, calculateGrade(s.marks));
}

float calculateGrade(float marks) {
    return marks;  // Simple pass-through for this example
}

// ========================================
// MAIN PROGRAM (main.c)
// ========================================
int main() {
    
    printHeader("MULTI-MODULE DEMO");
    
    printf("\nThis demonstrates how header files organize code.\n");
    printf("In real projects:");
    printf("  utilities.h + utilities.c\n");
    printf("  calculator.h + calculator.c\n");
    printf("  student.h + student.c\n");
    printf("  main.c (uses all above)\n");
    
    // Using utilities module
    printf("\n");
    printHeader("Using Utilities Module");
    int userAge = getIntInput("Enter your age: ");
    printf("You entered: %d\n", userAge);
    
    // Using calculator module
    printf("\n");
    printHeader("Using Calculator Module");
    
    int num1 = 25, num2 = 5;
    printf("Numbers: %d and %d\n\n", num1, num2);
    
    printf("Add:      %d\n", calc_add(num1, num2));
    printf("Subtract: %d\n", calc_subtract(num1, num2));
    printf("Multiply: %d\n", calc_multiply(num1, num2));
    printf("Divide:   %.2f\n", calc_divide(num1, num2));
    
    // Using student module
    printf("\n");
    printHeader("Using Student Module");
    
    Student students[3] = {
        {"Alice Johnson", 101, 85.5},
        {"Bob Smith", 102, 92.0},
        {"Charlie Brown", 103, 78.5}
    };
    
    printf("\nStudent Records:\n");
    printLine(70);
    
    for (int i = 0; i < 3; i++) {
        displayStudent(students[i]);
    }
    
    printLine(70);
    
    // Summary
    printf("\n");
    printHeader("Summary");
    printf("✅ Used functions from utilities.h\n");
    printf("✅ Used functions from calculator.h\n");
    printf("✅ Used structure from student.h\n");
    printf("\nThis is how real C projects are organized!\n");
    
    return 0;
}

/*
 * 💡 REAL PROJECT STRUCTURE:
 * 
 * project/
 *   ├── main.c
 *   ├── utilities.h
 *   ├── utilities.c
 *   ├── calculator.h
 *   ├── calculator.c
 *   ├── student.h
 *   └── student.c
 * 
 * Compilation:
 * gcc main.c utilities.c calculator.c student.c -o program
 * 
 * Or use a Makefile for easier building!
 * 
 * 🎯 CHALLENGE:
 * Try creating actual separate files:
 * 1. Create utilities.h and utilities.c
 * 2. Move function declarations to .h
 * 3. Move implementations to .c
 * 4. Compile them together
 * 5. See how modular code works!
 * 
 * Benefits:
 * - Easy to maintain
 * - Reusable across projects
 * - Team can work on different modules
 * - Professional project structure
 */
