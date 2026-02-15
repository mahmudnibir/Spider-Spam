/*
 * ========================================
 *   CHAPTER 17: FILE HANDLING - PRACTICE ✏️
 * ========================================
 * 
 * Let's build a simple student record system!
 */

#include <stdio.h>
#include <string.h>

int main() {
    
    FILE *filePtr;
    int choice;
    char filename[] = "students.txt";
    
    printf("📚 Student Record System\n");
    printf("========================\n\n");
    
    do {
        printf("\n--- MENU ---\n");
        printf("1. Add Student Record\n");
        printf("2. View All Records\n");
        printf("3. Count Students\n");
        printf("4. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);
        getchar();  // Clear newline
        
        switch (choice) {
            
            case 1: {
                // Add student record
                char name[50];
                int rollNo;
                float marks;
                
                printf("\n=== Add New Student ===\n");
                printf("Name: ");
                fgets(name, 50, stdin);
                name[strcspn(name, "\n")] = 0;  // Remove newline
                
                printf("Roll Number: ");
                scanf("%d", &rollNo);
                
                printf("Marks: ");
                scanf("%f", &marks);
                
                // Append to file
                filePtr = fopen(filename, "a");
                
                if (filePtr != NULL) {
                    fprintf(filePtr, "%s,%d,%.2f\n", name, rollNo, marks);
                    fclose(filePtr);
                    printf("✅ Student added successfully!\n");
                } else {
                    printf("❌ Error opening file!\n");
                }
                break;
            }
            
            case 2: {
                // View all records
                printf("\n=== All Student Records ===\n");
                printf("===============================================\n");
                printf("%-20s %-12s %-10s\n", "Name", "Roll No", "Marks");
                printf("===============================================\n");
                
                filePtr = fopen(filename, "r");
                
                if (filePtr == NULL) {
                    printf("No records found! Add students first.\n");
                } else {
                    char name[50];
                    int rollNo;
                    float marks;
                    int count = 0;
                    
                    while (fscanf(filePtr, "%49[^,],%d,%f\n", name, &rollNo, &marks) == 3) {
                        printf("%-20s %-12d %-10.2f\n", name, rollNo, marks);
                        count++;
                    }
                    
                    fclose(filePtr);
                    
                    if (count == 0) {
                        printf("No records found!\n");
                    } else {
                        printf("===============================================\n");
                        printf("Total students: %d\n", count);
                    }
                }
                break;
            }
            
            case 3: {
                // Count students
                printf("\n=== Student Statistics ===\n");
                
                filePtr = fopen(filename, "r");
                
                if (filePtr == NULL) {
                    printf("No records found!\n");
                } else {
                    char name[50];
                    int rollNo;
                    float marks;
                    int count = 0;
                    float totalMarks = 0;
                    float highest = 0;
                    
                    while (fscanf(filePtr, "%49[^,],%d,%f\n", name, &rollNo, &marks) == 3) {
                        count++;
                        totalMarks += marks;
                        if (marks > highest) {
                            highest = marks;
                        }
                    }
                    
                    fclose(filePtr);
                    
                    if (count > 0) {
                        printf("Total Students: %d\n", count);
                        printf("Average Marks: %.2f\n", totalMarks / count);
                        printf("Highest Marks: %.2f\n", highest);
                    }
                }
                break;
            }
            
            case 4:
                printf("\n👋 Goodbye!\n");
                break;
            
            default:
                printf("❌ Invalid choice!\n");
        }
        
    } while (choice != 4);
    
    return 0;
}

/*
 * 💡 TRY THIS:
 * 
 * 1. Add few students:
 *    - Name: John Doe, Roll: 101, Marks: 85
 *    - Name: Jane Smith, Roll: 102, Marks: 92
 *    - Name: Bob Wilson, Roll: 103, Marks: 78
 * 
 * 2. View all records
 * 3. Check statistics
 * 4. Close and reopen - data persists!
 * 
 * See how files save data permanently!
 * 
 * 🎯 CHALLENGE:
 * - Add search by roll number
 * - Add delete record option
 * - Save to different files (by class/subject)
 * - Add date/time stamps
 */
