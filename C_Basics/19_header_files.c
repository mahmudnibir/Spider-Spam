/*
 * ========================================
 *   CHAPTER 19: HEADER FILES 📄
 * ========================================
 * 
 * Organize your code like a pro! 🎉
 * 
 * What are header files?
 * - Files with .h extension
 * - Contain function declarations, macros, constants
 * - Included using #include
 * - Help organize large projects
 * 
 * Why use header files?
 * - Code reusability
 * - Better organization
 * - Separate interface from implementation
 * - Share code across multiple files
 * 
 * Standard headers you've used:
 * #include <stdio.h>   → Standard Input/Output
 * #include <stdlib.h>  → Standard Library (malloc, etc.)
 * #include <string.h>  → String functions
 * #include <math.h>    → Math functions
 */

#include <stdio.h>

// ========================================
// IMAGINE THIS IS "mymath.h"
// ========================================
// Function declarations (prototypes)
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
float divide(float a, float b);

// ========================================
// IMAGINE THIS IS "mymath.c"
// ========================================
// Function definitions
int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

float divide(float a, float b) {
    if (b != 0) {
        return a / b;
    }
    return 0;
}

// ========================================
// MAIN PROGRAM
// ========================================
int main() {
    
    printf("=== Using Custom Functions ===\n");
    printf("(In real project, these would be in separate files)\n\n");
    
    int x = 15, y = 5;
    
    printf("Numbers: %d and %d\n\n", x, y);
    
    printf("Add:      %d + %d = %d\n", x, y, add(x, y));
    printf("Subtract: %d - %d = %d\n", x, y, subtract(x, y));
    printf("Multiply: %d * %d = %d\n", x, y, multiply(x, y));
    printf("Divide:   %d / %d = %.2f\n", x, y, divide(x, y));
    
    
    // 📄 HEADER FILE STRUCTURE
    printf("\n\n=== Header File Structure ===\n");
    printf("Typical project structure:\n");
    printf("  main.c        → Main program\n");
    printf("  mymath.h      → Function declarations\n");
    printf("  mymath.c      → Function definitions\n");
    printf("  mystring.h    → String utilities\n");
    printf("  mystring.c    → String implementations\n");
    
    
    // 📄 HOW TO CREATE HEADER
    printf("\n\n=== Creating Header File ===\n");
    printf("Step 1: Create mymath.h\n");
    printf("------\n");
    printf("#ifndef MYMATH_H\n");
    printf("#define MYMATH_H\n");
    printf("\n");
    printf("int add(int a, int b);\n");
    printf("int subtract(int a, int b);\n");
    printf("\n");
    printf("#endif\n");
    
    printf("\nStep 2: Create mymath.c\n");
    printf("------\n");
    printf("#include \"mymath.h\"\n");
    printf("\n");
    printf("int add(int a, int b) {\n");
    printf("    return a + b;\n");
    printf("}\n");
    
    printf("\nStep 3: Use in main.c\n");
    printf("------\n");
    printf("#include \"mymath.h\"\n");
    printf("\n");
    printf("int main() {\n");
    printf("    int result = add(5, 3);\n");
    printf("    return 0;\n");
    printf("}\n");
    
    
    // 📄 INCLUDE TYPES
    printf("\n\n=== Two Types of Include ===\n");
    printf("#include <stdio.h>     ← Angle brackets (system headers)\n");
    printf("#include \"mymath.h\"    ← Quotes (your headers)\n");
    
    
    // 📄 HEADER GUARDS
    printf("\n\n=== Header Guards (Important!) ===\n");
    printf("Prevent multiple inclusion:\n\n");
    printf("#ifndef MYHEADER_H   ← If not defined\n");
    printf("#define MYHEADER_H   ← Define it\n");
    printf("\n");
    printf("// Your code here\n");
    printf("\n");
    printf("#endif               ← End if\n");
    
    
    return 0;
}

/*
 * 🎯 KEY TAKEAWAYS:
 * 
 * Header file (.h):
 * - Function declarations (prototypes)
 * - Macro definitions
 * - Type definitions (struct, typedef)
 * - Constants
 * - NO function implementations (usually)
 * 
 * Implementation file (.c):
 * - Function definitions (implementations)
 * - Includes corresponding .h file
 * 
 * Why separate?
 * ✅ Reusability (use same functions in multiple files)
 * ✅ Organization (related functions grouped)
 * ✅ Compilation (change .c without recompiling everything)
 * ✅ Interface (users see declarations, not implementation)
 * 
 * Header structure:
 * -----------------
 * // myheader.h
 * #ifndef MYHEADER_H
 * #define MYHEADER_H
 * 
 * // Declarations
 * int myFunction(int x);
 * 
 * #endif
 * 
 * Always use header guards to prevent multiple inclusion!
 * 
 * Compilation with headers:
 * gcc main.c mymath.c -o program
 * 
 * Now try the example! 🚀
 */
