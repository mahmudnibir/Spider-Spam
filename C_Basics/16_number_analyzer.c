/*
 * ========================================
 *   CHAPTER 16: BREAK & CONTINUE - PRACTICE ✏️
 * ========================================
 * 
 * Let's build a number analyzer with filters!
 */

#include <stdio.h>

int main() {
    
    printf("🔢 Number Analyzer\n");
    printf("==================\n\n");
    
    int numbers[15];
    
    // Input 15 numbers
    printf("Enter 15 numbers (press Enter after each):\n");
    for (int i = 0; i < 15; i++) {
        printf("%2d: ", i + 1);
        scanf("%d", &numbers[i]);
    }
    
    // Analysis 1: Find first number divisible by 7
    printf("\n📊 ANALYSIS 1: First number divisible by 7\n");
    int foundDivisible = 0;
    
    for (int i = 0; i < 15; i++) {
        if (numbers[i] % 7 == 0) {
            printf("Found: %d at position %d\n", numbers[i], i + 1);
            foundDivisible = 1;
            break;  // Stop searching after first match
        }
    }
    
    if (!foundDivisible) {
        printf("No number divisible by 7 found!\n");
    }
    
    
    // Analysis 2: Print only positive numbers
    printf("\n📊 ANALYSIS 2: Positive numbers only\n");
    printf("Positive numbers: ");
    
    int hasPositive = 0;
    for (int i = 0; i < 15; i++) {
        if (numbers[i] <= 0) {
            continue;  // Skip non-positive numbers
        }
        printf("%d ", numbers[i]);
        hasPositive = 1;
    }
    
    if (!hasPositive) {
        printf("(none)");
    }
    printf("\n");
    
    
    // Analysis 3: Sum of even numbers (skip odd)
    printf("\n📊 ANALYSIS 3: Sum of even numbers\n");
    int evenSum = 0;
    int evenCount = 0;
    
    for (int i = 0; i < 15; i++) {
        if (numbers[i] % 2 != 0) {
            continue;  // Skip odd numbers
        }
        evenSum += numbers[i];
        evenCount++;
    }
    
    printf("Even numbers found: %d\n", evenCount);
    printf("Sum of even numbers: %d\n", evenSum);
    
    if (evenCount > 0) {
        printf("Average: %.2f\n", (float)evenSum / evenCount);
    }
    
    
    // Analysis 4: Find max (with early exit on 100)
    printf("\n📊 ANALYSIS 4: Maximum value (stop at 100)\n");
    int max = numbers[0];
    int stoppedEarly = 0;
    
    for (int i = 0; i < 15; i++) {
        if (numbers[i] == 100) {
            printf("🎯 Found 100! Stopping search early.\n");
            max = 100;
            stoppedEarly = 1;
            break;  // No need to continue if we found 100
        }
        
        if (numbers[i] > max) {
            max = numbers[i];
        }
    }
    
    printf("Maximum value: %d\n", max);
    if (stoppedEarly) {
        printf("(Search stopped early at 100)\n");
    }
    
    
    // Analysis 5: Count numbers in range (10-50), skip others
    printf("\n📊 ANALYSIS 5: Numbers in range 10-50\n");
    printf("Numbers in range: ");
    
    int rangeCount = 0;
    for (int i = 0; i < 15; i++) {
        if (numbers[i] < 10 || numbers[i] > 50) {
            continue;  // Skip numbers outside range
        }
        printf("%d ", numbers[i]);
        rangeCount++;
    }
    
    if (rangeCount == 0) {
        printf("(none)");
    }
    printf("\nCount: %d\n", rangeCount);
    
    
    // Summary
    printf("\n" "===================\n");
    printf("✅ Analysis Complete!\n");
    printf("===================\n");
    
    return 0;
}

/*
 * 💡 TRY THIS:
 * 
 * Enter numbers like:
 * 14, -5, 22, 7, 33, -12, 50, 8, 100, 45, -3, 19, 28, 66, 11
 * 
 * Observe how:
 * - break stops the loop early when target is found
 * - continue skips unwanted values but keeps looping
 * 
 * Perfect examples of when to use each!
 * 
 * 🎯 CHALLENGE:
 * - Add analysis for prime numbers
 * - Find first negative number
 * - Count how many numbers are multiples of 3
 * - Display numbers in reverse (skip multiples of 5)
 */
