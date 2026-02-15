/*
 * COMMON MISTAKES: Pointers ❌
 */

#include <stdio.h>

int main() {
    
    /* ❌ MISTAKE 1: Confusing & and * */
    int num = 42;
    int *ptr = &num;
    
    // &num = address of num ✅
    // *ptr = value at ptr ✅
    // Don't mix them up!
    
    printf("Value: %d\n", *ptr);    // ✅ Value at pointer
    printf("Address: %p\n\n", ptr);  // ✅ Address in pointer
    
    
    /* ❌ MISTAKE 2: Using uninitialized pointer */
    // int *bad;  // ❌ Points to random location!
    // *bad = 5;  // ❌ DANGER! Could crash!
    
    int value = 5;
    int *good = &value;  // ✅ Points to real variable
    *good = 10;          // ✅ Safe
    printf("Safe pointer use: %d\n\n", value);
    
    
    /* ❌ MISTAKE 3: Forgetting * when declaring */
    int x = 10;
    // int ptr = &x;  // ❌ ptr is int, not pointer!
    int *ptrCorrect = &x;  // ✅ ptr is pointer to int
    
    
    /* ❌ MISTAKE 4: Double dereferencing */
    int a = 5;
    int *p = &a;
    
    // **p  // ❌ p is not pointer to pointer!
    printf("Value: %d\n", *p);  // ✅ Single *
    
    
    /* ❌ MISTAKE 5: Pointer to wrong type */
    int number = 100;
    // float *fPtr = &number;  // ❌ Types must match!
    int *iPtr = &number;       // ✅ int pointer for int variable
    
    
    /* ❌ MISTAKE 6: Forgetting & when passing to function */
    int val = 20;
    
    // swap(val);  // ❌ Function needs pointer!
    // swap(&val);  // ✅ Send address
    
    
    /* ❌ MISTAKE 7: Thinking pointer copies value */
    int original = 50;
    int *pointer = &original;
    
    *pointer = 100;  // Changes original, not a copy!
    printf("Original changed: %d\n\n", original);  // Shows 100
    
    
    printf("Pointer mistakes avoided! You're getting good! 💪\n");
    
    return 0;
}

/*
 * Remember:
 * - & gets address (like GPS coordinates)
 * - * gets value at address (what's at that location)
 * - Always initialize pointers
 * - Match pointer type with variable type
 * - Changing *pointer changes the original variable!
 * - Pointers are powerful but need care
 */
