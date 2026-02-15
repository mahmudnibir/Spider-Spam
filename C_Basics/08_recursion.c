/*
 * LESSON 8: Recursion (Function Calls Itself!)
 * 
 * Mind-blowing: a function can call ITSELF! 
 * Tricky but super cool for some problems!
 * 
 * Your Original: fibonacci.c
 */

#include <stdio.h>

// Countdown using recursion
void countdown(int n);

// Factorial using recursion
int factorial(int n);

// Your original: Fibonacci!
int fibonacci(int n);

int main() {
    // Simple countdown
    printf("=== Countdown ===\n");
    countdown(5);
    printf("Blast off!\n\n");
    
    // Factorial
    printf("=== Factorial ===\n");
    printf("5! = %d\n\n", factorial(5));
    
    // Your original: Fibonacci
    printf("=== Fibonacci Sequence ===\n");
    printf("First 10 Fibonacci numbers:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");
    
    return 0;
}

// Countdown: calls itself with smaller number
void countdown(int n) {
    if (n == 0) {  // STOP condition!
        return;
    }
    printf("%d... ", n);
    countdown(n - 1);  // Call itself!
}

// Factorial: n! = n × (n-1)!
int factorial(int n) {
    if (n <= 1) {  // STOP condition!
        return 1;
    }
    return n * factorial(n - 1);  // Call itself!
}

// Fibonacci: each number is sum of previous two
// 0, 1, 1, 2, 3, 5, 8, 13...
int fibonacci(int n) {
    if (n == 0) return 0;  // STOP conditions!
    if (n == 1) return 1;
    
    return fibonacci(n - 1) + fibonacci(n - 2);  // Call itself twice!
}

/*
 * Recursion needs:
 * 1. Base case (STOP condition) - or it goes forever!
 * 2. Recursive case (call itself with smaller problem)
 * 
 * Like Russian dolls - each one contains a smaller one!
 */
