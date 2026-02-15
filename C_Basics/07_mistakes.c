/*
 * COMMON MISTAKES: Functions ❌
 */

#include <stdio.h>

// Function prototypes
int multiply(int a, int b);
void printMessage();
int getValue();

int main() {
    
    /* ❌ MISTAKE 1: Forgetting to declare function */
    // If you use a function, declare it first at the top!
    
    
    /* ❌ MISTAKE 2: Forgetting to return value */
    // int bad() {  // Says it returns int
    //     int x = 5;  // ❌ But doesn't return anything!
    // }
    
    int result = multiply(3, 4);  // ✅ Correctly returns value
    printf("3 * 4 = %d\n\n", result);
    
    
    /* ❌ MISTAKE 3: Trying to use void function's "value" */
    printMessage();  // ✅ Just call it
    // int x = printMessage();  // ❌ void means no return value!
    
    
    /* ❌ MISTAKE 4: Wrong number of arguments */
    // multiply(5);  // ❌ Needs 2 numbers!
    // multiply(1, 2, 3);  // ❌ Too many!
    multiply(5, 6);  // ✅ Correct - exactly 2
    
    
    /* ❌ MISTAKE 5: Not using returned value */
    getValue();  // ❌ Returns a value but we ignore it
    int value = getValue();  // ✅ Store the returned value
    printf("Got value: %d\n\n", value);
    
    
    /* ❌ MISTAKE 6: Wrong return type */
    // int badFunction() {
    //     return 3.14;  // ❌ Says int but returns float!
    // }
    
    
    printf("Function mistakes avoided! Keep it up! 🎉\n");
    
    return 0;
}

// Function definitions

int multiply(int a, int b) {
    return a * b;  // ✅ Returns value
}

void printMessage() {
    printf("This is a message\n\n");
    // No return needed for void
}

int getValue() {
    return 42;  // ✅ Returns int as promised
}

/*
 * Remember:
 * - Declare functions at top (before main)
 * - If function says it returns something, it MUST return
 * - void = no return value
 * - Call function with correct number of arguments
 * - Store/use returned values
 * - Return type must match what function actually returns
 */
