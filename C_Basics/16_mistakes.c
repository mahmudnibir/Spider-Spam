/*
 * ========================================
 *   CHAPTER 16: COMMON BREAK/CONTINUE MISTAKES ❌
 * ========================================
 * 
 * These powerful tools need careful handling!
 */

#include <stdio.h>

int main() {
    
    // ❌ MISTAKE 1: Using break outside loop
    printf("=== Mistake 1: Break outside loop ===\n");
    
    int x = 5;
    
    // ❌ Wrong: break only works inside loops or switch!
    // if (x > 3) {
    //     break;  // ERROR! No loop to break from!
    // }
    
    // ✅ Correct: break inside loop
    for (int i = 1; i <= 5; i++) {
        if (i == 3) {
            break;  // ✅ Inside loop
        }
        printf("%d ", i);
    }
    printf("\n");
    
    
    // ❌ MISTAKE 2: Using continue outside loop
    printf("\n=== Mistake 2: Continue outside loop ===\n");
    
    // ❌ Wrong: continue only works inside loops!
    // if (x == 5) {
    //     continue;  // ERROR! No loop to continue!
    // }
    
    // ✅ Correct: continue inside loop
    for (int i = 1; i <= 5; i++) {
        if (i == 3) {
            continue;  // ✅ Inside loop
        }
        printf("%d ", i);
    }
    printf("\n");
    
    
    // ❌ MISTAKE 3: Break only exits innermost loop
    printf("\n=== Mistake 3: Break doesn't exit all loops ===\n");
    
    printf("With break (only exits inner loop):\n");
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            if (j == 2) {
                break;  // Only exits inner loop!
            }
            printf("(%d,%d) ", i, j);
        }
        printf("\n");
    }
    // Output: (1,1) (2,1) (3,1) - j never reaches 2
    
    // ✅ To exit all loops, use a flag
    printf("\nWith flag (exits all loops):\n");
    int exitAll = 0;
    for (int i = 1; i <= 3 && !exitAll; i++) {
        for (int j = 1; j <= 3; j++) {
            if (i == 2 && j == 2) {
                exitAll = 1;
                break;
            }
            printf("(%d,%d) ", i, j);
        }
        printf("\n");
    }
    
    
    // ❌ MISTAKE 4: Unreachable code after break
    printf("\n=== Mistake 4: Code after break ===\n");
    
    for (int i = 1; i <= 5; i++) {
        if (i == 3) {
            break;
            // printf("This never runs!");  // ❌ Unreachable!
        }
        printf("%d ", i);  // ✅ Reachable
    }
    printf("\n");
    
    
    // ❌ MISTAKE 5: Continue with wrong logic
    printf("\n=== Mistake 5: Wrong continue logic ===\n");
    
    // ❌ Wrong: Trying to skip even, but logic is backwards
    printf("Wrong logic: ");
    for (int i = 1; i <= 10; i++) {
        if (i % 2 == 0) {  // This IS even
            continue;      // Skip even
        }
        // Prints odd numbers (opposite of intention!)
    }
    printf("\n");
    
    // ✅ Correct: Fix the condition
    printf("Correct: ");
    for (int i = 1; i <= 10; i++) {
        if (i % 2 != 0) {  // If odd, skip
            continue;
        }
        printf("%d ", i);  // Print even
    }
    printf("(even numbers)\n");
    
    
    // ❌ MISTAKE 6: Forgetting increment with continue
    printf("\n=== Mistake 6: Infinite loop with continue ===\n");
    
    // ❌ Dangerous: continue before increment
    /*
    int count = 0;
    while (count < 5) {
        if (count == 2) {
            continue;  // Jumps back, count never increments!
        }
        printf("%d ", count);
        count++;  // Never reached when count==2
    }
    // INFINITE LOOP!
    */
    
    // ✅ Correct: increment before continue
    int count = 0;
    while (count < 5) {
        count++;  // ✅ Increment first!
        if (count == 3) {
            continue;  // Safe to skip now
        }
        printf("%d ", count);
    }
    printf("\n");
    
    
    // ❌ MISTAKE 7: Using break in switch incorrectly
    printf("\n=== Mistake 7: Break in switch ===\n");
    
    int choice = 2;
    
    // Without break in switch (fall through)
    printf("Without break in switch:\n");
    switch (choice) {
        case 1:
            printf("One ");
            // No break! Falls through!
        case 2:
            printf("Two ");
            // No break! Falls through!
        case 3:
            printf("Three ");
    }
    printf("\n");
    
    // ✅ Correct: Use break in switch
    printf("With break in switch:\n");
    switch (choice) {
        case 1:
            printf("One");
            break;  // ✅ Prevents fall-through
        case 2:
            printf("Two");
            break;  // ✅ Prevents fall-through
        case 3:
            printf("Three");
            break;
    }
    printf("\n");
    
    
    // ❌ MISTAKE 8: Overusing break/continue
    printf("\n=== Mistake 8: Overuse makes code messy ===\n");
    
    // ❌ Too many breaks/continues = confusing
    for (int i = 1; i <= 10; i++) {
        if (i == 2) continue;
        if (i == 4) continue;
        if (i == 6) continue;
        if (i == 8) break;
        printf("%d ", i);
    }
    printf("(confusing!)\n");
    
    // ✅ Better: Clear condition
    for (int i = 1; i <= 10; i++) {
        if (i % 2 != 0 && i < 8) {  // Clear: odd and less than 8
            printf("%d ", i);
        }
    }
    printf("(cleaner!)\n");
    
    return 0;
}

/*
 * 🎯 REMEMBER:
 * 
 * 1. break/continue only work inside loops (and switch for break)
 * 2. break exits only the innermost loop
 * 3. Code after break in same block is unreachable
 * 4. Watch for infinite loops with continue
 * 5. Increment before continue in while loops
 * 6. break is needed in switch to prevent fall-through
 * 7. Don't overuse - keep code readable
 * 
 * When to use:
 * - break: Found what you need, exit early
 * - continue: Skip invalid/unwanted items
 * 
 * When NOT to use:
 * - If simple condition works better
 * - If it makes code harder to understand
 * 
 * Clean, readable code > Clever tricks! 🎯
 */
