/*
 * ========================================
 *   CHAPTER 10: STRINGS - PRACTICE ✏️
 * ========================================
 * 
 * Let's build a simple name formatter!
 * It will take first and last name, then create a full name.
 */

#include <stdio.h>
#include <string.h>

int main() {
    
    char firstName[30];
    char lastName[30];
    char fullName[60];
    
    // Get user input
    printf("🎯 Name Formatter Tool\n");
    printf("=====================\n\n");
    
    printf("Enter first name: ");
    scanf("%s", firstName);  // No & needed for arrays!
    
    printf("Enter last name: ");
    scanf("%s", lastName);
    
    // Build full name
    strcpy(fullName, firstName);  // Copy first name
    strcat(fullName, " ");        // Add space
    strcat(fullName, lastName);   // Add last name
    
    // Display results
    printf("\n✨ Results ✨\n");
    printf("First Name: %s\n", firstName);
    printf("Last Name: %s\n", lastName);
    printf("Full Name: %s\n", fullName);
    printf("Full Name Length: %lu characters\n", strlen(fullName));
    
    // Fun fact: Check if names match
    if (strcmp(firstName, lastName) == 0) {
        printf("\n😄 Your first and last names are the same!\n");
    } else {
        printf("\n✅ Your first and last names are different!\n");
    }
    
    return 0;
}

/*
 * 💡 TRY THIS:
 * 
 * Run this program and enter:
 * First name: John
 * Last name: Doe
 * 
 * See how strcpy, strcat, strlen work together!
 * 
 * 🎯 CHALLENGE:
 * Add a middle name too! 
 * Make it: FirstName MiddleName LastName
 */
