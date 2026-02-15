/*
 * COMMON MISTAKES: Arrays ❌
 */

#include <stdio.h>

int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    
    /* ❌ MISTAKE 1: Index out of bounds */
    printf("arr[0] = %d (first element)\n", arr[0]);
    printf("arr[4] = %d (last element)\n", arr[4]);
    // printf("arr[5] = %d", arr[5]);  // ❌ DANGER! No 5th index!
    // arr has indices 0,1,2,3,4 only!
    printf("Array has 5 elements: index 0 to 4\n\n");
    
    
    /* ❌ MISTAKE 2: Forgetting arrays start at 0 */
    int numbers[3] = {100, 200, 300};
    
    // Wrong way
    printf("Wrong way:\n");
    for (int i = 1; i <= 3; i++) {  // ❌ Skips first, crashes at end!
        // printf("%d ", numbers[i]);
    }
    
    // Right way
    printf("Right way: ");
    for (int i = 0; i < 3; i++) {  // ✅ Start at 0, stop before 3
        printf("%d ", numbers[i]);
    }
    printf("\n\n");
    
    
    /* ❌ MISTAKE 3: Not initializing array */
    int bad[3];  // Has random garbage values!
    // Don't use without setting values first!
    
    int good[3] = {1, 2, 3};  // ✅ Initialize it
    printf("Initialized array: ");
    for (int i = 0; i < 3; i++) {
        printf("%d ", good[i]);
    }
    printf("\n\n");
    
    
    /* ❌ MISTAKE 4: Wrong size in loop */
    int data[5] = {5, 10, 15, 20, 25};
    
    // for (int i = 0; i <= 5; i++) {  // ❌ Goes too far! (0-5 is 6 times)
    for (int i = 0; i < 5; i++) {      // ✅ Correct (0-4 is 5 times)
        printf("%d ", data[i]);
    }
    printf("\n\n");
    
    
    /* ❌ MISTAKE 5: Can't assign whole array at once */
    int a[3] = {1, 2, 3};
    int b[3];
    
    // b = a;  // ❌ Can't copy like this!
    
    // ✅ Must copy element by element
    for (int i = 0; i < 3; i++) {
        b[i] = a[i];
    }
    
    printf("Copied array: ");
    for (int i = 0; i < 3; i++) {
        printf("%d ", b[i]);
    }
    printf("\n\n");
    
    
    /* ❌ MISTAKE 6: Treating size like index */
    int list[10];  // Size is 10
    // list[10] = 99;  // ❌ No index 10! (0-9 only)
    list[9] = 99;     // ✅ Last index is size-1
    
    printf("Last element: %d\n\n", list[9]);
    
    
    printf("Array mistakes conquered! You're doing great! 🌟\n");
    
    return 0;
}

/*
 * Remember:
 * - Index starts at 0, ends at size-1
 * - arr[5] means size 5, but indices 0,1,2,3,4
 * - Always initialize before using
 * - Use i < size in loops, not i <= size
 * - Can't assign arrays directly (a = b doesn't work)
 * - Last index is size-1, NOT size!
 */
