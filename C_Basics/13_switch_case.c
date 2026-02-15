/*
 * ========================================
 *   CHAPTER 13: SWITCH-CASE 🔀
 * ========================================
 * 
 * Cleaner way to handle multiple choices! 🎉
 * 
 * Instead of many if-else statements,
 * use switch when checking ONE variable against many values!
 * 
 * Syntax:
 * -------
 * switch (variable) {
 *     case value1:
 *         // code
 *         break;
 *     case value2:
 *         // code
 *         break;
 *     default:
 *         // code if no match
 * }
 */

#include <stdio.h>

int main() {
    
    // 🔀 BASIC SWITCH EXAMPLE
    int day = 3;
    
    printf("=== Day of Week ===\n");
    switch (day) {
        case 1:
            printf("Monday\n");
            break;
        case 2:
            printf("Tuesday\n");
            break;
        case 3:
            printf("Wednesday\n");
            break;
        case 4:
            printf("Thursday\n");
            break;
        case 5:
            printf("Friday\n");
            break;
        case 6:
            printf("Saturday\n");
            break;
        case 7:
            printf("Sunday\n");
            break;
        default:
            printf("Invalid day!\n");
    }
    
    
    // 🔀 MENU SYSTEM EXAMPLE
    printf("\n=== Simple Calculator ===\n");
    printf("1. Add\n");
    printf("2. Subtract\n");
    printf("3. Multiply\n");
    printf("4. Divide\n");
    printf("Choose operation (1-4): ");
    
    int choice;
    scanf("%d", &choice);
    
    int a = 10, b = 5;
    
    switch (choice) {
        case 1:
            printf("%d + %d = %d\n", a, b, a + b);
            break;
        case 2:
            printf("%d - %d = %d\n", a, b, a - b);
            break;
        case 3:
            printf("%d * %d = %d\n", a, b, a * b);
            break;
        case 4:
            if (b != 0) {
                printf("%d / %d = %d\n", a, b, a / b);
            } else {
                printf("Can't divide by zero!\n");
            }
            break;
        default:
            printf("Invalid choice!\n");
    }
    
    
    // 🔀 CHARACTER SWITCH
    char grade;
    printf("\nEnter your grade (A-F): ");
    scanf(" %c", &grade);  // Space before %c to skip whitespace
    
    switch (grade) {
        case 'A':
        case 'a':  // Handle both upper and lower case
            printf("Excellent! 🌟\n");
            break;
        case 'B':
        case 'b':
            printf("Good job! 👍\n");
            break;
        case 'C':
        case 'c':
            printf("Fair! 👌\n");
            break;
        case 'D':
        case 'd':
            printf("Needs improvement! 📚\n");
            break;
        case 'F':
        case 'f':
            printf("Failed! 😔\n");
            break;
        default:
            printf("Invalid grade!\n");
    }
    
    
    // 🔀 FALL-THROUGH EXAMPLE (no break)
    int month = 2;
    int days;
    
    switch (month) {
        case 1: case 3: case 5: case 7:
        case 8: case 10: case 12:
            days = 31;
            break;
        case 4: case 6: case 9: case 11:
            days = 30;
            break;
        case 2:
            days = 28;  // Not considering leap year
            break;
        default:
            printf("Invalid month!\n");
            return 1;
    }
    
    printf("\nMonth %d has %d days\n", month, days);
    
    return 0;
}

/*
 * 🎯 KEY TAKEAWAYS:
 * 
 * 1. switch checks ONE variable against multiple values
 * 2. Must use break; after each case (or it falls through)
 * 3. default: handles cases that don't match
 * 4. Works with: int, char (not float or string!)
 * 5. Can group cases together for same action
 * 
 * When to use switch vs if-else:
 * ------------------------------
 * ✅ Use switch: Checking one variable against exact values
 * ✅ Use if-else: Complex conditions, ranges, or comparisons
 * 
 * Example:
 * switch (x) { case 1: ... }  ✅ Good
 * if (x >= 1 && x <= 10) ...  ✅ Good (can't use switch for range)
 * 
 * Now try the example! 🚀
 */
