/*
 * ========================================
 *   CHAPTER 20: PREPROCESSOR DIRECTIVES ⚙️
 * ========================================
 * 
 * Control compilation before it even starts! 🎉
 * 
 * What is the preprocessor?
 * - Runs BEFORE actual compilation
 * - Processes directives (lines starting with #)
 * - Does text substitution, file inclusion, conditional compilation
 * 
 * Common directives:
 * #include   → Include files
 * #define    → Define constants/macros
 * #undef     → Undefine macro
 * #ifdef     → If defined
 * #ifndef    → If not defined
 * #if        → If condition
 * #else      → Else
 * #elif      → Else if
 * #endif     → End if
 * #pragma    → Compiler-specific commands
 */

#include <stdio.h>

// ⚙️ #define - Define constants
#define PI 3.14159
#define MAX_SIZE 100
#define GREETING "Hello, World!"

// ⚙️ #define - Macros (like mini functions)
#define SQUARE(x) ((x) * (x))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(x) ((x) < 0 ? -(x) : (x))

// ⚙️ Conditional compilation
#define DEBUG 1
#define VERSION 2

int main() {
    
    // Using defined constants
    printf("=== Using #define Constants ===\n");
    printf("PI = %.5f\n", PI);
    printf("MAX_SIZE = %d\n", MAX_SIZE);
    printf("GREETING = %s\n", GREETING);
    
    
    // Using macros
    printf("\n=== Using Macros ===\n");
    int x = 5;
    printf("SQUARE(%d) = %d\n", x, SQUARE(x));
    printf("MAX(10, 20) = %d\n", MAX(10, 20));
    printf("MIN(10, 20) = %d\n", MIN(10, 20));
    printf("ABS(-42) = %d\n", ABS(-42));
    
    
    // Conditional compilation with #ifdef
    printf("\n=== Conditional Compilation ===\n");
    
#ifdef DEBUG
    printf("Debug mode is ON\n");
    printf("Current values: x = %d\n", x);
#endif
    
#ifndef RELEASE
    printf("This is not a release build\n");
#endif
    
    
    // Conditional compilation with #if
#if VERSION == 1
    printf("Running Version 1\n");
#elif VERSION == 2
    printf("Running Version 2\n");
#else
    printf("Unknown Version\n");
#endif
    
    
    // Predefined macros
    printf("\n=== Predefined Macros ===\n");
    printf("File: %s\n", __FILE__);
    printf("Line: %d\n", __LINE__);
    printf("Date: %s\n", __DATE__);
    printf("Time: %s\n", __TIME__);
    
    
    // Multi-line macros
#define PRINT_TITLE(title) \
    printf("================\n"); \
    printf("%s\n", title); \
    printf("================\n")
    
    printf("\n");
    PRINT_TITLE("Multi-line Macro");
    
    
    // Using #undef
    printf("\n=== Using #undef ===\n");
#define TEMP 100
    printf("TEMP defined as %d\n", TEMP);
#undef TEMP
#define TEMP 200
    printf("TEMP redefined as %d\n", TEMP);
    
    
    // Conditional features
    printf("\n=== Conditional Features ===\n");
    
#define FEATURE_LOGIN 1
#define FEATURE_PAYMENT 0
    
#if FEATURE_LOGIN
    printf("✅ Login feature enabled\n");
#else
    printf("❌ Login feature disabled\n");
#endif
    
#if FEATURE_PAYMENT
    printf("✅ Payment feature enabled\n");
#else
    printf("❌ Payment feature disabled\n");
#endif
    
    
    // String concatenation
#define CONCAT(a, b) a##b
    int xy = 100;
    printf("\n=== Token Pasting (##) ===\n");
    printf("CONCAT(x, y) accesses variable 'xy': %d\n", CONCAT(x, y));
    
    
    // Stringification
#define TO_STRING(x) #x
    printf("\n=== Stringification (#) ===\n");
    printf("TO_STRING(Hello) = %s\n", TO_STRING(Hello));
    printf("TO_STRING(123) = %s\n", TO_STRING(123));
    
    return 0;
}

/*
 * 🎯 KEY TAKEAWAYS:
 * 
 * Preprocessor Directives:
 * ------------------------
 * #include "file.h"    → Include header file
 * #define NAME value   → Define constant
 * #define MACRO(x) ... → Define macro
 * #undef NAME          → Undefine
 * #ifdef NAME          → If defined
 * #ifndef NAME         → If not defined
 * #if condition        → If condition true
 * #elif condition      → Else if
 * #else                → Else
 * #endif               → End conditional
 * 
 * Predefined Macros:
 * ------------------
 * __FILE__    → Current filename
 * __LINE__    → Current line number
 * __DATE__    → Compilation date
 * __TIME__    → Compilation time
 * __STDC__    → 1 if standard C
 * 
 * Macro Best Practices:
 * ---------------------
 * ✅ Use UPPERCASE for macros
 * ✅ Parenthesize parameters: ((x) * (x))
 * ✅ Use for simple operations only
 * ✅ Consider inline functions for complex logic
 * 
 * When to use:
 * - Constants that never change
 * - Conditional compilation (debug/release)
 * - Platform-specific code
 * - Feature toggles
 * 
 * Macro vs Function:
 * ------------------
 * Macro:
 * ✅ No function call overhead
 * ✅ Works with any type
 * ❌ No type checking
 * ❌ Can cause unexpected behavior
 * 
 * Function:
 * ✅ Type safe
 * ✅ Easier to debug
 * ❌ Function call overhead
 * 
 * Use macros for constants and simple substitutions,
 * functions for everything else!
 * 
 * Now try the example! 🚀
 */
