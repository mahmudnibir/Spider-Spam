/*
 * COMMON MISTAKES: Recursion ❌
 */

#include <stdio.h>

// Good recursion examples
int goodCountdown(int n);
int safePower(int base, int exp);

int main() {
    
    /* ❌ MISTAKE 1: No base case (runs forever!) */
    // void badRecursion(int n) {
    //     printf("%d ", n);
    //     badRecursion(n - 1);  // ❌ Never stops!
    // }
    
    printf("Good recursion: ");
    goodCountdown(5);
    printf("\n\n");
    
    
    /* ❌ MISTAKE 2: Base case never reached */
    // int bad(int n) {
    //     if (n == 0) return 0;  // Base case
    //     return bad(n + 1);  // ❌ n gets BIGGER! Never reaches 0!
    // }
    
    // ✅ Make sure you move TOWARD base case
    printf("2^3 = %d\n\n", safePower(2, 3));
    
    
    /* ❌ MISTAKE 3: Forgetting to return */
    // int wrong(int n) {
    //     if (n == 1) return 1;
    //     n * wrong(n - 1);  // ❌ Forgot return!
    // }
    
    
    /* ❌ MISTAKE 4: Too deep recursion */
    // Calling with huge number can crash!
    // safePower(2, 1000);  // ❌ Too many recursive calls!
    // Use loops for big numbers
    
    
    printf("Recursion done safely! Nice work! 🎯\n");
    
    return 0;
}

// Countdown with proper base case
int goodCountdown(int n) {
    if (n <= 0) {  // ✅ Base case
        return 0;
    }
    printf("%d ", n);
    return goodCountdown(n - 1);  // ✅ Moving toward base case
}

// Power with proper recursion
int safePower(int base, int exp) {
    if (exp == 0) {  // ✅ Base case
        return 1;
    }
    return base * safePower(base, exp - 1);  // ✅ exp decreases
}

/*
 * Remember:
 * - ALWAYS have a base case (stop condition)
 * - Make sure you move TOWARD the base case
 * - Always return values if function isn't void
 * - Don't use recursion with huge numbers (stack overflow!)
 * - When in doubt, use a loop instead!
 */
