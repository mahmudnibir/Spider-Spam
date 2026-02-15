/*
 * LESSON 4: For Loops (Repeating Stuff!)
 * 
 * Loops let you repeat code without writing it 100 times!
 * Super powerful! 🔄
 * 
 * Your Original: factorial.c, reversetable.c
 */

#include <stdio.h>

int main() {
    // Count from 1 to 5
    printf("Counting:\n");
    for (int i = 1; i <= 5; i++) {
        printf("%d ", i);
    }
    printf("\n\n");
    
    // Your original: Factorial!
    printf("=== Factorial Calculator ===\n");
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result = result * i;
    }
    printf("%d! = %d\n\n", n, result);
    
    // Your original: Multiplication table (reverse)
    printf("=== Times Table (Backwards) ===\n");
    int num = 5;
    for (int i = 10; i >= 1; i--) {
        printf("%d x %d = %d\n", num, i, num * i);
    }
    
    return 0;
}

/*
 * Loop breakdown:
 * for (start; keep going while; update) {
 *     do this
 * }
 * 
 * Example:
 * for (i = 1; i <= 5; i++) {
 *     - Start: i = 1
 *     - Keep going while i <= 5
 *     - Update: increase i by 1
 * }
 */
