/*
 * ========================================
 *   CHAPTER 18: DYNAMIC MEMORY - PRACTICE ✏️
 * ========================================
 * 
 * Let's build a flexible gradebook!
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    
    printf("📓 Flexible Gradebook\n");
    printf("=====================\n\n");
    
    int numStudents;
    
    // Get number of students at runtime
    printf("How many students? ");
    scanf("%d", &numStudents);
    
    if (numStudents <= 0) {
        printf("❌ Invalid number!\n");
        return 1;
    }
    
    // Dynamically allocate arrays
    char **names = (char**) malloc(numStudents * sizeof(char*));
    int *rollNumbers = (int*) malloc(numStudents * sizeof(int));
    float *grades = (float*) malloc(numStudents * sizeof(float));
    
    // Check if allocation succeeded
    if (names == NULL || rollNumbers == NULL || grades == NULL) {
        printf("❌ Memory allocation failed!\n");
        return 1;
    }
    
    // Input student data
    printf("\nEnter student details:\n");
    printf("======================\n");
    
    for (int i = 0; i < numStudents; i++) {
        printf("\nStudent %d:\n", i + 1);
        
        // Allocate space for name
        names[i] = (char*) malloc(50 * sizeof(char));
        if (names[i] == NULL) {
            printf("❌ Memory allocation failed!\n");
            return 1;
        }
        
        printf("  Name: ");
        scanf(" %[^\n]", names[i]);  // Read line with spaces
        
        printf("  Roll No: ");
        scanf("%d", &rollNumbers[i]);
        
        printf("  Grade (0-100): ");
        scanf("%f", &grades[i]);
    }
    
    // Display all records
    printf("\n\n📊 GRADEBOOK\n");
    printf("================================================================\n");
    printf("%-5s %-20s %-12s %-10s %-10s\n", "No.", "Name", "Roll No", "Grade", "Status");
    printf("================================================================\n");
    
    float totalGrades = 0;
    int passCount = 0;
    
    for (int i = 0; i < numStudents; i++) {
        char *status = (grades[i] >= 50) ? "PASS" : "FAIL";
        
        printf("%-5d %-20s %-12d %-10.2f %-10s\n",
               i + 1, names[i], rollNumbers[i], grades[i], status);
        
        totalGrades += grades[i];
        if (grades[i] >= 50) {
            passCount++;
        }
    }
    
    printf("================================================================\n");
    
    // Calculate statistics
    float average = totalGrades / numStudents;
    float passPercentage = (passCount * 100.0) / numStudents;
    
    // Find highest and lowest
    float highest = grades[0];
    float lowest = grades[0];
    int topperIndex = 0;
    
    for (int i = 1; i < numStudents; i++) {
        if (grades[i] > highest) {
            highest = grades[i];
            topperIndex = i;
        }
        if (grades[i] < lowest) {
            lowest = grades[i];
        }
    }
    
    // Display statistics
    printf("\n📈 STATISTICS\n");
    printf("=================================\n");
    printf("Total Students:     %d\n", numStudents);
    printf("Average Grade:      %.2f\n", average);
    printf("Highest Grade:      %.2f\n", highest);
    printf("Lowest Grade:       %.2f\n", lowest);
    printf("Students Passed:    %d (%.1f%%)\n", passCount, passPercentage);
    printf("Students Failed:    %d\n", numStudents - passCount);
    printf("=================================\n");
    printf("🏆 Top Student:     %s (%.2f)\n", names[topperIndex], highest);
    
    // Option to expand (demonstration of realloc)
    char expand;
    printf("\nAdd more students? (y/n): ");
    scanf(" %c", &expand);
    
    if (expand == 'y' || expand == 'Y') {
        int additionalStudents;
        printf("How many more? ");
        scanf("%d", &additionalStudents);
        
        int newTotal = numStudents + additionalStudents;
        
        // Resize arrays
        names = (char**) realloc(names, newTotal * sizeof(char*));
        rollNumbers = (int*) realloc(rollNumbers, newTotal * sizeof(int));
        grades = (float*) realloc(grades, newTotal * sizeof(float));
        
        if (names == NULL || rollNumbers == NULL || grades == NULL) {
            printf("❌ Memory reallocation failed!\n");
        } else {
            printf("✅ Memory expanded! You can add %d more students.\n", additionalStudents);
            printf("(Feature demonstration - not implementing full input in this example)\n");
        }
    }
    
    // Free all allocated memory
    printf("\n🧹 Cleaning up memory...\n");
    for (int i = 0; i < numStudents; i++) {
        free(names[i]);  // Free each name
    }
    free(names);         // Free name array
    free(rollNumbers);   // Free roll number array
    free(grades);        // Free grades array
    
    printf("✅ All memory freed. Program ending.\n");
    
    return 0;
}

/*
 * 💡 TRY THIS:
 * 
 * Enter:
 * - 3 students
 * - Student 1: Alice, Roll 101, Grade 85
 * - Student 2: Bob, Roll 102, Grade 92
 * - Student 3: Charlie, Roll 103, Grade 67
 * 
 * See how:
 * - Arrays are sized based on user input
 * - Memory is allocated dynamically
 * - Statistics are calculated
 * - Memory is properly freed
 * 
 * 🎯 CHALLENGE:
 * - Add search by name or roll number
 * - Sort students by grade
 * - Save/load to file
 * - Add multiple subjects per student
 */
