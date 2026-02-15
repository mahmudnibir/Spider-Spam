/*
 * ========================================
 *   CHAPTER 17: COMMON FILE HANDLING MISTAKES ❌
 * ========================================
 * 
 * Files are powerful but require careful handling!
 */

#include <stdio.h>

int main() {
    
    // ❌ MISTAKE 1: Not checking if file opened
    printf("=== Mistake 1: Not checking NULL ===\n");
    
    FILE *fp1;
    
    // ❌ Wrong: Assuming file always opens
    // fp1 = fopen("nonexistent.txt", "r");
    // fprintf(fp1, "Hello");  // CRASH if file doesn't exist!
    
    // ✅ Correct: Always check!
    fp1 = fopen("nonexistent.txt", "r");
    if (fp1 == NULL) {
        printf("✅ Correctly handled: File doesn't exist\n");
    } else {
        fprintf(fp1, "Hello");
        fclose(fp1);
    }
    
    
    // ❌ MISTAKE 2: Forgetting to close file
    printf("\n=== Mistake 2: Not closing file ===\n");
    
    // ❌ Wrong: File not closed
    // fp1 = fopen("test.txt", "w");
    // fprintf(fp1, "Data");
    // // fclose(fp1);  ← Missing! Memory leak!
    
    // ✅ Correct: Always close
    fp1 = fopen("test_close.txt", "w");
    if (fp1 != NULL) {
        fprintf(fp1, "Data");
        fclose(fp1);  // ✅ Always close!
        printf("✅ File closed properly\n");
    }
    
    
    // ❌ MISTAKE 3: Wrong file mode
    printf("\n=== Mistake 3: Using wrong mode ===\n");
    
    // ❌ Wrong: Trying to read with "w" mode
    // fp1 = fopen("data.txt", "w");  // Opens for writing!
    // char buffer[100];
    // fgets(buffer, 100, fp1);  // ERROR! Can't read in write mode!
    
    // ✅ Correct: Use "r" for reading
    fp1 = fopen("test_close.txt", "r");
    if (fp1 != NULL) {
        char buffer[100];
        if (fgets(buffer, 100, fp1) != NULL) {
            printf("Read: %s\n", buffer);
        }
        fclose(fp1);
    }
    
    
    // ❌ MISTAKE 4: Overwriting with "w" mode
    printf("\n=== Mistake 4: Accidental overwrite ===\n");
    
    // ❌ Dangerous: "w" deletes existing content!
    fp1 = fopen("important.txt", "w");
    if (fp1 != NULL) {
        fprintf(fp1, "New content\n");
        fclose(fp1);
    }
    // Previous content is GONE!
    
    // ✅ Better: Use "a" to append (keeps existing)
    fp1 = fopen("important.txt", "a");
    if (fp1 != NULL) {
        fprintf(fp1, "Appended content\n");  // Adds to end
        fclose(fp1);
        printf("✅ Content appended (not lost)\n");
    }
    
    
    // ❌ MISTAKE 5: Not checking read success
    printf("\n=== Mistake 5: Not checking reads ===\n");
    
    fp1 = fopen("numbers.txt", "w");
    if (fp1 != NULL) {
        fprintf(fp1, "10\n20\n30\n");
        fclose(fp1);
    }
    
    // ❌ Wrong: Not checking if read succeeded
    fp1 = fopen("numbers.txt", "r");
    if (fp1 != NULL) {
        int num;
        // fscanf(fp1, "%d", &num);  // What if it fails?
        // printf("%d", num);  // Undefined if read failed!
        
        // ✅ Correct: Check return value
        while (fscanf(fp1, "%d", &num) == 1) {  // 1 = success
            printf("Read: %d\n", num);
        }
        fclose(fp1);
    }
    
    
    // ❌ MISTAKE 6: Buffer overflow with fgets
    printf("\n=== Mistake 6: Buffer overflow ===\n");
    
    fp1 = fopen("long_line.txt", "w");
    if (fp1 != NULL) {
        fprintf(fp1, "This is a very long line that might overflow\n");
        fclose(fp1);
    }
    
    // ❌ Wrong: Buffer too small
    // char small[10];
    // fgets(small, 10, fp1);  // Only reads 9 chars + \0
    // Rest of line is lost in next read!
    
    // ✅ Correct: Use adequate buffer
    fp1 = fopen("long_line.txt", "r");
    if (fp1 != NULL) {
        char adequate[100];
        fgets(adequate, 100, fp1);
        printf("Read safely: %s", adequate);
        fclose(fp1);
    }
    
    
    // ❌ MISTAKE 7: Using file pointer after close
    printf("\n=== Mistake 7: Using closed file ===\n");
    
    fp1 = fopen("temp.txt", "w");
    if (fp1 != NULL) {
        fprintf(fp1, "Data");
        fclose(fp1);
        
        // ❌ Wrong: File already closed!
        // fprintf(fp1, "More data");  // ERROR! Undefined behavior!
    }
    
    // ✅ Correct: Reopen if needed
    fp1 = fopen("temp.txt", "a");
    if (fp1 != NULL) {
        fprintf(fp1, "More data");
        fclose(fp1);
        printf("✅ Reopened and wrote successfully\n");
    }
    
    
    // ❌ MISTAKE 8: Not handling EOF correctly
    printf("\n=== Mistake 8: Wrong EOF check ===\n");
    
    fp1 = fopen("temp.txt", "w");
    if (fp1 != NULL) {
        fprintf(fp1, "ABC");
        fclose(fp1);
    }
    
    // ❌ Wrong: Using feof() before reading
    fp1 = fopen("temp.txt", "r");
    if (fp1 != NULL) {
        char ch;
        // while (!feof(fp1)) {  // Wrong! Checks before read
        //     ch = fgetc(fp1);
        //     printf("%c", ch);  // Prints last char twice!
        // }
        
        // ✅ Correct: Check after read
        while ((ch = fgetc(fp1)) != EOF) {
            printf("%c", ch);
        }
        printf("\n");
        fclose(fp1);
    }
    
    return 0;
}

/*
 * 🎯 REMEMBER:
 * 
 * 1. Always check if fopen() returns NULL
 * 2. Always close files with fclose()
 * 3. Use correct mode:
 *    - "r" for reading (file must exist)
 *    - "w" for writing (OVERWRITES!)
 *    - "a" for appending (preserves content)
 * 4. Check return values of fscanf(), fgets(), etc.
 * 5. Use adequate buffer sizes
 * 6. Don't use file pointer after closing
 * 7. Check EOF correctly (after reading, not before)
 * 
 * File handling checklist:
 * ✅ Check NULL after fopen
 * ✅ Use correct mode
 * ✅ Check read/write success
 * ✅ Close file when done
 * ✅ Handle errors gracefully
 * 
 * Files = Permanent storage! Handle with care! 📁
 */
