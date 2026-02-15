/*
 * COMMON MISTAKES: Math Operations ❌
 */

#include <stdio.h>

int main() {
    
    /* ❌ MISTAKE 1: Forgetting operator precedence */
    int result1 = 5 + 3 * 2;      // Equals 11, not 16!
    printf("5 + 3 * 2 = %d (multiplication first!)\n", result1);
    
    int result2 = (5 + 3) * 2;    // ✅ Use parentheses for clarity
    printf("(5 + 3) * 2 = %d\n\n", result2);
    
    
    /* ❌ MISTAKE 2: Integer division loses decimals */
    int a = 7, b = 2;
    // int result = 7 / 2;  // Gives 3, not 3.5!
    printf("7 / 2 = %d (lost the .5!)\n", a / b);
    
    float correct = 7.0 / 2;  // ✅ Use float for decimals
    printf("7.0 / 2 = %.2f (correct!)\n\n", correct);
    
    
    /* ❌ MISTAKE 3: Modulo with float/double */
    // float x = 7.5 % 2.0;  // ❌ ERROR! % only works with integers
    int remainder = 7 % 2;   // ✅ Correct
    printf("7 %% 2 = %d\n\n", remainder);
    
    
    /* ❌ MISTAKE 4: Using wrong operator for power */
    int num = 2;
    // int power = num ^ 3;  // ❌ ^ is NOT power in C!
    int power = num * num * num;  // ✅ Multiply manually
    printf("2 cubed = %d\n\n", power);
    
    
    /* ❌ MISTAKE 5: Division by zero */
    int x = 10;
    // int bad = x / 0;  // ❌ NEVER divide by zero! Program crashes!
    
    int divisor = 0;
    if (divisor != 0) {  // ✅ Check first!
        printf("Result: %d\n", x / divisor);
    } else {
        printf("Can't divide by zero!\n");
    }
    
    
    printf("\nRemember: Be careful with division! 👍\n");
    
    return 0;
}

/*
 * Key Points:
 * - Multiplication/Division happen before Addition/Subtraction
 * - Use parentheses when unsure: (5 + 3) * 2
 * - Integer division drops decimals: 7/2 = 3
 * - % (modulo) only works with integers
 * - Never divide by zero!
 */
