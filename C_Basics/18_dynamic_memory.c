/*
 * ========================================
 *   CHAPTER 18: DYNAMIC MEMORY 💾
 * ========================================
 * 
 * Allocate memory at runtime! 🎉
 * 
 * Static memory (so far):
 * - Size fixed at compile time
 * - int arr[10];  ← Must know size beforehand
 * 
 * Dynamic memory:
 * - Size decided at runtime
 * - Allocate exactly what you need
 * - Can grow/shrink as needed
 * 
 * Key functions (from stdlib.h):
 * - malloc()  → Allocate memory
 * - calloc()  → Allocate and initialize to 0
 * - realloc() → Resize memory
 * - free()    → Release memory
 */

#include <stdio.h>
#include <stdlib.h>  // For malloc, free, etc.

int main() {
    
    // 💾 MALLOC: Allocate memory
    printf("=== malloc() - Memory Allocation ===\n");
    
    int n;
    printf("How many numbers? ");
    scanf("%d", &n);
    
    // Allocate memory for n integers
    int *arr = (int*) malloc(n * sizeof(int));
    
    // Check if allocation succeeded
    if (arr == NULL) {
        printf("❌ Memory allocation failed!\n");
        return 1;
    }
    
    // Use the allocated memory
    printf("Enter %d numbers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("You entered: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // Free memory when done (IMPORTANT!)
    free(arr);
    printf("✅ Memory freed\n");
    
    
    // 💾 CALLOC: Allocate and initialize
    printf("\n=== calloc() - Initialized Allocation ===\n");
    
    int size = 5;
    int *zeros = (int*) calloc(size, sizeof(int));
    
    if (zeros != NULL) {
        printf("calloc initialized to: ");
        for (int i = 0; i < size; i++) {
            printf("%d ", zeros[i]);  // All are 0
        }
        printf("\n");
        free(zeros);
    }
    
    
    // 💾 REALLOC: Resize memory
    printf("\n=== realloc() - Resize Memory ===\n");
    
    int *dynamic = (int*) malloc(3 * sizeof(int));
    
    if (dynamic != NULL) {
        dynamic[0] = 10;
        dynamic[1] = 20;
        dynamic[2] = 30;
        
        printf("Original (3 elements): ");
        for (int i = 0; i < 3; i++) {
            printf("%d ", dynamic[i]);
        }
        printf("\n");
        
        // Need more space? Resize it!
        dynamic = (int*) realloc(dynamic, 5 * sizeof(int));
        
        if (dynamic != NULL) {
            dynamic[3] = 40;
            dynamic[4] = 50;
            
            printf("After realloc (5 elements): ");
            for (int i = 0; i < 5; i++) {
                printf("%d ", dynamic[i]);
            }
            printf("\n");
            
            free(dynamic);
        }
    }
    
    
    // 💾 PRACTICAL EXAMPLE: Dynamic string
    printf("\n=== Dynamic String ===\n");
    
    char *name;
    int length;
    
    printf("Enter name length: ");
    scanf("%d", &length);
    getchar();
    
    name = (char*) malloc((length + 1) * sizeof(char));  // +1 for \0
    
    if (name != NULL) {
        printf("Enter name: ");
        fgets(name, length + 1, stdin);
        name[strcspn(name, "\n")] = 0;
        
        printf("Hello, %s!\n", name);
        free(name);
    }
    
    
    // 💾 COMPARING malloc vs calloc
    printf("\n=== malloc vs calloc ===\n");
    
    int *withMalloc = (int*) malloc(3 * sizeof(int));
    int *withCalloc = (int*) calloc(3, sizeof(int));
    
    printf("malloc (uninitialized): ");
    for (int i = 0; i < 3; i++) {
        printf("%d ", withMalloc[i]);  // Garbage values!
    }
    printf("\n");
    
    printf("calloc (initialized): ");
    for (int i = 0; i < 3; i++) {
        printf("%d ", withCalloc[i]);  // All zeros
    }
    printf("\n");
    
    free(withMalloc);
    free(withCalloc);
    
    return 0;
}

/*
 * 🎯 KEY TAKEAWAYS:
 * 
 * malloc(size):
 * - Allocates 'size' bytes
 * - Returns void* (cast to desired type)
 * - Memory contains garbage (not initialized)
 * - Returns NULL if allocation fails
 * 
 * calloc(count, size):
 * - Allocates count * size bytes
 * - Initializes all bytes to 0
 * - Safer than malloc (no garbage)
 * 
 * realloc(ptr, new_size):
 * - Resizes previously allocated memory
 * - Copies old data to new location
 * - Can grow or shrink
 * 
 * free(ptr):
 * - Releases allocated memory
 * - MUST be called to prevent memory leaks
 * - Don't use pointer after free!
 * 
 * Common pattern:
 * --------------
 * int *ptr = (int*) malloc(n * sizeof(int));
 * if (ptr == NULL) {
 *     // Handle error
 * }
 * // Use ptr
 * free(ptr);
 * 
 * Always remember:
 * ✅ Check for NULL after allocation
 * ✅ Free memory when done
 * ✅ Don't access freed memory
 * ✅ Don't free same memory twice
 * 
 * Now try the example! 🚀
 */
