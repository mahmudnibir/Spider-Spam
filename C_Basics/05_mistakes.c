/*
 * COMMON MISTAKES: While Loops ❌
 */

#include <stdio.h>

int main() {
    
    /* ❌ MISTAKE 1: Infinite loop (forgot to update!) */
    // int i = 1;
    // while (i <= 5) {  // ❌ i never changes!
    //     printf("%d ", i);  // STUCK FOREVER!
    // }
    
    int i = 1;
    while (i <= 5) {  // ✅ Correct
        printf("%d ", i);
        i++;  // Update the variable!
    }
    printf("\n\n");
    
    
    /* ❌ MISTAKE 2: Condition never true */
    int x = 10;
    while (x < 5) {  // ❌ x is 10, always false!
        printf("This never runs\n");
    }
    printf("Loop skipped because condition was false\n\n");
    
    
    /* ❌ MISTAKE 3: Using = instead of == */
    int count = 0;
    // while (count = 5) {  // ❌ This ASSIGNS 5, doesn't compare!
    while (count == 5) {     // ✅ Correct - double ==
        printf("Count is 5\n");
        count++;
    }
    printf("Comparison done correctly\n\n");
    
    
    /* ❌ MISTAKE 4: Forgetting to read input in loop */
    int guess;
    int secret = 7;
    
    printf("Guess the number: ");
    scanf("%d", &guess);
    
    while (guess != secret) {
        printf("Wrong! Try again: ");
        scanf("%d", &guess);  // ✅ Must read new input!
        // If you forget this, you're stuck with same wrong guess!
    }
    printf("Correct!\n\n");
    
    
    /* ❌ MISTAKE 5: Semicolon after while */
    int j = 1;
    // while (j <= 3);  // ❌ Semicolon = infinite loop!
    // {
    //     printf("%d ", j);
    //     j++;
    // }
    
    while (j <= 3) {  // ✅ No semicolon
        printf("%d ", j);
        j++;
    }
    printf("\n\n");
    
    
    printf("While loops mastered! Keep going! 🚀\n");
    
    return 0;
}

/*
 * Remember:
 * - ALWAYS update the loop variable
 * - Check if condition can actually be true
 * - Use == for comparison, not =
 * - Update inputs inside the loop
 * - No semicolon after while (condition)
 */
