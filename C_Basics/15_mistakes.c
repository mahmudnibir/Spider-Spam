/*
 * ========================================
 *   CHAPTER 15: COMMON DO-WHILE MISTAKES ❌
 * ========================================
 * 
 * Do-while has unique pitfalls!
 */

#include <stdio.h>

int main() {
    
    // ❌ MISTAKE 1: Forgetting semicolon after while
    printf("=== Mistake 1: Missing semicolon ===\n");
    
    int i = 1;
    
    // ❌ Wrong: no semicolon
    /*
    do {
        printf("%d ", i);
        i++;
    } while (i <= 3)  // ERROR! Missing ;
    */
    
    // ✅ Correct: semicolon required!
    do {
        printf("%d ", i);
        i++;
    } while (i <= 3);  // ✅ Semicolon here!
    printf("\n");
    
    
    // ❌ MISTAKE 2: Confusing do-while with while
    printf("\n=== Mistake 2: Wrong choice of loop ===\n");
    
    int count = 10;
    
    // Using while when count is already > 5 (won't run)
    printf("While loop: ");
    while (count < 5) {
        printf("%d ", count);  // Never runs!
    }
    printf("(didn't run)\n");
    
    // Using do-while when count is > 5 (runs once unnecessarily)
    count = 10;
    printf("Do-while loop: ");
    do {
        printf("%d ", count);  // Runs once even though condition is false!
    } while (count < 5);
    printf("(ran once even though 10 < 5 is false)\n");
    
    // ✅ Lesson: Choose the right loop!
    // If it MUST run at least once → do-while
    // If it MIGHT not need to run → while
    
    
    // ❌ MISTAKE 3: Infinite loop (forgetting to update)
    printf("\n=== Mistake 3: Infinite loop ===\n");
    
    int x = 1;
    int loopCount = 0;
    
    // ❌ Wrong: x never changes!
    do {
        // printf("%d ", x);  // Would run forever!
        // Missing: x++;
        loopCount++;
        if (loopCount > 3) break;  // Safety break for demo
    } while (x <= 5);  // x is always 1, so always true!
    printf("Loop broke after %d iterations (would be infinite!)\n", loopCount);
    
    // ✅ Correct: update the variable
    x = 1;
    do {
        printf("%d ", x);
        x++;  // ✅ Don't forget this!
    } while (x <= 5);
    printf("\n");
    
    
    // ❌ MISTAKE 4: Wrong condition position
    printf("\n=== Mistake 4: Condition in wrong place ===\n");
    
    int num = 5;
    
    // ❌ Wrong: checking condition inside loop body
    do {
        if (num > 0) {  // This is NOT the loop condition!
            printf("%d ", num);
        }
        num--;
    } while (num > 0);  // This is the loop condition!
    printf("\n");
    
    // ✅ Understanding: condition check is AFTER the body
    
    
    // ❌ MISTAKE 5: Not handling first iteration specially
    printf("\n=== Mistake 5: Ignoring first run ===\n");
    
    int input;
    int validInput = 0;
    
    // ❌ Problem: Doesn't show message on first try
    // do {
    //     if (!validInput) {
    //         printf("Invalid! Try again: ");  // Shows even on first try!
    //     }
    //     scanf("%d", &input);
    //     validInput = (input >= 1 && input <= 10);
    // } while (!validInput);
    
    // ✅ Better: Handle first iteration properly
    printf("Enter number (1-10): ");
    do {
        scanf("%d", &input);
        if (input < 1 || input > 10) {
            printf("❌ Invalid! Enter 1-10: ");
        }
    } while (input < 1 || input > 10);
    printf("✅ Valid input: %d\n", input);
    
    
    // ❌ MISTAKE 6: Using do-while for counting loops
    printf("\n=== Mistake 6: Wrong use case ===\n");
    
    // ❌ Awkward: using do-while just to count
    int j = 0;
    do {
        printf("%d ", j);
        j++;
    } while (j < 5);
    printf("(works but awkward)\n");
    
    // ✅ Better: use for loop for counting
    for (int k = 0; k < 5; k++) {
        printf("%d ", k);
    }
    printf("(cleaner!)\n");
    
    // Use do-while when: MUST run at least once
    // Use for loop when: Counting iterations
    // Use while loop when: Might not run at all
    
    return 0;
}

/*
 * 🎯 REMEMBER:
 * 
 * 1. Always end with } while (condition);  ← Semicolon!
 * 2. Body runs at least ONCE, then checks condition
 * 3. Don't forget to update loop variable
 * 4. Choose right loop for the job:
 *    - do-while: Must run at least once
 *    - while: Might not run at all
 *    - for: Counting/iterating
 * 5. Perfect for menus and input validation
 * 
 * Common pattern for validation:
 * do {
 *     printf("Enter value: ");
 *     scanf("%d", &value);
 *     if (invalid) {
 *         printf("Try again!");
 *     }
 * } while (invalid);
 * 
 * Do-while = Execute first, ask questions later! 🔄
 */
