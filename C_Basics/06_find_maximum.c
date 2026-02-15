/*
 * EXAMPLE: Find the Biggest Number
 */

#include <stdio.h>

int main() {
    int numbers[5] = {23, 67, 12, 89, 45};
    
    // Assume first is biggest
    int max = numbers[0];
    
    // Check all others
    for (int i = 1; i < 5; i++) {
        if (numbers[i] > max) {
            max = numbers[i];
        }
    }
    
    printf("Numbers: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    
    printf("Biggest: %d\n", max);
    
    return 0;
}

// Try changing the numbers!
