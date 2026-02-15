/*
 * LESSON 1: Variables and Data Types
 * 
 * Hey there! Welcome to C programming! 👋
 * In this lesson, you'll learn how to store information in your program.
 * Think of variables as labeled boxes where you can put different types of stuff!
 */

#include <stdio.h>

int main() {
    // INTEGERS (whole numbers) - like counting items
    int age = 21;
    int score = 100;
    
    printf("Your age: %d\n", age);
    printf("Your score: %d\n\n", score);
    
    // FLOAT (decimal numbers) - when you need fractions
    float price = 9.99;
    float height = 5.8;
    
    printf("Price: $%.2f\n", price);
    printf("Height: %.1f feet\n\n", height);
    
    // CHAR (single letter or symbol)
    char grade = 'A';
    char initial = 'J';
    
    printf("Grade: %c\n", grade);
    printf("Initial: %c\n\n", initial);
    
    // DOUBLE (bigger decimal numbers - more precise)
    double pi = 3.14159265;
    
    printf("Pi: %.8f\n", pi);
    
    return 0;
}

/*
 * Quick Summary:
 * - int    → whole numbers (age, count, score)
 * - float  → decimal numbers (price, height)
 * - char   → single character (letter, symbol)
 * - double → precise decimal numbers (scientific stuff)
 * 
 * Remember: Always end statements with semicolon ;
 */
