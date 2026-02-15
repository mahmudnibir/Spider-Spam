/*
 * ========================================
 *   CHAPTER 18: COMMON DYNAMIC MEMORY MISTAKES ❌
 * ========================================
 * 
 * Dynamic memory is powerful but dangerous!
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    
    // ❌ MISTAKE 1: Not checking for NULL
    printf("=== Mistake 1: Not checking allocation ===\n");
    
    // ❌ Wrong: Assuming malloc always succeeds
    // int *ptr = (int*) malloc(1000000000 * sizeof(int));  // Huge!
    // ptr[0] = 5;  // CRASH if malloc failed!
    
    // ✅ Correct: Always check
    int *ptr = (int*) malloc(10 * sizeof(int));
    if (ptr == NULL) {
        printf("❌ Allocation failed!\n");
    } else {
        ptr[0] = 5;
        printf("✅ Allocation succeeded\n");
        free(ptr);
    }
    
    
    // ❌ MISTAKE 2: Memory leak (forgetting to free)
    printf("\n=== Mistake 2: Memory leak ===\n");
    
    // ❌ Wrong: Allocated but never freed
    for (int i = 0; i < 3; i++) {
        int *leak = (int*) malloc(100 * sizeof(int));
        // Use leak...
        // Forgot to free! Memory leaked! ❌
    }
    printf("❌ Memory leaked (3 allocations not freed)\n");
    
    // ✅ Correct: Always free
    for (int i = 0; i < 3; i++) {
        int *noLeak = (int*) malloc(100 * sizeof(int));
        if (noLeak != NULL) {
            // Use noLeak...
            free(noLeak);  // ✅ Freed!
        }
    }
    printf("✅ No memory leak (all freed)\n");
    
    
    // ❌ MISTAKE 3: Using freed memory
    printf("\n=== Mistake 3: Use after free ===\n");
    
    int *data = (int*) malloc(5 * sizeof(int));
    
    if (data != NULL) {
        data[0] = 10;
        printf("Before free: %d\n", data[0]);
        
        free(data);
        
        // ❌ Wrong: Using freed memory (dangling pointer)
        // printf("After free: %d\n", data[0]);  // Undefined behavior!
        // data[1] = 20;  // CRASH or corruption!
        
        printf("✅ Correctly avoided using freed memory\n");
    }
    
    
    // ❌ MISTAKE 4: Double free
    printf("\n=== Mistake 4: Double free ===\n");
    
    int *nums = (int*) malloc(3 * sizeof(int));
    
    if (nums != NULL) {
        nums[0] = 5;
        free(nums);
        // free(nums);  // ❌ ERROR! Already freed!
        printf("✅ Avoided double free\n");
    }
    
    
    // ❌ MISTAKE 5: Wrong size calculation
    printf("\n=== Mistake 5: Wrong size ===\n");
    
    // ❌ Wrong: Forgot sizeof(int)
    // int *wrong = (int*) malloc(10);  // Only 10 bytes, not 10 ints!
    // wrong[5] = 100;  // Out of bounds!
    
    // ✅ Correct: Use sizeof
    int *correct = (int*) malloc(10 * sizeof(int));  // 10 ints
    if (correct != NULL) {
        correct[5] = 100;  // ✅ Within bounds
        printf("✅ Correct size: %lu bytes for 10 ints\n", 10 * sizeof(int));
        free(correct);
    }
    
    
    // ❌ MISTAKE 6: Freeing stack memory
    printf("\n=== Mistake 6: Freeing stack variables ===\n");
    
    int stackVar = 42;
    int *stackPtr = &stackVar;
    
    // ❌ Wrong: Can't free stack memory!
    // free(stackPtr);  // CRASH! Only free malloc'd memory!
    
    // ✅ Only free dynamically allocated memory
    int *heapPtr = (int*) malloc(sizeof(int));
    if (heapPtr != NULL) {
        *heapPtr = 42;
        free(heapPtr);  // ✅ This is fine
        printf("✅ Only freed heap memory\n");
    }
    
    
    // ❌ MISTAKE 7: Forgetting null terminator for strings
    printf("\n=== Mistake 7: String allocation size ===\n");
    
    char name[] = "Hello";  // 6 chars including \0
    
    // ❌ Wrong: Not enough space for \0
    // char *copy = (char*) malloc(5 * sizeof(char));  // Only 5!
    // strcpy(copy, name);  // Buffer overflow! Needs 6!
    
    // ✅ Correct: +1 for null terminator
    char *copy = (char*) malloc(6 * sizeof(char));  // 5 + 1
    if (copy != NULL) {
        strcpy(copy, name);
        printf("✅ Copied: %s\n", copy);
        free(copy);
    }
    
    // Better: Use strlen
    copy = (char*) malloc((strlen(name) + 1) * sizeof(char));
    if (copy != NULL) {
        strcpy(copy, name);
        printf("✅ Better: %s\n", copy);
        free(copy);
    }
    
    
    // ❌ MISTAKE 8: Not updating pointer after realloc
    printf("\n=== Mistake 8: Ignoring realloc return ===\n");
    
    int *arr = (int*) malloc(3 * sizeof(int));
    
    if (arr != NULL) {
        arr[0] = 1;
        arr[1] = 2;
        arr[2] = 3;
        
        // ❌ Wrong: Ignoring return value
        // realloc(arr, 5 * sizeof(int));  // What if it moved?
        // arr[3] = 4;  // May crash!
        
        // ✅ Correct: Update pointer
        int *temp = (int*) realloc(arr, 5 * sizeof(int));
        if (temp != NULL) {
            arr = temp;  // ✅ Update pointer
            arr[3] = 4;
            arr[4] = 5;
            printf("✅ realloc pointer updated correctly\n");
            free(arr);
        } else {
            // realloc failed, original arr still valid
            free(arr);
        }
    }
    
    
    // ❌ MISTAKE 9: Accessing out of bounds
    printf("\n=== Mistake 9: Out of bounds access ===\n");
    
    int *small = (int*) malloc(3 * sizeof(int));
    
    if (small != NULL) {
        small[0] = 1;
        small[1] = 2;
        small[2] = 3;
        // small[10] = 99;  // ❌ Out of bounds! Undefined behavior!
        
        printf("✅ Stayed within bounds (0-2)\n");
        free(small);
    }
    
    return 0;
}

/*
 * 🎯 REMEMBER:
 * 
 * Critical rules for dynamic memory:
 * 
 * 1. Always check if malloc/calloc returns NULL
 * 2. Always free() allocated memory
 * 3. Never use memory after free()
 * 4. Never free() the same pointer twice
 * 5. Use sizeof() for correct size calculation
 * 6. Only free() heap memory (not stack)
 * 7. Add +1 for string null terminator
 * 8. Update pointer after realloc()
 * 9. Don't access out of bounds
 * 
 * Memory management pattern:
 * --------------------------
 * 1. Allocate: ptr = malloc(size);
 * 2. Check: if (ptr == NULL) { error }
 * 3. Use: ptr[0] = value;
 * 4. Free: free(ptr);
 * 5. Don't use: ptr[0] = value; ← WRONG!
 * 
 * Common causes of crashes:
 * ❌ Use after free
 * ❌ Double free
 * ❌ Buffer overflow
 * ❌ Null pointer dereference
 * 
 * With great power comes great responsibility! 💾
 */
