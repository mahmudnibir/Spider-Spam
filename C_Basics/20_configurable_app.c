/*
 * ========================================
 *   CHAPTER 20: PREPROCESSOR - PRACTICE ✏️
 * ========================================
 * 
 * Let's build a configurable program!
 */

#include <stdio.h>
#include <string.h>

// ========================================
// CONFIGURATION (Toggle features here!)
// ========================================
#define ENABLE_COLOR 1
#define ENABLE_STATS 1
#define ENABLE_DEBUG 0
#define MAX_STUDENTS 100
#define APP_VERSION "2.0"
#define APP_NAME "Student Manager"

// ========================================
// DEBUGGING MACROS
// ========================================
#if ENABLE_DEBUG
    #define DEBUG_PRINT(msg) printf("[DEBUG] %s\n", msg)
    #define DEBUG_VAR(var) printf("[DEBUG] %s = %d\n", #var, var)
#else
    #define DEBUG_PRINT(msg)  // Empty when debug off
    #define DEBUG_VAR(var)    // Empty when debug off
#endif

// ========================================
// COLOR MACROS
// ========================================
#if ENABLE_COLOR
    #define COLOR_RED "\033[1;31m"
    #define COLOR_GREEN "\033[1;32m"
    #define COLOR_YELLOW "\033[1;33m"
    #define COLOR_BLUE "\033[1;34m"
    #define COLOR_RESET "\033[0m"
#else
    #define COLOR_RED ""
    #define COLOR_GREEN ""
    #define COLOR_YELLOW ""
    #define COLOR_BLUE ""
    #define COLOR_RESET ""
#endif

// ========================================
// UTILITY MACROS
// ========================================
#define PRINT_HEADER(title) \
    printf("\n"); \
    printf(COLOR_BLUE "========================================\n"); \
    printf("  %s\n", title); \
    printf("========================================\n" COLOR_RESET)

#define PRINT_SUCCESS(msg) \
    printf(COLOR_GREEN "✅ %s\n" COLOR_RESET, msg)

#define PRINT_ERROR(msg) \
    printf(COLOR_RED "❌ %s\n" COLOR_RESET, msg)

#define PRINT_WARNING(msg) \
    printf(COLOR_YELLOW "⚠️  %s\n" COLOR_RESET, msg)

// Math macros
#define PERCENTAGE(part, total) (((float)(part) / (total)) * 100)
#define IS_PASSING(marks) ((marks) >= 50)
#define GRADE(marks) \
    ((marks) >= 90 ? 'A' : \
     (marks) >= 80 ? 'B' : \
     (marks) >= 70 ? 'C' : \
     (marks) >= 60 ? 'D' : \
     (marks) >= 50 ? 'E' : 'F')

// ========================================
// MAIN PROGRAM
// ========================================
int main() {
    
    // App header with version info
    printf("\n");
    printf(COLOR_BLUE "╔════════════════════════════════════════╗\n");
    printf("║  " APP_NAME "  v" APP_VERSION "         ║\n");
    printf("║  Compiled: " __DATE__ " " __TIME__ "  ║\n");
    printf("╚════════════════════════════════════════╝\n" COLOR_RESET);
    
    DEBUG_PRINT("Program started");
    
    // Student data
    int numStudents = 5;
    int marks[] = {85, 92, 67, 45, 78};
    char names[][20] = {"Alice", "Bob", "Charlie", "David", "Eve"};
    
    DEBUG_VAR(numStudents);
    
    // Display students
    PRINT_HEADER("Student Records");
    
    printf("%-15s %-10s %-10s %-10s\n", "Name", "Marks", "Grade", "Status");
    printf("-----------------------------------------------------\n");
    
    int passCount = 0;
    int totalMarks = 0;
    
    for (int i = 0; i < numStudents; i++) {
        char grade = GRADE(marks[i]);
        char *status = IS_PASSING(marks[i]) ? "PASS" : "FAIL";
        
        // Color based on pass/fail
        if (IS_PASSING(marks[i])) {
            printf(COLOR_GREEN);
            passCount++;
        } else {
            printf(COLOR_RED);
        }
        
        printf("%-15s %-10d %-10c %-10s\n",
               names[i], marks[i], grade, status);
        printf(COLOR_RESET);
        
        totalMarks += marks[i];
    }
    
    // Statistics section (conditional)
#if ENABLE_STATS
    PRINT_HEADER("Statistics");
    
    float average = (float)totalMarks / numStudents;
    float passPercentage = PERCENTAGE(passCount, numStudents);
    
    printf("Total Students:  %d\n", numStudents);
    printf("Average Marks:   %.2f\n", average);
    printf("Students Passed: %d (%.1f%%)\n", passCount, passPercentage);
    printf("Students Failed: %d\n", numStudents - passCount);
    
    if (passPercentage >= 80) {
        PRINT_SUCCESS("Excellent class performance!");
    } else if (passPercentage >= 60) {
        PRINT_WARNING("Good class performance");
    } else {
        PRINT_ERROR("Class needs improvement");
    }
#endif
    
    // App info
    PRINT_HEADER("Configuration");
    
    printf("Max Capacity:    %d students\n", MAX_STUDENTS);
    
#if ENABLE_COLOR
    printf("Color Output:    " COLOR_GREEN "Enabled\n" COLOR_RESET);
#else
    printf("Color Output:    Disabled\n");
#endif
    
#if ENABLE_STATS
    printf("Statistics:      " COLOR_GREEN "Enabled\n" COLOR_RESET);
#else
    printf("Statistics:      Disabled\n");
#endif
    
#if ENABLE_DEBUG
    printf("Debug Mode:      " COLOR_YELLOW "Enabled\n" COLOR_RESET);
    PRINT_WARNING("Debug mode is ON! Turn off for production");
#else
    printf("Debug Mode:      Disabled\n");
#endif
    
    // Platform info
    PRINT_HEADER("Build Information");
    printf("Compiled on:     %s %s\n", __DATE__, __TIME__);
    printf("Source file:     %s\n", __FILE__);
    printf("C Standard:      ");
#ifdef __STDC_VERSION__
    printf("%ld\n", __STDC_VERSION__);
#else
    printf("Pre-C99\n");
#endif
    
    DEBUG_PRINT("Program ending");
    
    printf("\n");
    PRINT_SUCCESS("Program completed successfully!");
    
    return 0;
}

/*
 * 💡 TRY THIS:
 * 
 * 1. Change configuration at top:
 *    - Set ENABLE_DEBUG to 1 (see debug messages)
 *    - Set ENABLE_COLOR to 0 (remove colors)
 *    - Set ENABLE_STATS to 0 (hide statistics)
 * 
 * 2. Recompile and run - see how behavior changes!
 * 
 * 3. Change MAX_STUDENTS to see capacity change
 * 
 * This is how real apps handle configurations!
 * 
 * 🎯 CHALLENGE:
 * - Add ENABLE_LOGGING feature
 * - Add different color schemes (THEME_DARK, THEME_LIGHT)
 * - Add multilingual support (LANGUAGE_EN, LANGUAGE_ES)
 * - Create release vs debug builds
 * 
 * Real-world usage:
 * - Debug vs Release builds
 * - Platform-specific code (Windows/Linux/Mac)
 * - Feature toggles
 * - API version handling
 */
