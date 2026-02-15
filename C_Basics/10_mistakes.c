/*
 * ========================================
 *   CHAPTER 10: COMMON STRING MISTAKES ❌
 * ========================================
 * 
 * Strings are tricky! Let's avoid these common errors.
 */

#include <stdio.h>
#include <string.h>

int main() {
    
    // ❌ MISTAKE 1: Forgetting the null terminator
    printf("=== Mistake 1: No null terminator ===\n");
    char wrong[5];
    wrong[0] = 'H';
    wrong[1] = 'i';
    // Missing: wrong[2] = '\0';
    // This will print garbage! ⚠️
    
    // ✅ CORRECT:
    char right[5];
    right[0] = 'H';
    right[1] = 'i';
    right[2] = '\0';  // Always add this!
    printf("Correct: %s\n", right);
    
    
    // ❌ MISTAKE 2: Array too small
    printf("\n=== Mistake 2: Array too small ===\n");
    // char tiny[5] = "Hello World";  // Won't fit! Buffer overflow!
    
    // ✅ CORRECT:
    char big[20] = "Hello World";  // Room for 11 chars + '\0'
    printf("Correct: %s\n", big);
    
    
    // ❌ MISTAKE 3: Using = to copy strings
    printf("\n=== Mistake 3: Can't use = for strings ===\n");
    char str1[20] = "Hello";
    char str2[20];
    // str2 = str1;  // ❌ ERROR! Can't do this!
    
    // ✅ CORRECT:
    strcpy(str2, str1);  // Use strcpy!
    printf("Copied correctly: %s\n", str2);
    
    
    // ❌ MISTAKE 4: Using == to compare strings
    printf("\n=== Mistake 4: Can't use == for strings ===\n");
    char name1[10] = "John";
    char name2[10] = "John";
    
    // if (name1 == name2) { }  // ❌ Compares addresses, not content!
    
    // ✅ CORRECT:
    if (strcmp(name1, name2) == 0) {  // Use strcmp!
        printf("Names are equal!\n");
    }
    
    
    // ❌ MISTAKE 5: Forgetting to include <string.h>
    printf("\n=== Mistake 5: Missing header ===\n");
    // If you use strlen, strcpy, strcmp, etc.
    // You MUST include: #include <string.h>
    printf("strlen, strcpy need <string.h> ✅\n");
    
    
    // ❌ MISTAKE 6: Using & with scanf for strings
    printf("\n=== Mistake 6: & with string input ===\n");
    char input[20];
    printf("Enter a word: ");
    // scanf("&%s", &input);  // ❌ Wrong! No & needed!
    scanf("%s", input);       // ✅ Correct! Array name is already address
    printf("You entered: %s\n", input);
    
    return 0;
}

/*
 * 🎯 REMEMBER:
 * 
 * 1. Always end strings with '\0'
 * 2. Make arrays big enough
 * 3. Use strcpy to copy, not =
 * 4. Use strcmp to compare, not ==
 * 5. Include <string.h> for string functions
 * 6. No & needed with scanf for strings
 * 
 * Strings are just char arrays with '\0' at the end! 📝
 */
