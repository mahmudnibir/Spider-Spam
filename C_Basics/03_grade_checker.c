/*
 * EXAMPLE: Positive or Negative?
 * 
 * Your Original: dividedby2.c (even/odd checker)
 */

#include <stdio.h>

int main() {
    int number;
    
    printf("Enter a number: ");
    scanf("%d", &number);
    
    // Check if even or odd
    if (number % 2 == 0) {
        printf("%d is EVEN!\n", number);
    } else {
        printf("%d is ODD!\n", number);
    }
    
    return 0;
}

// Try with different numbers: 10, 7, 0, -5
