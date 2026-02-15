/*
 * LESSON 9: Pointers (Memory Addresses!)
 * 
 * Pointers are like GPS coordinates for your variables! 📍
 * They store the LOCATION of data, not the data itself!
 * Sounds scary but it's actually cool!
 * 
 * Your Original: pointers.c
 */

#include <stdio.h>

int main() {
    // Regular variable
    int age = 25;
    
    printf("Value of age: %d\n", age);
    printf("Address of age: %p\n\n", &age);  // & = "address of"
    
    // Pointer variable (stores address)
    int *ptr;      // * means "pointer to int"
    ptr = &age;    // ptr now points to age
    
    printf("Pointer stores: %p\n", ptr);     // Shows address
    printf("Value at pointer: %d\n\n", *ptr); // * = "value at"
    
    // Your original: Change value through pointer!
    printf("=== Changing Through Pointer ===\n");
    int x = 0;
    int *p = &x;
    
    printf("Before: x = %d\n", x);
    *p = 100;  // Change x through pointer!
    printf("After: x = %d\n\n", x);
    
    // Why use pointers?
    printf("=== Why Pointers? ===\n");
    int num = 5;
    int *numPtr = &num;
    
    printf("Original: %d\n", num);
    *numPtr = *numPtr * 2;  // Double it through pointer
    printf("Doubled: %d\n", num);
    
    return 0;
}

/*
 * Pointer basics:
 * - & = "address of" (get location)
 * - * = "value at" (get data at location)
 * 
 * Think of it like:
 * - House number (address) → &variable
 * - Person in house (value) → *pointer
 */
