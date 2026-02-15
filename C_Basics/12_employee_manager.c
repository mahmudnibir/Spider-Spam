/*
 * ========================================
 *   CHAPTER 12: STRUCTURES - PRACTICE ✏️
 * ========================================
 * 
 * Let's build a simple employee management system!
 */

#include <stdio.h>
#include <string.h>

// Define Employee structure
struct Employee {
    int id;
    char name[50];
    char department[30];
    float salary;
};

int main() {
    
    struct Employee employees[3];  // Array for 3 employees
    
    printf("👔 Employee Management System\n");
    printf("==============================\n\n");
    
    // Input employee data
    for (int i = 0; i < 3; i++) {
        printf("Enter details for Employee %d:\n", i + 1);
        
        printf("  ID: ");
        scanf("%d", &employees[i].id);
        getchar();  // Clear newline
        
        printf("  Name: ");
        fgets(employees[i].name, 50, stdin);
        employees[i].name[strcspn(employees[i].name, "\n")] = 0;
        
        printf("  Department: ");
        fgets(employees[i].department, 30, stdin);
        employees[i].department[strcspn(employees[i].department, "\n")] = 0;
        
        printf("  Salary: $");
        scanf("%f", &employees[i].salary);
        
        printf("\n");
    }
    
    // Display all employees
    printf("\n📊 EMPLOYEE RECORDS:\n");
    printf("========================================================\n");
    printf("ID    Name               Department       Salary\n");
    printf("========================================================\n");
    
    for (int i = 0; i < 3; i++) {
        printf("%-6d %-18s %-16s $%.2f\n",
               employees[i].id,
               employees[i].name,
               employees[i].department,
               employees[i].salary);
    }
    
    // Calculate total salary
    float totalSalary = 0;
    for (int i = 0; i < 3; i++) {
        totalSalary += employees[i].salary;
    }
    
    printf("========================================================\n");
    printf("Total Salary Budget: $%.2f\n", totalSalary);
    printf("Average Salary: $%.2f\n", totalSalary / 3);
    
    // Find highest paid employee
    int highestIndex = 0;
    for (int i = 1; i < 3; i++) {
        if (employees[i].salary > employees[highestIndex].salary) {
            highestIndex = i;
        }
    }
    
    printf("\n🏆 Highest Paid: %s ($%.2f)\n",
           employees[highestIndex].name,
           employees[highestIndex].salary);
    
    return 0;
}

/*
 * 💡 TRY THIS:
 * 
 * Enter data like:
 * Employee 1: ID=101, John Doe, IT, 75000
 * Employee 2: ID=102, Jane Smith, HR, 65000
 * Employee 3: ID=103, Bob Johnson, Sales, 70000
 * 
 * See how structures organize complex data!
 * 
 * 🎯 CHALLENGE:
 * - Add email field to Employee structure
 * - Search for employee by ID
 * - Sort employees by salary
 */
