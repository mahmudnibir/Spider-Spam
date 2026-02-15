/*
 * ========================================
 *   CHAPTER 20: COMMON PREPROCESSOR MISTAKES ❌
 * ========================================
 * 
 * Preprocessor is powerful but dangerous!
 */

#include <stdio.h>

// ========================================
// ❌ MISTAKE 1: Not parenthesizing macro parameters
// ========================================

// ❌ Wrong: Missing parentheses
#define SQUARE_WRONG(x) x * x

// ✅ Correct: Properly parenthesized
#define SQUARE_RIGHT(x) ((x) * (x))

void mistake1() {
    printf("=== Mistake 1: Missing parentheses ===\n");
    
    // This goes wrong!
    int result1 = SQUARE_WRONG(2 + 3);  // Expands to: 2 + 3 * 2 + 3 = 11 (Wrong!)
    int result2 = SQUARE_RIGHT(2 + 3); // Expands to: ((2+3)*(2+3)) = 25 (Correct!)
    
    printf("SQUARE_WRONG(2+3) = %d (Expected 25, got wrong!)\n", result1);
    printf("SQUARE_RIGHT(2+3) = %d (Correct!)\n", result2);
}


// ========================================
// ❌ MISTAKE 2: Side effects in macros
// ========================================

#define MAX_WRONG(a, b) ((a) > (b) ? (a) : (b))

void mistake2() {
    printf("\n=== Mistake 2: Side effects ===\n");
    
    int x = 5, y = 10;
    
    // ❌ Wrong: x++ evaluated multiple times!
    int result = MAX_WRONG(x++, y);  // Expands to: ((x++) > (y) ? (x++) : (y))
    // x might increment twice!
    
    printf("After MAX_WRONG(x++, y): x = %d (Unexpected!)\n", x);
    printf("Use functions, not macros, when side effects possible\n");
}


// ========================================
// ❌ MISTAKE 3: Semicolon after macro
// ========================================

#define PRINT_MSG(msg) printf("%s\n", msg);  // ❌ Semicolon at end!

void mistake3() {
    printf("\n=== Mistake 3: Semicolon in macro ===\n");
    
    // This looks fine:
    PRINT_MSG("Hello");
    
    // But this breaks:
    // if (1)
    //     PRINT_MSG("Test");  // Expands to: printf(); ; (extra semicolon!)
    // else
    //     printf("Else");  // ERROR! else after single ;
    
    printf("Don't put semicolons in macro definitions\n");
    printf("Let the caller add the semicolon\n");
}


// ========================================
// ❌ MISTAKE 4: Using macros like functions
// ========================================

#define INCREMENT(x) x++

void mistake4() {
    printf("\n=== Mistake 4: Complex operations in macros ===\n");
    
    int arr[5] = {1, 2, 3, 4, 5};
    int i = 0;
    
    // ❌ Confusing: What does this do?
    // arr[INCREMENT(i)] = 10;  // Expands to: arr[i++] = 10
    
    printf("Macros aren't type-safe and can be confusing\n");
    printf("Use inline functions for better safety:\n");
    printf("  inline int increment(int *x) { return (*x)++; }\n");
}


// ========================================
// ❌ MISTAKE 5: Redefining without #undef
// ========================================

#define MAX_SIZE 100

void mistake5() {
    printf("\n=== Mistake 5: Redefining macros ===\n");
    
    // ❌ Wrong: Redefining without undef
    // #define MAX_SIZE 200  // Warning: MAX_SIZE redefined!
    
    // ✅ Correct:
    // #undef MAX_SIZE
    // #define MAX_SIZE 200
    
    printf("Current MAX_SIZE: %d\n", MAX_SIZE);
    printf("Always #undef before redefining\n");
}


// ========================================
// ❌ MISTAKE 6: Macro spanning multiple statements
// ========================================

// ❌ Wrong: No do-while wrapper
#define SWAP_WRONG(a, b) \
    int temp = a; \
    a = b; \
    b = temp;

// ✅ Correct: Use do-while
#define SWAP_RIGHT(a, b) \
    do { \
        int temp = a; \
        a = b; \
        b = temp; \
    } while(0)

void mistake6() {
    printf("\n=== Mistake 6: Multi-statement macros ===\n");
    
    int x = 5, y = 10;
    
    // Works fine here
    SWAP_RIGHT(x, y);
    printf("After SWAP_RIGHT: x=%d, y=%d\n", x, y);
    
    // But SWAP_WRONG breaks with if statements:
    // if (condition)
    //     SWAP_WRONG(a, b);  // Only first statement in if!
    // else
    //     ...  // ERROR!
    
    printf("Always wrap multi-statement macros in do-while(0)\n");
}


// ========================================
// ❌ MISTAKE 7: String literals in macros
// ========================================

#define PRINT_VALUE(x) printf("Value of x is: %d\n", x)  // ❌ Hardcoded string

void mistake7() {
    printf("\n=== Mistake 7: Not stringifying ===\n");
    
    int age = 25;
    PRINT_VALUE(age);  // Prints "Value of x is: 25" (wrong variable name!)
    
    // ✅ Better: Use stringification
    #define PRINT_VAR(x) printf("Value of " #x " is: %d\n", x)
    PRINT_VAR(age);  // Prints "Value of age is: 25" (correct!)
}


// ========================================
// ❌ MISTAKE 8: Comparing strings with ==
// ========================================

void mistake8() {
    printf("\n=== Mistake 8: Wrong string comparison ===\n");
    
    #define VERSION "1.0"
    
    // ❌ Wrong: This compares pointers, not strings!
    // if (VERSION == "1.0") { }  // Always false!
    
    // ✅ Correct: Use strcmp
    // if (strcmp(VERSION, "1.0") == 0) { }
    
    printf("Macros don't make string comparison easier\n");
    printf("Still need strcmp!\n");
}


// ========================================
// MAIN DEMONSTRATIONS
// ========================================

int main() {
    
    printf("⚠️  PREPROCESSOR PITFALLS ⚠️\n");
    printf("==============================\n");
    
    mistake1();
    mistake2();
    mistake3();
    mistake4();
    mistake5();
    mistake6();
    mistake7();
    mistake8();
    
    // Summary
    printf("\n\n=== BEST PRACTICES ===\n");
    printf("✅ Parenthesize all macro parameters\n");
    printf("✅ Parenthesize entire macro expression\n");
    printf("✅ Avoid side effects in macros\n");
    printf("✅ Don't put semicolons in definitions\n");
    printf("✅ Use do-while(0) for multi-statement macros\n");
    printf("✅ Use #undef before redefining\n");
    printf("✅ Consider inline functions instead\n");
    printf("✅ Use uppercase for macro names\n");
    
    printf("\n=== WHEN TO USE WHAT ===\n");
    printf("Macros:\n");
    printf("  ✅ Constants (#define PI 3.14)\n");
    printf("  ✅ Simple text substitution\n");
    printf("  ✅ Conditional compilation\n");
    printf("  ✅ Type-agnostic operations\n");
    
    printf("\nFunctions:\n");
    printf("  ✅ Complex logic\n");
    printf("  ✅ Type safety needed\n");
    printf("  ✅ Debugging required\n");
    printf("  ✅ Side effects present\n");
    
    return 0;
}

/*
 * 🎯 REMEMBER:
 * 
 * Macro Safety Rules:
 * 1. Parenthesize parameters: ((x) * (x))
 * 2. Parenthesize whole expression: (...entire macro...)
 * 3. Avoid side effects (++, --, function calls)
 * 4. No semicolon at end of definition
 * 5. Use do-while(0) for multi-statements
 * 6. #undef before redefining
 * 7. Use UPPERCASE names
 * 
 * Macro vs Function:
 * ------------------
 * Macro:
 * ✅ No overhead
 * ✅ Any type
 * ❌ No type checking
 * ❌ Hard to debug
 * ❌ Code bloat (copies code)
 * 
 * Function:
 * ✅ Type safe
 * ✅ Debuggable
 * ✅ One copy
 * ❌ Call overhead
 * ❌ Type specific
 * 
 * Modern C recommendation:
 * Use inline functions instead of macros when possible!
 * 
 * inline int square(int x) {
 *     return x * x;
 * }
 * 
 * Safer than macros, nearly as fast!
 * 
 * Preprocessor = Power tool, handle with care! ⚙️
 */
