/*
 * EXAMPLE: Swap Two Numbers Using Pointers
 */

#include <stdio.h>

void swap(int *a, int *b);

int main() {
    int x = 10, y = 20;
    
    printf("Before swap: x = %d, y = %d\n", x, y);
    
    swap(&x, &y);  // Send addresses
    
    printf("After swap: x = %d, y = %d\n", x, y);
    
    return 0;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// This actually swaps the original variables!
// Without pointers, it wouldn't work!
