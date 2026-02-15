/*
 * LESSON 3: Making Decisions (if-else)
 * 
 * Sometimes your program needs to make choices!
 * Like: "If it's raining, take umbrella. Otherwise, don't."
 * Super useful! 🌂
 */

#include <stdio.h>

int main() {
    // Simple if-else
    int age = 20;
    
    printf("Your age: %d\n", age);
    
    if (age >= 18) {
        printf("You're an adult! 🎉\n\n");
    } else {
        printf("You're still young!\n\n");
    }
    
    // Multiple conditions with else if
    int score = 85;
    
    printf("Your score: %d\n", score);
    
    if (score >= 90) {
        printf("Grade: A (Excellent!)\n");
    } else if (score >= 80) {
        printf("Grade: B (Great!)\n");
    } else if (score >= 70) {
        printf("Grade: C (Good)\n");
    } else if (score >= 60) {
        printf("Grade: D (Pass)\n");
    } else {
        printf("Grade: F (Need to study more)\n");
    }
    
    return 0;
}

/*
 * How it works:
 * if (condition is true) {
 *     do this
 * } else {
 *     do that instead
 * }
 */
