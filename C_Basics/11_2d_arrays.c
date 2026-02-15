/*
 * ========================================
 *   CHAPTER 11: 2D ARRAYS 📊
 * ========================================
 * 
 * Arrays inside arrays! Like a grid or table! 🎉
 * 
 * Think of it like:
 * - Excel spreadsheet (rows and columns)
 * - Chessboard (8x8 grid)
 * - Tic-tac-toe board (3x3 grid)
 * 
 * Syntax:
 * -------
 * int grid[3][4];  // 3 rows, 4 columns
 * grid[0][0] = 5;  // First row, first column
 * grid[2][3] = 9;  // Third row, fourth column
 */

#include <stdio.h>

int main() {
    
    // 📊 METHOD 1: Declare then assign
    int numbers[3][3];  // 3x3 grid
    
    numbers[0][0] = 1;  numbers[0][1] = 2;  numbers[0][2] = 3;
    numbers[1][0] = 4;  numbers[1][1] = 5;  numbers[1][2] = 6;
    numbers[2][0] = 7;  numbers[2][1] = 8;  numbers[2][2] = 9;
    
    printf("3x3 Grid:\n");
    printf("%d %d %d\n", numbers[0][0], numbers[0][1], numbers[0][2]);
    printf("%d %d %d\n", numbers[1][0], numbers[1][1], numbers[1][2]);
    printf("%d %d %d\n", numbers[2][0], numbers[2][1], numbers[2][2]);
    
    
    // 📊 METHOD 2: Initialize directly
    int matrix[2][3] = {
        {1, 2, 3},     // Row 0
        {4, 5, 6}      // Row 1
    };
    
    printf("\n2x3 Matrix:\n");
    for (int i = 0; i < 2; i++) {           // Loop through rows
        for (int j = 0; j < 3; j++) {       // Loop through columns
            printf("%d ", matrix[i][j]);
        }
        printf("\n");  // New line after each row
    }
    
    
    // 📊 REAL EXAMPLE: Student grades
    // 3 students, 4 subjects each
    int grades[3][4] = {
        {85, 90, 78, 92},  // Student 1's grades
        {88, 76, 95, 89},  // Student 2's grades
        {92, 85, 88, 94}   // Student 3's grades
    };
    
    printf("\n=== Student Grades ===\n");
    printf("Student 1: ");
    for (int j = 0; j < 4; j++) {
        printf("%d ", grades[0][j]);
    }
    
    // Calculate average for first student
    int sum = 0;
    for (int j = 0; j < 4; j++) {
        sum += grades[0][j];
    }
    float average = sum / 4.0;
    printf("\nAverage: %.2f\n", average);
    
    
    // 📊 TIC-TAC-TOE BOARD EXAMPLE
    char board[3][3] = {
        {'X', 'O', 'X'},
        {'O', 'X', 'O'},
        {'X', ' ', 'O'}
    };
    
    printf("\n=== Tic-Tac-Toe Board ===\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|");  // Column separator
        }
        printf("\n");
        if (i < 2) printf("---|---|---\n");  // Row separator
    }
    
    return 0;
}

/*
 * 🎯 KEY TAKEAWAYS:
 * 
 * 1. 2D array = array[rows][columns]
 * 2. Access element: array[row][col]
 * 3. First index is ALWAYS 0
 * 4. Use nested loops to traverse
 *    - Outer loop: rows (i)
 *    - Inner loop: columns (j)
 * 
 * Think of it as a table! 📊
 * 
 *     Col0  Col1  Col2
 * Row0  [1]   [2]   [3]
 * Row1  [4]   [5]   [6]
 * Row2  [7]   [8]   [9]
 * 
 * Now try the example! 🚀
 */
