/*
 * LESSON 7: Functions (Your Own Commands!)
 * 
 * Functions let you create your own mini-programs!
 * Write code once, use it many times! 🎯
 * 
 * Your Original: functions.c
 */

#include <stdio.h>

// Tell C about your function first
void sayHello();
int add(int a, int b);
int square(int num);

int main() {
    // Your original: Say hello!
    printf("=== Calling Functions ===\n");
    sayHello();
    sayHello();  // Can call it many times!
    printf("\n");
    
    // Function that returns a value
    int sum = add(5, 3);
    printf("5 + 3 = %d\n", sum);
    
    // Can use result directly
    printf("10 squared = %d\n", square(10));
    
    return 0;
}

// Your original function
void sayHello() {
    printf("Hello World! ");
}

// Add two numbers
int add(int a, int b) {
    return a + b;  // Send result back
}

// Square a number
int square(int num) {
    return num * num;
}

/*
 * Function parts:
 * 1. Declaration (at top): tells C it exists
 * 2. Definition (below): what it actually does
 * 3. Call (in main): use it!
 * 
 * void = returns nothing
 * int = returns a number
 */
