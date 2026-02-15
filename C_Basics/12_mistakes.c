/*
 * ========================================
 *   CHAPTER 12: COMMON STRUCTURE MISTAKES ❌
 * ========================================
 * 
 * Structures are powerful but easy to mess up!
 */

#include <stdio.h>
#include <string.h>

// Define structure
struct Person {
    char name[50];
    int age;
    float height;
};

int main() {
    
    // ❌ MISTAKE 1: Forgetting 'struct' keyword
    printf("=== Mistake 1: Missing 'struct' ===\n");
    
    // ❌ Wrong:
    // Person p1;  // Error! Not Java/C++!
    
    // ✅ Correct:
    struct Person p1;  // Must use 'struct' keyword in C
    strcpy(p1.name, "John");
    p1.age = 25;
    printf("Correct: %s is %d years old\n", p1.name, p1.age);
    
    
    // ❌ MISTAKE 2: Using = for string members
    printf("\n=== Mistake 2: Can't use = for strings ===\n");
    
    struct Person p2;
    // ❌ Wrong:
    // p2.name = "Alice";  // Error! Can't assign strings with =
    
    // ✅ Correct:
    strcpy(p2.name, "Alice");  // Use strcpy!
    p2.age = 30;
    printf("Correct: %s is %d years old\n", p2.name, p2.age);
    
    
    // ❌ MISTAKE 3: Missing semicolon after struct definition
    printf("\n=== Mistake 3: Missing semicolon ===\n");
    
    // ❌ Wrong:
    // struct Book {
    //     char title[50];
    //     int pages;
    // }  // Missing semicolon here!
    
    // ✅ Correct:
    /* 
    struct Book {
        char title[50];
        int pages;
    };  // Semicolon is REQUIRED!
    */
    printf("Always end struct definition with ;\n");
    
    
    // ❌ MISTAKE 4: Accessing members without dot
    printf("\n=== Mistake 4: Wrong member access ===\n");
    
    struct Person p3 = {"Bob", 35, 5.9};
    
    // ❌ Wrong:
    // printf("%s", name);  // Error! 'name' doesn't exist alone
    
    // ✅ Correct:
    printf("Name: %s\n", p3.name);      // Use structure.member
    printf("Age: %d\n", p3.age);
    printf("Height: %.1f\n", p3.height);
    
    
    // ❌ MISTAKE 5: Wrong initialization order
    printf("\n=== Mistake 5: Wrong init order ===\n");
    
    // ❌ Wrong: values don't match order!
    // struct Person p4 = {25, 5.8, "Charlie"};  // Wrong order!
    
    // ✅ Correct: must match struct definition order
    struct Person p5 = {"Charlie", 25, 5.8};  // name, age, height
    printf("Correct: %s, %d, %.1f\n", p5.name, p5.age, p5.height);
    
    
    // ❌ MISTAKE 6: Defining struct inside main
    printf("\n=== Mistake 6: Struct scope ===\n");
    
    // ⚠️ Bad practice:
    struct LocalStruct {
        int value;
    };
    // This works, but struct is only visible inside main!
    
    // ✅ Better: Define structures OUTSIDE main()
    // So they can be used everywhere!
    printf("Define structs outside main for better scope!\n");
    
    
    // ❌ MISTAKE 7: Comparing structures directly
    printf("\n=== Mistake 7: Can't compare structs directly ===\n");
    
    struct Person p6 = {"Alice", 30, 5.5};
    struct Person p7 = {"Alice", 30, 5.5};
    
    // ❌ Wrong:
    // if (p6 == p7) { }  // Error! Can't compare like this!
    
    // ✅ Correct: Compare members individually
    if (strcmp(p6.name, p7.name) == 0 && 
        p6.age == p7.age && 
        p6.height == p7.height) {
        printf("Persons are identical!\n");
    }
    
    return 0;
}

/*
 * 🎯 REMEMBER:
 * 
 * 1. Always use 'struct' keyword in C
 * 2. Use strcpy() for string members, not =
 * 3. End struct definition with ;
 * 4. Access members with dot (.)
 * 5. Initialize in same order as definition
 * 6. Define structs outside main()
 * 7. Compare members individually, not whole struct
 * 
 * Structures organize related data! 🏗️
 */
