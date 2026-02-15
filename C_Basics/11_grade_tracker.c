/*
 * ========================================
 *   CHAPTER 11: 2D ARRAYS - PRACTICE ✏️
 * ========================================
 * 
 * Let's create a simple classroom grade tracker!
 * We'll store grades for multiple students and subjects.
 */

#include <stdio.h>

int main() {
    
    // 3 students, 3 subjects (Math, Science, English)
    int grades[3][3];
    
    printf("🎓 Classroom Grade Tracker\n");
    printf("==========================\n\n");
    
    // Input grades for each student
    for (int student = 0; student < 3; student++) {
        printf("Enter grades for Student %d:\n", student + 1);
        
        printf("  Math: ");
        scanf("%d", &grades[student][0]);
        
        printf("  Science: ");
        scanf("%d", &grades[student][1]);
        
        printf("  English: ");
        scanf("%d", &grades[student][2]);
        
        printf("\n");
    }
    
    // Display all grades in table format
    printf("\n📊 GRADE TABLE:\n");
    printf("=============================================\n");
    printf("Student    Math    Science    English    Avg\n");
    printf("=============================================\n");
    
    for (int i = 0; i < 3; i++) {
        int sum = 0;
        printf("   %d       ", i + 1);
        
        for (int j = 0; j < 3; j++) {
            printf("%3d      ", grades[i][j]);
            sum += grades[i][j];
        }
        
        float average = sum / 3.0;
        printf("%.1f\n", average);
    }
    
    // Find highest grade overall
    int highest = grades[0][0];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grades[i][j] > highest) {
                highest = grades[i][j];
            }
        }
    }
    
    printf("\n🏆 Highest grade in class: %d\n", highest);
    
    return 0;
}

/*
 * 💡 TRY THIS:
 * 
 * Enter grades like:
 * Student 1: 85, 90, 88
 * Student 2: 78, 92, 85
 * Student 3: 95, 87, 90
 * 
 * See how the 2D array stores and organizes data!
 * 
 * 🎯 CHALLENGE:
 * - Calculate average per subject (all students)
 * - Find which student has the highest average
 * - Add a 4th subject!
 */
