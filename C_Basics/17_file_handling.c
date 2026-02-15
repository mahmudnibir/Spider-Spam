/*
 * ========================================
 *   CHAPTER 17: FILE HANDLING 📁
 * ========================================
 * 
 * Save and load data from files! 🎉
 * 
 * Why use files?
 * - Store data permanently (survives after program ends)
 * - Save user data, settings, scores, logs
 * - Read data from external sources
 * 
 * Basic operations:
 * - Open file
 * - Read/Write data
 * - Close file
 * 
 * File modes:
 * "r"  = read (file must exist)
 * "w"  = write (creates new, overwrites existing)
 * "a"  = append (adds to end)
 * "r+" = read + write
 */

#include <stdio.h>

int main() {
    
    // 📁 WRITING TO FILE
    printf("=== Writing to File ===\n");
    
    FILE *filePtr;  // File pointer
    
    // Open file in write mode
    filePtr = fopen("output.txt", "w");
    
    if (filePtr == NULL) {
        printf("❌ Error opening file!\n");
        return 1;
    }
    
    // Write to file
    fprintf(filePtr, "Hello, File!\n");
    fprintf(filePtr, "This is line 2.\n");
    fprintf(filePtr, "Numbers: %d, %d, %d\n", 10, 20, 30);
    
    // Close file (important!)
    fclose(filePtr);
    printf("✅ File written successfully!\n");
    
    
    // 📁 READING FROM FILE
    printf("\n=== Reading from File ===\n");
    
    filePtr = fopen("output.txt", "r");
    
    if (filePtr == NULL) {
        printf("❌ Error opening file!\n");
        return 1;
    }
    
    char line[100];
    
    // Read line by line
    while (fgets(line, 100, filePtr) != NULL) {
        printf("%s", line);
    }
    
    fclose(filePtr);
    
    
    // 📁 APPENDING TO FILE
    printf("\n=== Appending to File ===\n");
    
    filePtr = fopen("output.txt", "a");
    
    if (filePtr != NULL) {
        fprintf(filePtr, "This line was appended!\n");
        fclose(filePtr);
        printf("✅ Text appended!\n");
    }
    
    
    // 📁 CHARACTER BY CHARACTER
    printf("\n=== Reading Character by Character ===\n");
    
    filePtr = fopen("output.txt", "r");
    
    if (filePtr != NULL) {
        char ch;
        int charCount = 0;
        
        while ((ch = fgetc(filePtr)) != EOF) {
            charCount++;
        }
        
        fclose(filePtr);
        printf("File has %d characters\n", charCount);
    }
    
    
    // 📁 WRITING NUMBERS
    printf("\n=== Saving Numbers ===\n");
    
    filePtr = fopen("numbers.txt", "w");
    
    if (filePtr != NULL) {
        for (int i = 1; i <= 10; i++) {
            fprintf(filePtr, "%d\n", i * i);  // Save squares
        }
        fclose(filePtr);
        printf("✅ Numbers saved!\n");
    }
    
    
    // 📁 READING NUMBERS
    printf("\n=== Reading Numbers ===\n");
    
    filePtr = fopen("numbers.txt", "r");
    
    if (filePtr != NULL) {
        int num;
        int sum = 0;
        
        printf("Numbers from file: ");
        while (fscanf(filePtr, "%d", &num) == 1) {
            printf("%d ", num);
            sum += num;
        }
        
        fclose(filePtr);
        printf("\nSum: %d\n", sum);
    }
    
    
    // 📁 CHECK IF FILE EXISTS
    printf("\n=== Check File Existence ===\n");
    
    filePtr = fopen("test.txt", "r");
    
    if (filePtr == NULL) {
        printf("File 'test.txt' does not exist\n");
    } else {
        printf("File 'test.txt' exists!\n");
        fclose(filePtr);
    }
    
    return 0;
}

/*
 * 🎯 KEY TAKEAWAYS:
 * 
 * File operations:
 * 1. fopen()   - Open file (returns FILE pointer)
 * 2. fclose()  - Close file (ALWAYS do this!)
 * 3. fprintf() - Write formatted data
 * 4. fscanf()  - Read formatted data
 * 5. fgets()   - Read line (safer)
 * 6. fgetc()   - Read character
 * 7. fputc()   - Write character
 * 
 * File Modes:
 * -----------
 * "r"  - Read (file must exist)
 * "w"  - Write (creates/overwrites)
 * "a"  - Append (adds to end)
 * "r+" - Read and write
 * 
 * Important:
 * - Always check if file opened (NULL check)
 * - Always close file when done
 * - Use appropriate mode
 * 
 * Common pattern:
 * FILE *fp = fopen("file.txt", "r");
 * if (fp == NULL) {
 *     // Handle error
 * }
 * // Use file
 * fclose(fp);
 * 
 * Now try the example! 🚀
 */
