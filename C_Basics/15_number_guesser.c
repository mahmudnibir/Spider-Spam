/*
 * ========================================
 *   CHAPTER 15: DO-WHILE LOOP - PRACTICE ✏️
 * ========================================
 * 
 * Let's build a number guessing game!
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    
    // Seed random number generator
    srand(time(NULL));
    int secretNumber = (rand() % 100) + 1;  // Random between 1-100
    int guess;
    int attempts = 0;
    int maxAttempts = 7;
    
    printf("🎮 NUMBER GUESSING GAME\n");
    printf("========================\n");
    printf("I'm thinking of a number between 1 and 100\n");
    printf("You have %d attempts to guess it!\n\n", maxAttempts);
    
    // Game loop (must play at least once!)
    do {
        attempts++;
        
        printf("Attempt %d/%d - Enter your guess: ", attempts, maxAttempts);
        scanf("%d", &guess);
        
        // Validate input
        if (guess < 1 || guess > 100) {
            printf("❌ Please guess between 1 and 100!\n");
            attempts--;  // Don't count invalid guesses
            continue;
        }
        
        // Check guess
        if (guess < secretNumber) {
            printf("📉 Too low! Try higher.\n\n");
        } else if (guess > secretNumber) {
            printf("📈 Too high! Try lower.\n\n");
        } else {
            // Correct guess!
            printf("\n🎉 CONGRATULATIONS! 🎉\n");
            printf("You guessed it in %d attempts!\n", attempts);
            
            // Performance feedback
            if (attempts <= 3) {
                printf("⭐⭐⭐ Amazing! You're a genius! 🧠\n");
            } else if (attempts <= 5) {
                printf("⭐⭐ Great job! Well done! 👍\n");
            } else {
                printf("⭐ Good effort! You made it! 😊\n");
            }
            break;  // Exit loop on correct guess
        }
        
        // Hint after 4 attempts
        if (attempts == 4 && guess != secretNumber) {
            if (secretNumber % 2 == 0) {
                printf("💡 Hint: The number is EVEN\n\n");
            } else {
                printf("💡 Hint: The number is ODD\n\n");
            }
        }
        
    } while (attempts < maxAttempts && guess != secretNumber);
    
    // Lost the game
    if (guess != secretNumber) {
        printf("\n😔 Game Over!\n");
        printf("The number was: %d\n", secretNumber);
        printf("Better luck next time! 🍀\n");
    }
    
    // Play again?
    char playAgain;
    printf("\nPlay again? (y/n): ");
    scanf(" %c", &playAgain);
    
    if (playAgain == 'y' || playAgain == 'Y') {
        printf("Great! Run the program again! 🔄\n");
    } else {
        printf("Thanks for playing! Goodbye! 👋\n");
    }
    
    return 0;
}

/*
 * 💡 TRY THIS:
 * 
 * Play the game and observe:
 * - The loop runs at least once (to show the game)
 * - Input validation happens inside the loop
 * - Game continues until win or max attempts
 * 
 * Perfect use of do-while because:
 * - Must ask for guess at least once
 * - Need to validate and retry
 * 
 * 🎯 CHALLENGE:
 * - Add difficulty levels (Easy: 1-50, Hard: 1-200)
 * - Show remaining attempts
 * - Add timer to track how long it takes
 * - Keep score and high scores
 */
