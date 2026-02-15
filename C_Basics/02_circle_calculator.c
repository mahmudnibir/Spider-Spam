/*
 * EXAMPLE: Simple Calculator
 */

#include <stdio.h>

int main() {
    int x = 20;
    int y = 4;
    
    printf("x = %d, y = %d\n\n", x, y);
    
    printf("Addition: %d + %d = %d\n", x, y, x + y);
    printf("Subtraction: %d - %d = %d\n", x, y, x - y);
    printf("Multiplication: %d * %d = %d\n", x, y, x * y);
    printf("Division: %d / %d = %d\n", x, y, x / y);
    
    return 0;
}

// Try changing x and y values!
