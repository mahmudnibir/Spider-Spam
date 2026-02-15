/*
 * ========================================
 *   CHAPTER 16: BREAK & CONTINUE ⏭️
 * ========================================
 * 
 * Control your loops like a boss! 🎉
 * 
 * break: Exit the loop immediately (stop everything!)
 * continue: Skip to next iteration (skip this one, keep going!)
 * 
 * Think of it as:
 * - break = Emergency exit door 🚪
 * - continue = Skip button ⏭️
 */

#include <stdio.h>

int main() {
    
    // ⏭️ BREAK: Exit loop immediately
    printf("=== BREAK Statement ===\n");
    printf("Print 1-10, but stop at 6:\n");
    
    for (int i = 1; i <= 10; i++) {
        if (i == 6) {
            break;  // Exit loop when i is 6
        }
        printf("%d ", i);
    }
    printf("\n(Loop stopped at 6!)\n");
    
    
    // ⏭️ CONTINUE: Skip current iteration
    printf("\n=== CONTINUE Statement ===\n");
    printf("Print 1-10, but skip 5 and 7:\n");
    
    for (int i = 1; i <= 10; i++) {
        if (i == 5 || i == 7) {
            continue;  // Skip this iteration
        }
        printf("%d ", i);
    }
    printf("\n(Skipped 5 and 7!)\n");
    
    
    // ⏭️ REAL EXAMPLE: Search in array
    printf("\n=== Array Search with BREAK ===\n");
    int numbers[] = {10, 25, 30, 45, 50, 60};
    int searchFor = 45;
    int found = 0;
    
    for (int i = 0; i < 6; i++) {
        if (numbers[i] == searchFor) {
            printf("Found %d at index %d!\n", searchFor, i);
            found = 1;
            break;  // No need to search further!
        }
    }
    
    if (!found) {
        printf("%d not found!\n", searchFor);
    }
    
    
    // ⏭️ CONTINUE: Skip even numbers
    printf("\n=== Print Only Odd Numbers ===\n");
    printf("Numbers 1-20 (odd only):\n");
    
    for (int i = 1; i <= 20; i++) {
        if (i % 2 == 0) {
            continue;  // Skip even numbers
        }
        printf("%d ", i);
    }
    printf("\n");
    
    
    // ⏭️ BREAK in nested loops (only exits innermost loop)
    printf("\n=== Break in Nested Loops ===\n");
    
    for (int i = 1; i <= 3; i++) {
        printf("Outer loop: %d\n", i);
        
        for (int j = 1; j <= 5; j++) {
            if (j == 3) {
                break;  // Only exits inner loop, not outer!
            }
            printf("  Inner: %d\n", j);
        }
    }
    
    
    // ⏭️ CONTINUE in nested loops
    printf("\n=== Continue in Nested Loops ===\n");
    
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 4; j++) {
            if (j == 2) {
                continue;  // Skip when j is 2
            }
            printf("%d-%d ", i, j);
        }
        printf("\n");
    }
    
    
    // ⏭️ PRACTICAL: Input validation with break
    printf("\n=== Password Validator ===\n");
    int attempts = 0;
    int maxAttempts = 3;
    int correctPassword = 1234;
    int inputPassword;
    
    while (attempts < maxAttempts) {
        printf("Enter password: ");
        scanf("%d", &inputPassword);
        attempts++;
        
        if (inputPassword == correctPassword) {
            printf("✅ Access granted!\n");
            break;  // Exit on correct password
        } else {
            printf("❌ Wrong password! (%d/%d attempts)\n", attempts, maxAttempts);
        }
    }
    
    if (inputPassword != correctPassword) {
        printf("🔒 Account locked!\n");
    }
    
    
    // ⏭️ CONTINUE: Skip negative numbers
    printf("\n=== Sum of Positive Numbers ===\n");
    int data[] = {5, -2, 10, -8, 15, 20, -5};
    int sum = 0;
    
    for (int i = 0; i < 7; i++) {
        if (data[i] < 0) {
            continue;  // Skip negative numbers
        }
        sum += data[i];
    }
    
    printf("Sum of positive numbers: %d\n", sum);
    
    return 0;
}

/*
 * 🎯 KEY TAKEAWAYS:
 * 
 * BREAK:
 * ------
 * - Exits the entire loop immediately
 * - Used when: Found what you're looking for
 * - Used when: Hit error condition
 * - Used when: Reached limit
 * - Only exits innermost loop in nested loops
 * 
 * CONTINUE:
 * ---------
 * - Skips rest of current iteration
 * - Goes directly to next iteration
 * - Used when: Want to skip certain values
 * - Used when: Filtering data
 * - Loop continues running
 * 
 * Comparison:
 * -----------
 * for (int i = 1; i <= 5; i++) {
 *     if (i == 3) break;     // Stops at 3, prints: 1 2
 *     printf("%d ", i);
 * }
 * 
 * for (int i = 1; i <= 5; i++) {
 *     if (i == 3) continue;  // Skips 3, prints: 1 2 4 5
 *     printf("%d ", i);
 * }
 * 
 * Think of it:
 * break = "I'm done, get me out!" 🚪
 * continue = "Skip this one, next please!" ⏭️
 * 
 * Now try the example! 🚀
 */
