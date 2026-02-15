/*
 * ========================================
 *   CHAPTER 19: COMMON HEADER FILE MISTAKES ❌
 * ========================================
 * 
 * Headers are tricky! Let's avoid common errors.
 */

#include <stdio.h>

// ========================================
// ❌ MISTAKE 1: Missing header guards
// ========================================

// BAD: myheader.h without guards
/*
// myheader.h
void myFunction();
*/

// If included twice, you get redefinition errors!

// ✅ GOOD: myheader.h with guards
/*
#ifndef MYHEADER_H
#define MYHEADER_H

void myFunction();

#endif
*/


// ========================================
// ❌ MISTAKE 2: Including .c files
// ========================================

// ❌ Wrong: Including implementation
// #include "myfile.c"  // NEVER do this!

// ✅ Correct: Include only .h files
// #include "myfile.h"


// ========================================
// ❌ MISTAKE 3: Function definitions in header
// ========================================

// BAD: Definitions in header causes multiple definition errors
/*
// bad_header.h
int add(int a, int b) {  // ❌ Definition in header!
    return a + b;
}
*/

// ✅ GOOD: Only declarations in header
/*
// good_header.h
int add(int a, int b);  // ✅ Just declaration
*/

// Implementations go in .c file!


// ========================================
// ❌ MISTAKE 4: Circular includes
// ========================================

// BAD: a.h includes b.h, b.h includes a.h
/*
// a.h
#include "b.h"
void funcA();

// b.h
#include "a.h"
void funcB();
*/
// This creates infinite loop!

// ✅ SOLUTION: Forward declarations or restructure


// ========================================
// DEMONSTRATION
// ========================================

// Simulated header (normally in separate file)
#ifndef DEMO_H
#define DEMO_H

// ✅ Correct: Declarations only
int square(int x);
void printSquare(int x);

// Constants are fine in headers
#define PI 3.14159
#define MAX_SIZE 100

// Structs are fine in headers
typedef struct {
    int id;
    char name[50];
} Item;

#endif

// Implementation (normally in demo.c)
int square(int x) {
    return x * x;
}

void printSquare(int x) {
    printf("%d squared = %d\n", x, square(x));
}

int main() {
    
    printf("=== Header File Best Practices ===\n\n");
    
    // Using the functions
    printSquare(5);
    printSquare(10);
    
    // Using constants from header
    printf("\nConstants from header:\n");
    printf("PI = %.5f\n", PI);
    printf("MAX_SIZE = %d\n", MAX_SIZE);
    
    // Using struct from header
    Item item1;
    item1.id = 1;
    sprintf(item1.name, "Example");
    printf("\nStruct from header:\n");
    printf("ID: %d, Name: %s\n", item1.id, item1.name);
    
    
    // Common mistakes explained
    printf("\n\n=== Common Mistakes to Avoid ===\n");
    
    printf("\n❌ MISTAKE 1: No header guards\n");
    printf("   Problem: Multiple inclusion errors\n");
    printf("   Solution: Always use #ifndef guards\n");
    
    printf("\n❌ MISTAKE 2: Including .c files\n");
    printf("   Wrong: #include \"file.c\"\n");
    printf("   Right: #include \"file.h\"\n");
    
    printf("\n❌ MISTAKE 3: Defining functions in .h\n");
    printf("   Problem: Multiple definition errors\n");
    printf("   Solution: Declarations in .h, definitions in .c\n");
    
    printf("\n❌ MISTAKE 4: Not including own header\n");
    printf("   In myfile.c, always #include \"myfile.h\"\n");
    printf("   This ensures consistency!\n");
    
    printf("\n❌ MISTAKE 5: Wrong include path\n");
    printf("   System: #include <stdio.h>  (angle brackets)\n");
    printf("   Local:  #include \"myfile.h\"  (quotes)\n");
    
    printf("\n❌ MISTAKE 6: Global variables in header\n");
    printf("   Causes multiple definition if included multiple times\n");
    printf("   Use 'extern' keyword properly\n");
    
    
    printf("\n\n=== Correct Header Structure ===\n");
    printf("myfile.h:\n");
    printf("----------\n");
    printf("#ifndef MYFILE_H\n");
    printf("#define MYFILE_H\n");
    printf("\n");
    printf("// Function declarations\n");
    printf("int myFunction(int x);\n");
    printf("\n");
    printf("// Constants\n");
    printf("#define MAX 100\n");
    printf("\n");
    printf("// Structures\n");
    printf("typedef struct {\n");
    printf("    int value;\n");
    printf("} MyStruct;\n");
    printf("\n");
    printf("#endif\n");
    
    printf("\nmyfile.c:\n");
    printf("----------\n");
    printf("#include \"myfile.h\"\n");
    printf("\n");
    printf("// Function implementations\n");
    printf("int myFunction(int x) {\n");
    printf("    return x * 2;\n");
    printf("}\n");
    
    
    printf("\n\n=== Tips for Good Headers ===\n");
    printf("✅ Always use header guards\n");
    printf("✅ Include only necessary headers\n");
    printf("✅ Put declarations in .h, implementations in .c\n");
    printf("✅ Use meaningful names (MODULE_H)\n");
    printf("✅ Document what the header provides\n");
    printf("✅ Group related functions together\n");
    printf("✅ Keep headers focused (one purpose)\n");
    
    return 0;
}

/*
 * 🎯 REMEMBER:
 * 
 * Header files (.h):
 * ✅ Function declarations (prototypes)
 * ✅ Macro definitions (#define)
 * ✅ Type definitions (struct, typedef, enum)
 * ✅ Constants
 * ✅ extern variable declarations
 * 
 * ❌ NOT in headers:
 * ❌ Function implementations (usually)
 * ❌ Global variable definitions
 * ❌ Executable code
 * 
 * Header guard pattern:
 * ---------------------
 * #ifndef FILENAME_H
 * #define FILENAME_H
 * 
 * // Your declarations
 * 
 * #endif
 * 
 * Naming:
 * - Use uppercase for guard: MYHEADER_H
 * - Match filename: myheader.h → MYHEADER_H
 * 
 * Include paths:
 * - System: <stdio.h> → Searches system directories
 * - Local: "my.h" → Searches current directory first
 * 
 * Compilation:
 * gcc main.c file1.c file2.c -o program
 * 
 * Headers = Interface, .c files = Implementation! 📄
 */
