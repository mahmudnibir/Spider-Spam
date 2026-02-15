/*
 * ========================================
 *   CHAPTER 10: STRINGS 📝
 * ========================================
 * 
 * Hey! Let's talk about storing text! 🎉
 * 
 * In C, there's no "string" type like other languages.
 * We use character arrays with a special ending!
 * 
 * String = Array of characters ending with '\0' (null character)
 * 
 * Quick Guide:
 * ------------
 * char name[20] = "John";     // Creates: J o h n \0
 * char word[] = "Hello";      // Auto-sizes to fit
 * printf("%s", name);         // %s prints strings
 */

#include <stdio.h>
#include <string.h>  // For string functions!

int main() {
    
    // 📝 METHOD 1: Direct initialization
    char greeting[20] = "Hello World";
    printf("Greeting: %s\n", greeting);
    
    // 📝 METHOD 2: Character by character
    char word[10];
    word[0] = 'H';
    word[1] = 'i';
    word[2] = '\0';  // Don't forget this!
    printf("Word: %s\n", word);
    
    // 📝 STRING INPUT: Use gets() or fgets()
    char name[50];
    printf("\nWhat's your name? ");
    fgets(name, 50, stdin);  // Safer than gets()
    printf("Hello, %s", name);
    
    // 📝 STRING FUNCTIONS (from string.h)
    char str1[20] = "Hello";
    char str2[20] = "World";
    
    // Length of string
    printf("\nLength of '%s' = %lu\n", str1, strlen(str1));
    
    // Copy string
    char copy[20];
    strcpy(copy, str1);
    printf("Copied: %s\n", copy);
    
    // Concatenate (join) strings
    strcat(str1, " ");     // Add space
    strcat(str1, str2);    // Add World
    printf("Combined: %s\n", str1);  // "Hello World"
    
    // Compare strings (returns 0 if equal)
    if (strcmp("abc", "abc") == 0) {
        printf("Strings are equal!\n");
    }
    
    // 📝 USEFUL TIP:
    // Strings in C are just character arrays!
    char text[] = "Code";
    printf("\nAccessing individual characters:\n");
    printf("First letter: %c\n", text[0]);   // 'C'
    printf("Second letter: %c\n", text[1]);  // 'o'
    
    return 0;
}

/*
 * 🎯 KEY TAKEAWAYS:
 * 
 * 1. String = char array ending with '\0'
 * 2. Use %s to print strings
 * 3. Use fgets() for safe input
 * 4. Remember to include <string.h>
 * 
 * Common functions:
 * - strlen(str)      → Get length
 * - strcpy(dst, src) → Copy string
 * - strcat(dst, src) → Join strings
 * - strcmp(s1, s2)   → Compare strings
 * 
 * Now try the example! 🚀
 */
