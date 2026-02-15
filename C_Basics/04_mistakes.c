/*
 * COMMON MISTAKES: For Loops ❌
 */

#include <stdio.h>

int main() {
    
    /* ❌ MISTAKE 1: Infinite loop (never stops!) */
    // for (int i = 1; i <= 5; i--) {  // ❌ i goes DOWN, never reaches 5!
    //     printf("%d ", i);  // This runs forever!
    // }
    
    for (int i = 1; i <= 5; i++) {  // ✅ i goes UP
        printf("%d ", i);
    }
    printf("\n\n");
    
    
    /* ❌ MISTAKE 2: Semicolon after for */
    // for (int i = 1; i <= 5; i++);  // ❌ Semicolon here breaks it!
    // {
    //     printf("%d ", i);  // This won't run in the loop
    // }
    
    for (int i = 1; i <= 3; i++) {  // ✅ No semicolon
        printf("%d ", i);
    }
    printf("\n\n");
    
    
    /* ❌ MISTAKE 3: Off-by-one error */
    // Wrong: prints 0 to 9 (10 numbers)
    printf("Wrong way (0-9): ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", i);
    }
    printf("\n");
    
    // Right: prints 1 to 10 (10 numbers)
    printf("Right way (1-10): ");
    for (int i = 1; i <= 10; i++) {
        printf("%d ", i);
    }
    printf("\n\n");
    
    
    /* ❌ MISTAKE 4: Using wrong variable */
    int sum = 0;
    for (int i = 1; i <= 5; i++) {
        // sum = sum + j;  // ❌ What's j? It doesn't exist!
        sum = sum + i;     // ✅ Use i (the loop variable)
    }
    printf("Sum: %d\n\n", sum);
    
    
    /* ❌ MISTAKE 5: Changing loop variable inside loop */
    printf("Dangerous: ");
    for (int i = 1; i <= 5; i++) {
        printf("%d ", i);
        // i = i + 1;  // ❌ Don't do this! Loop already does i++
    }
    printf("\n");
    
    
    /* ❌ MISTAKE 6: Forgetting to initialize */
    int count;
    // for (count; count < 5; count++) {  // ❌ count has random value!
    //     printf("%d ", count);
    // }
    
    count = 0;  // ✅ Initialize first!
    for (count; count < 5; count++) {
        printf("%d ", count);
    }
    printf("\n\n");
    
    
    printf("Loop mistakes avoided! You got this! 💪\n");
    
    return 0;
}

/*
 * Remember:
 * - Make sure loop variable changes in right direction
 * - No semicolon after for (...)
 * - Be careful with < vs <=
 * - Use the right loop variable (i, not some random name)
 * - Don't change loop variable inside the loop
 * - Always initialize variables
 */
