/*
 * ========================================
 *   CHAPTER 11: COMMON 2D ARRAY MISTAKES ❌
 * ========================================
 * 
 * 2D arrays can be confusing! Let's fix common errors.
 */

#include <stdio.h>

int main() {
    
    // ❌ MISTAKE 1: Wrong index order
    printf("=== Mistake 1: Wrong index order ===\n");
    int matrix[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };
    
    // ❌ Wrong: matrix[column][row]
    // printf("%d", matrix[2][1]);  // Out of bounds! Only 2 rows!
    
    // ✅ Correct: matrix[row][column]
    printf("Element at row 1, col 2: %d\n", matrix[1][2]);  // = 6
    // Remember: [rows][columns] always!
    
    
    // ❌ MISTAKE 2: Wrong loop limits
    printf("\n=== Mistake 2: Wrong loop limits ===\n");
    int grid[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    
    // ❌ Wrong: swapped limits
    // for (int i = 0; i < 4; i++) {      // 4 is columns!
    //     for (int j = 0; j < 3; j++) {  // 3 is rows!
    //         printf("%d ", grid[i][j]); // Out of bounds!
    //     }
    // }
    
    // ✅ Correct: match array dimensions
    printf("Correct traversal:\n");
    for (int i = 0; i < 3; i++) {      // 3 rows
        for (int j = 0; j < 4; j++) {  // 4 columns
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
    
    
    // ❌ MISTAKE 3: Forgetting nested loop for input
    printf("\n=== Mistake 3: Input without nested loops ===\n");
    int numbers[2][2];
    
    // ❌ Wrong: only one loop
    // for (int i = 0; i < 2; i++) {
    //     scanf("%d", &numbers[i]);  // This won't work!
    // }
    
    // ✅ Correct: nested loops
    printf("Enter 4 numbers (2x2):\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("  [%d][%d]: ", i, j);
            scanf("%d", &numbers[i][j]);
        }
    }
    
    printf("Your array:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", numbers[i][j]);
        }
        printf("\n");
    }
    
    
    // ❌ MISTAKE 4: Confusing dimensions
    printf("\n=== Mistake 4: Dimension confusion ===\n");
    
    // int wrong[3];        // This is 1D array with 3 elements
    // int right[3][1];     // This is 2D array: 3 rows, 1 column
    // They're DIFFERENT!
    
    int arr1D[3] = {1, 2, 3};
    int arr2D[3][1] = {{1}, {2}, {3}};
    
    printf("1D array: %d %d %d\n", arr1D[0], arr1D[1], arr1D[2]);
    printf("2D array: %d %d %d\n", arr2D[0][0], arr2D[1][0], arr2D[2][0]);
    
    
    // ❌ MISTAKE 5: Incorrect initialization
    printf("\n=== Mistake 5: Wrong initialization ===\n");
    
    // ❌ Wrong: missing braces
    // int bad[2][2] = {1, 2, 3, 4};  // Works but confusing!
    
    // ✅ Correct: clear structure
    int good[2][2] = {
        {1, 2},   // Row 0
        {3, 4}    // Row 1
    };
    printf("Properly initialized:\n");
    printf("%d %d\n", good[0][0], good[0][1]);
    printf("%d %d\n", good[1][0], good[1][1]);
    
    return 0;
}

/*
 * 🎯 REMEMBER:
 * 
 * 1. Always: array[row][column], not [column][row]
 * 2. Loop limits must match dimensions
 * 3. Use nested loops for 2D operations
 * 4. 1D and 2D arrays are different!
 * 5. Initialize with nested braces for clarity
 * 
 * Think: [how many rows][how many columns] 📊
 */
