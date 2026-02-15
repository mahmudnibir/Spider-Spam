/*
 * EXAMPLE: Print 1 to 10
 * 
 * Your Original: sumbetween2.c
 */

#include <stdio.h>

int main() {
    // Sum of numbers in a range
    int start, end, sum = 0;
    
    printf("Enter two numbers: ");
    scanf("%d %d", &start, &end);
    
    // Make sure start is smaller
    if (start > end) {
        int temp = start;
        start = end;
        end = temp;
    }
    
    for (int i = start; i <= end; i++) {
        sum = sum + i;
    }
    
    printf("Sum from %d to %d = %d\n", start, end, sum);
    
    return 0;
}

// Try: 1 to 10 (should give 55)
