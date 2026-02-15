/*
 * ========================================
 *   CHAPTER 13: COMMON SWITCH-CASE MISTAKES ❌
 * ========================================
 * 
 * Switch can be tricky! Let's avoid common errors.
 */

#include <stdio.h>

int main() {
    
    // ❌ MISTAKE 1: Forgetting break statement
    printf("=== Mistake 1: Missing break ===\n");
    int x = 2;
    
    printf("Without break:\n");
    switch (x) {
        case 1:
            printf("One\n");
            // Missing break! Falls through!
        case 2:
            printf("Two\n");
            // Missing break! Falls through!
        case 3:
            printf("Three\n");
            break;
    }
    // This prints: Two AND Three! (Fall-through)
    
    printf("\nWith break:\n");
    switch (x) {
        case 1:
            printf("One\n");
            break;  // ✅ Stops here
        case 2:
            printf("Two\n");
            break;  // ✅ Stops here
        case 3:
            printf("Three\n");
            break;
    }
    // This prints only: Two ✅
    
    
    // ❌ MISTAKE 2: Using switch with strings
    printf("\n=== Mistake 2: Can't use strings ===\n");
    
    // ❌ Wrong: Can't switch on strings!
    // char name[] = "John";
    // switch (name) { ... }  // ERROR!
    
    // ✅ Correct: Use if-else for strings
    char name[20];
    printf("Enter name (John/Jane/Bob): ");
    scanf("%s", name);
    
    if (strcmp(name, "John") == 0) {
        printf("Hello John!\n");
    } else if (strcmp(name, "Jane") == 0) {
        printf("Hello Jane!\n");
    } else {
        printf("Hello stranger!\n");
    }
    
    
    // ❌ MISTAKE 3: Using switch with conditions
    printf("\n=== Mistake 3: Can't use conditions ===\n");
    int age = 25;
    
    // ❌ Wrong: switch can't check ranges!
    // switch (age) {
    //     case age >= 18:  // ERROR! Not allowed!
    //         printf("Adult");
    //         break;
    // }
    
    // ✅ Correct: Use if-else for conditions
    if (age >= 18) {
        printf("Adult (age %d)\n", age);
    } else {
        printf("Minor (age %d)\n", age);
    }
    
    
    // ❌ MISTAKE 4: Duplicate case values
    printf("\n=== Mistake 4: Duplicate cases ===\n");
    int num = 5;
    
    // ❌ Wrong: Same case value twice!
    // switch (num) {
    //     case 5:
    //         printf("Five A");
    //         break;
    //     case 5:  // ERROR! Duplicate!
    //         printf("Five B");
    //         break;
    // }
    
    // ✅ Correct: Each case value must be unique
    switch (num) {
        case 4:
            printf("Four\n");
            break;
        case 5:
            printf("Five\n");  // Only one case 5
            break;
        case 6:
            printf("Six\n");
            break;
    }
    
    
    // ❌ MISTAKE 5: Using float with switch
    printf("\n=== Mistake 5: Can't use float ===\n");
    
    // ❌ Wrong: switch doesn't work with float!
    // float price = 9.99;
    // switch (price) { ... }  // ERROR!
    
    // ✅ Correct: Use if-else for floats
    float price = 9.99;
    if (price < 10.0) {
        printf("Cheap item ($%.2f)\n", price);
    } else if (price < 50.0) {
        printf("Medium item ($%.2f)\n", price);
    } else {
        printf("Expensive item ($%.2f)\n", price);
    }
    
    
    // ❌ MISTAKE 6: Forgetting default case
    printf("\n=== Mistake 6: Missing default ===\n");
    int choice;
    printf("Enter 1 or 2: ");
    scanf("%d", &choice);
    
    // ⚠️ Without default: What if user enters 5?
    switch (choice) {
        case 1:
            printf("Option 1\n");
            break;
        case 2:
            printf("Option 2\n");
            break;
        // No default! Silent failure for other inputs!
    }
    
    // ✅ Better: Always add default
    switch (choice) {
        case 1:
            printf("Option 1\n");
            break;
        case 2:
            printf("Option 2\n");
            break;
        default:
            printf("Invalid option!\n");  // ✅ Handles all other cases
    }
    
    return 0;
}

/*
 * 🎯 REMEMBER:
 * 
 * 1. Always use break; (unless you want fall-through)
 * 2. Switch only works with: int, char (not string, float)
 * 3. Can't use conditions in case (like case x > 5)
 * 4. Each case value must be unique
 * 5. Use if-else for strings and floats
 * 6. Always add default: for safety
 * 
 * Switch = Clean menu navigation! 🔀
 */
