/*
 * COMMON MISTAKES: Learn What NOT to Do! ❌
 * 
 * Don't worry - everyone makes these mistakes when learning!
 * This file shows common errors so you can avoid them.
 */

#include <stdio.h>

int main() {
    
    /* ❌ MISTAKE 1: Forgetting semicolon */
    // int age = 25     // ERROR! Missing semicolon
    int age = 25;       // ✅ Correct
    
    
    /* ❌ MISTAKE 2: Wrong data type for decimal */
    // int price = 9.99;  // ❌ Wrong! int can't store decimals
    float price = 9.99;   // ✅ Correct - use float for decimals
    
    
    /* ❌ MISTAKE 3: Using double quotes for char */
    // char grade = "A";  // ❌ Wrong! Double quotes are for strings
    char grade = 'A';     // ✅ Correct - single quotes for char
    
    
    /* ❌ MISTAKE 4: Not initializing variable */
    int score;            // Has random garbage value
    // printf("%d", score);  // ❌ Don't use before assigning!
    score = 100;          // ✅ First assign a value
    printf("Score: %d\n", score);  // ✅ Now it's safe to use
    
    
    /* ❌ MISTAKE 5: Wrong format specifier */
    int num = 42;
    // printf("%f", num);  // ❌ Wrong! %f is for float, not int
    printf("%d\n", num);   // ✅ Correct - use %d for int
    
    
    /* ❌ MISTAKE 6: Trying to change data type */
    int x = 10;
    // float x = 5.5;  // ❌ Can't redeclare same variable!
    x = 5;             // ✅ You can change the value though
    
    
    /* ❌ MISTAKE 7: Variable name starting with number */
    // int 1stPlace = 1;  // ❌ Can't start with number
    int first_place = 1;  // ✅ Use letters or underscore
    
    
    printf("\nAll mistakes fixed! You're learning! 🎉\n");
    
    return 0;
}

/*
 * Remember:
 * - Always use semicolon ;
 * - int for whole numbers, float for decimals
 * - Single quotes 'A' for char, double quotes "Hello" for strings
 * - Assign value before using variable
 * - Match format specifier with data type (%d for int, %f for float)
 */
