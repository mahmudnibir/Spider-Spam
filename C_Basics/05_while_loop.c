/*
 * LESSON 5: While Loops
 * 
 * Like for loops, but simpler!
 * "While this is true, keep doing this"
 * Good when you don't know how many times to repeat! 🔁
 */

#include <stdio.h>

int main() {
    // Count to 5
    printf("Counting with while:\n");
    int i = 1;
    while (i <= 5) {
        printf("%d ", i);
        i++;  // Don't forget this!
    }
    printf("\n\n");
    
    // Guess a number game
    printf("=== Guessing Game ===\n");
    int secret = 7;
    int guess;
    
    printf("Guess a number (1-10): ");
    scanf("%d", &guess);
    
    while (guess != secret) {
        printf("Wrong! Try again: ");
        scanf("%d", &guess);
    }
    
    printf("You got it! 🎉\n");
    
    return 0;
}

/*
 * While loop:
 * while (condition) {
 *     do stuff
 *     update something (or you're stuck forever!)
 * }
 */
