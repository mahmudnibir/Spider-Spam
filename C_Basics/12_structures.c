/*
 * ========================================
 *   CHAPTER 12: STRUCTURES 🏗️
 * ========================================
 * 
 * Group different data types together! 🎉
 * 
 * Arrays = Multiple values of SAME type
 * Structures = Multiple values of DIFFERENT types
 * 
 * Think of it like:
 * - A contact card (name, phone, email)
 * - A product (name, price, quantity)
 * - A student (name, age, grade)
 * 
 * Syntax:
 * -------
 * struct Person {
 *     char name[50];
 *     int age;
 *     float height;
 * };
 */

#include <stdio.h>
#include <string.h>

// 🏗️ Define a structure (outside main)
struct Student {
    char name[50];
    int rollNumber;
    float marks;
};

struct Book {
    char title[100];
    char author[50];
    int pages;
    float price;
};

int main() {
    
    // 📝 METHOD 1: Declare then assign
    struct Student s1;
    
    strcpy(s1.name, "Alice");
    s1.rollNumber = 101;
    s1.marks = 95.5;
    
    printf("=== Student Details ===\n");
    printf("Name: %s\n", s1.name);
    printf("Roll: %d\n", s1.rollNumber);
    printf("Marks: %.1f\n", s1.marks);
    
    
    // 📝 METHOD 2: Initialize directly
    struct Student s2 = {"Bob", 102, 88.5};
    
    printf("\n=== Another Student ===\n");
    printf("Name: %s\n", s2.name);
    printf("Roll: %d\n", s2.rollNumber);
    printf("Marks: %.1f\n", s2.marks);
    
    
    // 📝 REAL EXAMPLE: Book catalog
    struct Book b1;
    
    printf("\n=== Book Entry System ===\n");
    printf("Enter book title: ");
    fgets(b1.title, 100, stdin);
    b1.title[strcspn(b1.title, "\n")] = 0;  // Remove newline
    
    printf("Enter author: ");
    fgets(b1.author, 50, stdin);
    b1.author[strcspn(b1.author, "\n")] = 0;
    
    printf("Enter pages: ");
    scanf("%d", &b1.pages);
    
    printf("Enter price: ");
    scanf("%f", &b1.price);
    
    printf("\n📚 Book Details:\n");
    printf("Title: %s\n", b1.title);
    printf("Author: %s\n", b1.author);
    printf("Pages: %d\n", b1.pages);
    printf("Price: $%.2f\n", b1.price);
    
    
    // 📝 ARRAY OF STRUCTURES
    struct Student class[3] = {
        {"Alice", 101, 95.5},
        {"Bob", 102, 88.5},
        {"Charlie", 103, 92.0}
    };
    
    printf("\n=== Class Records ===\n");
    for (int i = 0; i < 3; i++) {
        printf("%d. %s - %.1f marks\n", 
               i + 1, class[i].name, class[i].marks);
    }
    
    return 0;
}

/*
 * 🎯 KEY TAKEAWAYS:
 * 
 * 1. struct groups different data types
 * 2. Define structure outside main()
 * 3. Access members with dot (.)
 *    Example: student.name, student.age
 * 4. Can create arrays of structures
 * 5. Use strcpy() to assign strings in struct
 * 
 * Structure syntax:
 * -----------------
 * struct StructName {
 *     dataType member1;
 *     dataType member2;
 * };
 * 
 * struct StructName variable;
 * variable.member1 = value;
 * 
 * Perfect for real-world objects! 🏗️
 * 
 * Now try the example! 🚀
 */
