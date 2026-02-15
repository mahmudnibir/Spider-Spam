/*
 * EXAMPLE: Sum of Numbers (Recursive)
 */

#include <stdio.h>

// Sum from 1 to n recursively
int sum(int n);

int main() {
    int num = 5;
    
    printf("Sum from 1 to %d = %d\n", num, sum(num));
    
    return 0;
}

int sum(int n) {
    if (n == 1) {  // Base case
        return 1;
    }
    return n + sum(n - 1);  // Recursive case
}

// How it works:
// sum(5) = 5 + sum(4)
//        = 5 + 4 + sum(3)
//        = 5 + 4 + 3 + sum(2)
//        = 5 + 4 + 3 + 2 + sum(1)
//        = 5 + 4 + 3 + 2 + 1 = 15
