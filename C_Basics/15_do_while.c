/*
 * ========================================
 *   CHAPTER 15: DO-WHILE LOOP 🔄
 * ========================================
 * 
 * Loop that ALWAYS runs at least once! 🎉
 * 
 * Difference from while:
 * - while: Check condition FIRST, then run
 * - do-while: Run FIRST, then check condition
 * 
 * Syntax:
 * -------
 * do {
 *     // code (runs at least once!)
 * } while (condition);
 * 
 * Perfect for: Menus, input validation, try-again scenarios
 */

#include <stdio.h>

int main() {
    
    // 🔄 BASIC EXAMPLE: Print 1 to 5
    printf("=== Basic Do-While ===\n");
    
    int i = 1;
    do {
        printf("%d ", i);
        i++;
    } while (i <= 5);
    printf("\n");
    
    
    // 🔄 COMPARING while vs do-while
    printf("\n=== While vs Do-While ===\n");
    
    // Regular while (condition false, never runs)
    int a = 10;
    printf("While loop (starts at 10): ");
    while (a < 5) {
        printf("%d ", a);  // Never prints!
        a++;
    }
    printf("(didn't run!)\n");
    
    // Do-while (condition false, runs once anyway!)
    int b = 10;
    printf("Do-while loop (starts at 10): ");
    do {
        printf("%d ", b);  // Prints once!
        b++;
    } while (b < 5);
    printf("(ran once!)\n");
    
    
    // 🔄 REAL EXAMPLE: Input validation
    printf("\n=== Input Validation ===\n");
    int age;
    
    do {
        printf("Enter your age (1-120): ");
        scanf("%d", &age);
        
        if (age < 1 || age > 120) {
            printf("❌ Invalid! Try again.\n");
        }
    } while (age < 1 || age > 120);
    
    printf("✅ Valid age: %d\n", age);
    
    
    // 🔄 MENU SYSTEM (classic use case)
    printf("\n=== Simple Menu ===\n");
    int choice;
    
    do {
        printf("\n--- MENU ---\n");
        printf("1. Say Hello\n");
        printf("2. Show Date\n");
        printf("3. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Hello there! 👋\n");
                break;
            case 2:
                printf("Today is a great day! 📅\n");
                break;
            case 3:
                printf("Goodbye! 👋\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 3);  // Keep looping until user chooses exit
    
    
    // 🔄 SUM OF DIGITS
    printf("\n=== Sum of Digits ===\n");
    int number = 12345;
    int sum = 0;
    int temp = number;
    
    do {
        sum += temp % 10;  // Get last digit
        temp /= 10;        // Remove last digit
    } while (temp > 0);
    
    printf("Sum of digits in %d = %d\n", number, sum);
    
    
    // 🔄 COUNTDOWN
    printf("\n=== Countdown ===\n");
    int countdown = 5;
    
    do {
        printf("%d... ", countdown);
        countdown--;
    } while (countdown > 0);
    printf("Blast off! 🚀\n");
    
    return 0;
}

/*
 * 🎯 KEY TAKEAWAYS:
 * 
 * while loop:
 * - Check condition FIRST
 * - May run 0 times
 * - Use when: May not need to run at all
 * 
 * do-while loop:
 * - Run code FIRST, check condition AFTER
 * - Always runs at least 1 time
 * - Use when: Must run at least once
 * 
 * Perfect for:
 * ✅ Menu systems (show menu at least once)
 * ✅ Input validation (ask at least once)
 * ✅ Try-again scenarios
 * ✅ Game loops (play at least once)
 * 
 * Comparison:
 * -----------
 * while (condition) {
 *     code;
 * }
 * 
 * do {
 *     code;  // Runs first!
 * } while (condition);
 * 
 * Don't forget the semicolon after while! ;
 * 
 * Now try the example! 🚀
 */
