/*
 * LESSON 2: Basic Math Operations
 * 
 * Let's do some math! Don't worry, it's super easy in C 😊
 * You already know +, -, ×, ÷ from school - same thing here!
 * 
 * Your Original: areaofcircle.c
 */

#include <stdio.h>

int main() {
    // Basic operations
    int a = 10;
    int b = 3;
    
    printf("a = %d, b = %d\n\n", a, b);
    
    // Addition (+)
    printf("a + b = %d\n", a + b);
    
    // Subtraction (-)
    printf("a - b = %d\n", a - b);
    
    // Multiplication (*)
    printf("a * b = %d\n", a * b);
    
    // Division (/)
    printf("a / b = %d\n", a / b);  // Note: gives 3, not 3.33!
    
    // Modulo (%) - remainder after division
    printf("a %% b = %d (remainder)\n\n", a % b);
    
    // Your original program: Circle area!
    printf("=== Circle Area Calculator ===\n");
    int radius;
    float area;
    float pi = 3.14;
    
    printf("Enter radius: ");
    scanf("%d", &radius);
    
    area = pi * radius * radius;  // Area = π × r²
    
    printf("Area = %.2f\n", area);
    
    return 0;
}

/*
 * Quick Guide:
 * + add
 * - subtract
 * * multiply
 * / divide
 * % remainder (modulo)
 */
