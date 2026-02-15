/*
 * LESSON 6: Arrays (Lists of Stuff!)
 * 
 * Arrays let you store MANY values in one variable!
 * Like a row of boxes, each with a number 📦📦📦
 */

#include <stdio.h>

int main() {
    // Instead of this:
    // int score1 = 85;
    // int score2 = 90;
    // int score3 = 78;
    
    // Do this! (much better)
    int scores[5] = {85, 90, 78, 92, 88};
    
    // Access by index (starts at 0!)
    printf("First score: %d\n", scores[0]);   // First is 0
    printf("Second score: %d\n", scores[1]);  // Second is 1
    printf("Last score: %d\n\n", scores[4]);  // Fifth is 4
    
    // Print all scores with loop
    printf("All scores:\n");
    for (int i = 0; i < 5; i++) {
        printf("Score %d: %d\n", i + 1, scores[i]);
    }
    
    // Calculate average
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        sum = sum + scores[i];
    }
    float average = sum / 5.0;
    printf("\nAverage: %.2f\n", average);
    
    return 0;
}

/*
 * Array basics:
 * - int arr[5] = declares array of 5 integers
 * - Index starts at 0: arr[0], arr[1], arr[2]...
 * - Last element is arr[size-1]
 * - Use loops to work with all elements
 */
