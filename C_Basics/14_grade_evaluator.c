/*
 * ========================================
 *   CHAPTER 14: TERNARY OPERATOR - PRACTICE ✏️
 * ========================================
 * 
 * Let's build a simple grade evaluator!
 */

#include <stdio.h>

int main() {
    
    int marks;
    
    printf("🎓 Grade Evaluator\n");
    printf("==================\n\n");
    
    printf("Enter your marks (0-100): ");
    scanf("%d", &marks);
    
    // Validate input
    if (marks < 0 || marks > 100) {
        printf("❌ Invalid marks! Must be 0-100.\n");
        return 1;
    }
    
    // Determine pass/fail using ternary
    char *result = (marks >= 40) ? "PASS ✅" : "FAIL ❌";
    
    // Determine grade using nested ternary
    char grade = (marks >= 90) ? 'A' :
                 (marks >= 80) ? 'B' :
                 (marks >= 70) ? 'C' :
                 (marks >= 60) ? 'D' :
                 (marks >= 40) ? 'E' : 'F';
    
    // Determine performance message
    char *message = (marks >= 90) ? "Outstanding! 🌟" :
                    (marks >= 75) ? "Very Good! 👍" :
                    (marks >= 60) ? "Good! 😊" :
                    (marks >= 40) ? "Average 👌" :
                    "Need More Study 📚";
    
    // Calculate percentage
    float percentage = marks;  // Out of 100
    
    // Check if distinction (above 85%)
    char *distinction = (marks >= 85) ? "(With Distinction)" : "";
    
    // Display results
    printf("\n📊 RESULT CARD\n");
    printf("=====================================\n");
    printf("Marks:       %d / 100\n", marks);
    printf("Percentage:  %.1f%%\n", percentage);
    printf("Grade:       %c\n", grade);
    printf("Result:      %s %s\n", result, distinction);
    printf("Performance: %s\n", message);
    printf("=====================================\n");
    
    // Bonus points eligibility (using ternary)
    int bonusPoints = (marks >= 95) ? 5 : 
                      (marks >= 85) ? 3 : 
                      (marks >= 75) ? 1 : 0;
    
    if (bonusPoints > 0) {
        printf("\n🎁 Bonus Points: +%d\n", bonusPoints);
        printf("   Final Marks: %d\n", marks + bonusPoints);
    }
    
    return 0;
}

/*
 * 💡 TRY THIS:
 * 
 * Run and enter:
 * - 95 (See A grade with distinction and bonus)
 * - 75 (See C grade with small bonus)
 * - 35 (See F grade with fail status)
 * 
 * Notice how ternary makes decisions compact and readable!
 * 
 * 🎯 CHALLENGE:
 * - Add subject name input
 * - Calculate GPA (Grade Point Average)
 * - Add attendance percentage check (fail if below 75%)
 */
