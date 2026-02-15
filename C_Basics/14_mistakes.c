/*
 * ========================================
 *   CHAPTER 14: COMMON TERNARY MISTAKES ❌
 * ========================================
 * 
 * Ternary is powerful but easy to misuse!
 */

#include <stdio.h>

int main() {
    
    // ❌ MISTAKE 1: Over-nesting (too complex)
    printf("=== Mistake 1: Too many nested ternaries ===\n");
    int x = 5;
    
    // ❌ Wrong: Hard to read!
    int bad = (x > 10) ? 100 : (x > 5) ? 50 : (x > 0) ? 10 : (x > -5) ? -10 : -100;
    printf("Bad (confusing): %d\n", bad);
    
    // ✅ Better: Use if-else for complex logic
    int good;
    if (x > 10) {
        good = 100;
    } else if (x > 5) {
        good = 50;
    } else if (x > 0) {
        good = 10;
    } else if (x > -5) {
        good = -10;
    } else {
        good = -100;
    }
    printf("Good (clear): %d\n", good);
    
    
    // ❌ MISTAKE 2: Using ternary for side effects
    printf("\n=== Mistake 2: Ternary for actions ===\n");
    int score = 85;
    
    // ❌ Wrong: Don't use ternary just for printf!
    (score >= 50) ? printf("Pass (bad style)\n") : printf("Fail (bad style)\n");
    
    // ✅ Correct: Use if-else for actions
    if (score >= 50) {
        printf("Pass (good style)\n");
    } else {
        printf("Fail (good style)\n");
    }
    
    
    // ❌ MISTAKE 3: Type mismatch in ternary
    printf("\n=== Mistake 3: Mismatched types ===\n");
    int age = 20;
    
    // ⚠️ Careful: Both values should be same type
    // int wrong = (age >= 18) ? 1 : "Minor";  // ERROR! int vs string
    
    // ✅ Correct: Both values same type
    int rightInt = (age >= 18) ? 1 : 0;
    char *rightStr = (age >= 18) ? "Adult" : "Minor";
    printf("Using int: %d\n", rightInt);
    printf("Using string: %s\n", rightStr);
    
    
    // ❌ MISTAKE 4: Forgetting parentheses
    printf("\n=== Mistake 4: Missing parentheses ===\n");
    int a = 5, b = 10;
    
    // ❌ Confusing without parentheses
    int result1 = a > b ? a : b + 1;  // Is it (a > b) ? a : (b + 1)?
    
    // ✅ Clear with parentheses
    int result2 = (a > b) ? a : (b + 1);
    printf("Result: %d\n", result2);
    
    
    // ❌ MISTAKE 5: Using ternary when not assigning
    printf("\n=== Mistake 5: Wasting ternary result ===\n");
    int num = 10;
    
    // ❌ Wrong: Result is not used!
    (num > 5) ? 100 : 50;  // This does nothing!
    
    // ✅ Correct: Assign or use the result
    int value = (num > 5) ? 100 : 50;
    printf("Value: %d\n", value);
    
    // Or use it directly:
    printf("Direct use: %d\n", (num > 5) ? 100 : 50);
    
    
    // ❌ MISTAKE 6: Trying to modify variables
    printf("\n=== Mistake 6: Multiple statements ===\n");
    int count = 5;
    
    // ❌ Wrong: Can't do multiple things
    // (count > 0) ? (count++, printf("Yes")) : printf("No");  // Ugly!
    
    // ✅ Correct: Use if-else for multiple actions
    if (count > 0) {
        count++;
        printf("Count incremented: %d\n", count);
    } else {
        printf("Count is zero or negative\n");
    }
    
    
    // ✅ GOOD USE CASES
    printf("\n=== ✅ Good Ternary Usage ===\n");
    
    int n = 42;
    
    // Finding max/min
    int max = (a > b) ? a : b;
    printf("Max: %d\n", max);
    
    // Simple flag
    int isPositive = (n > 0) ? 1 : 0;
    printf("Is positive: %d\n", isPositive);
    
    // Quick display
    printf("Number is %s\n", (n % 2 == 0) ? "even" : "odd");
    
    // Absolute value
    int absolute = (n < 0) ? -n : n;
    printf("Absolute: %d\n", absolute);
    
    return 0;
}

/*
 * 🎯 REMEMBER:
 * 
 * Use ternary for:
 * ✅ Simple value assignments
 * ✅ Quick conditional values
 * ✅ One-liner decisions
 * 
 * Avoid ternary for:
 * ❌ Complex nested conditions
 * ❌ Multiple statements
 * ❌ Side effects (printf, etc.)
 * ❌ When it hurts readability
 * 
 * Golden Rule:
 * If you need to think twice to understand it,
 * use if-else instead! 
 * 
 * Ternary = Quick and clean! ⚡
 */
