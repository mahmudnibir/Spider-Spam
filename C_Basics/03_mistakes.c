/*
 * COMMON MISTAKES: If-Else ❌
 */

#include <stdio.h>

int main() {
    
    /* ❌ MISTAKE 1: Using = instead of == */
    int x = 10;
    
    // if (x = 5) {  // ❌ WRONG! This ASSIGNS 5 to x
    if (x == 5) {    // ✅ Correct - double == for comparison
        printf("x is 5\n");
    }
    
    
    /* ❌ MISTAKE 2: Forgetting braces (can be tricky!) */
    int age = 15;
    
    // Without braces - only first line is in if!
    if (age >= 18)
        printf("You're adult\n");
        printf("You can vote\n");  // ❌ This ALWAYS runs!
    
    // ✅ Better - use braces
    if (age >= 18) {
        printf("You're adult\n");
        printf("You can vote\n");
    }
    
    
    /* ❌ MISTAKE 3: Semicolon after if */
    int score = 85;
    
    // if (score > 80);  // ❌ Semicolon here breaks it!
    // {
    //     printf("Good job!\n");  // This always runs
    // }
    
    if (score > 80) {  // ✅ No semicolon after if
        printf("Good job!\n");
    }
    
    
    /* ❌ MISTAKE 4: Wrong comparison operators */
    int num = 10;
    
    // Common mix-ups:
    // >  greater than
    // >= greater than or equal
    // <  less than
    // <= less than or equal
    // == equal to
    // != not equal to
    
    if (num >= 10) {  // ✅ This includes 10
        printf("num is 10 or more\n");
    }
    
    if (num > 10) {  // This does NOT include 10
        printf("num is more than 10\n");
    } else {
        printf("num is 10 or less\n");
    }
    
    
    /* ❌ MISTAKE 5: Confusing && and || */
    int a = 20;
    
    // && means AND (both must be true)
    if (a > 10 && a < 30) {  // ✅ True only if BOTH conditions true
        printf("a is between 10 and 30\n");
    }
    
    // || means OR (at least one must be true)
    if (a < 10 || a > 100) {  // True if EITHER condition true
        printf("a is outside range\n");
    } else {
        printf("a is in normal range\n");
    }
    
    
    printf("\nNow you know what to watch out for! 🎯\n");
    
    return 0;
}

/*
 * Remember:
 * - Use == for comparison, not =
 * - Always use { } braces with if/else
 * - No semicolon after if (condition)
 * - &&  = AND (both must be true)
 * - ||  = OR (one must be true)
 */
