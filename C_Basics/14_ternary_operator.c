/*
 * ========================================
 *   CHAPTER 14: TERNARY OPERATOR ⚡
 * ========================================
 * 
 * Short way to write if-else! 🎉
 * 
 * Instead of 5 lines, write just 1!
 * 
 * Syntax:
 * -------
 * condition ? valueIfTrue : valueIfFalse;
 * 
 * Example:
 * int max = (a > b) ? a : b;
 * 
 * Reads as: "Is a > b? If yes, use a, else use b"
 */

#include <stdio.h>

int main() {
    
    // ⚡ BASIC EXAMPLE: Find max of two numbers
    printf("=== Finding Maximum ===\n");
    
    int a = 10, b = 20;
    
    // Traditional if-else way:
    int max1;
    if (a > b) {
        max1 = a;
    } else {
        max1 = b;
    }
    printf("Using if-else: max = %d\n", max1);
    
    // Ternary way (shorter!):
    int max2 = (a > b) ? a : b;
    printf("Using ternary: max = %d\n", max2);
    
    
    // ⚡ PRINTING WITH TERNARY
    printf("\n=== Even or Odd ===\n");
    int num = 7;
    
    // Traditional way:
    if (num % 2 == 0) {
        printf("Traditional: Even\n");
    } else {
        printf("Traditional: Odd\n");
    }
    
    // Ternary way:
    printf("Ternary: %s\n", (num % 2 == 0) ? "Even" : "Odd");
    
    
    // ⚡ ASSIGNMENT WITH TERNARY
    printf("\n=== Grade Pass/Fail ===\n");
    int marks = 65;
    
    char result[10];
    strcpy(result, (marks >= 50) ? "Pass" : "Fail");
    printf("Result: %s (marks: %d)\n", result, marks);
    
    
    // ⚡ NESTED TERNARY (use carefully!)
    printf("\n=== Find Max of Three ===\n");
    int x = 15, y = 25, z = 20;
    
    // Find largest of three
    int largest = (x > y) ? ((x > z) ? x : z) : ((y > z) ? y : z);
    printf("Largest of %d, %d, %d = %d\n", x, y, z, largest);
    
    
    // ⚡ PRACTICAL EXAMPLE: Display absolute value
    printf("\n=== Absolute Value ===\n");
    int number = -42;
    int absolute = (number < 0) ? -number : number;
    printf("Absolute value of %d = %d\n", number, absolute);
    
    
    // ⚡ CHECKING AGE CATEGORY
    printf("\n=== Age Category ===\n");
    int age = 25;
    
    char *category = (age < 18) ? "Minor" : 
                     (age < 60) ? "Adult" : 
                     "Senior";
    printf("Age %d: %s\n", age, category);
    
    
    // ⚡ COMPARISON WITH TRADITIONAL IF-ELSE
    printf("\n=== Discount Calculator ===\n");
    float price = 1000.0;
    float discount;
    
    // Ternary way (1 line):
    discount = (price > 500) ? price * 0.10 : price * 0.05;
    printf("Price: $%.2f, Discount: $%.2f\n", price, discount);
    
    return 0;
}

/*
 * 🎯 KEY TAKEAWAYS:
 * 
 * Syntax: condition ? value_if_true : value_if_false
 * 
 * When to use ternary:
 * ✅ Simple if-else with assignments
 * ✅ Quick value selection
 * ✅ Making code more compact
 * 
 * When NOT to use ternary:
 * ❌ Complex conditions (hard to read)
 * ❌ Multiple statements in if/else
 * ❌ When it makes code confusing
 * 
 * Rule of thumb:
 * If it fits in one line and is clear → Use ternary ⚡
 * If it's getting complex → Use if-else 🔀
 * 
 * Examples:
 * max = (a > b) ? a : b;           ✅ Perfect!
 * (x>y)?((a>b)?((c>d)?...)):...    ❌ Too complex!
 * 
 * Now try the example! 🚀
 */
