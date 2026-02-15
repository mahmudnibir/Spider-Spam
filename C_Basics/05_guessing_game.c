/*
 * EXAMPLE: Sum Numbers Until 0
 */

#include <stdio.h>

int main() {
    int num, sum = 0;
    
    printf("Enter numbers (0 to stop):\n");
    scanf("%d", &num);
    
    while (num != 0) {
        sum = sum + num;
        scanf("%d", &num);
    }
    
    printf("Total sum: %d\n", sum);
    
    return 0;
}

// Try: 5, 10, 15, 0 (should give 30)
