/*
============================================
   📝 PRACTICE TIME: Preprocessor
============================================

🎯 Master compilation control!
   Practice macros and conditional compilation.

============================================
*/

// QUESTION 1: Simple Macros
// Define macros:
//   - PI (3.14159)
//   - MAX(a,b) - returns larger of two
//   - SQUARE(x) - returns x*x
// Use all three in calculations




// QUESTION 2: Conditional Compilation
// Define DEBUG macro
// Use #ifdef to print debug messages
// Compile with and without -DDEBUG flag




// QUESTION 3: Feature Flags
// Create macros: FEATURE_LOGIN, FEATURE_PAYMENT
// Use #ifdef to enable/disable features
// Show different menus based on flags




// QUESTION 4: Platform-Specific Code
// Use predefined macros:
//   #ifdef _WIN32 (for Windows)
//   #ifdef __linux__ (for Linux)
// Print different messages per platform




// QUESTION 5: Macro Functions
// Create these macros:
//   - ABS(x) - absolute value
//   - MIN(a,b) - minimum of two
//   - SWAP(a,b) - swap using temp variable
// Test with various inputs
// Discuss why functions might be safer




/*
🌟 COMPILE WITH FLAGS:
   gcc 20_practice.c -o practice
   gcc -DDEBUG 20_practice.c -o practice_debug
   ./practice

💡 Check 20_configurable_app.c!
⚠️  Be careful - macros don't check types!
*/
