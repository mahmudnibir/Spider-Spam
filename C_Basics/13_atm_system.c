/*
 * ========================================
 *   CHAPTER 13: SWITCH-CASE - PRACTICE ✏️
 * ========================================
 * 
 * Let's build a simple ATM menu system!
 */

#include <stdio.h>

int main() {
    
    int choice;
    float balance = 5000.00;  // Starting balance
    float amount;
    
    printf("💳 ATM Machine\n");
    printf("==============\n\n");
    
    printf("1. Check Balance\n");
    printf("2. Deposit Money\n");
    printf("3. Withdraw Money\n");
    printf("4. Exit\n\n");
    
    printf("Enter your choice (1-4): ");
    scanf("%d", &choice);
    
    switch (choice) {
        
        case 1:
            printf("\n💰 Current Balance: $%.2f\n", balance);
            break;
        
        case 2:
            printf("\nEnter amount to deposit: $");
            scanf("%f", &amount);
            
            if (amount > 0) {
                balance += amount;
                printf("✅ Deposited: $%.2f\n", amount);
                printf("💰 New Balance: $%.2f\n", balance);
            } else {
                printf("❌ Invalid amount!\n");
            }
            break;
        
        case 3:
            printf("\nEnter amount to withdraw: $");
            scanf("%f", &amount);
            
            if (amount > 0 && amount <= balance) {
                balance -= amount;
                printf("✅ Withdrawn: $%.2f\n", amount);
                printf("💰 New Balance: $%.2f\n", balance);
            } else if (amount > balance) {
                printf("❌ Insufficient balance!\n");
                printf("💰 Available: $%.2f\n", balance);
            } else {
                printf("❌ Invalid amount!\n");
            }
            break;
        
        case 4:
            printf("\n👋 Thank you for using our ATM!\n");
            printf("Have a great day! 🌟\n");
            break;
        
        default:
            printf("\n❌ Invalid choice!\n");
            printf("Please choose 1-4 only.\n");
    }
    
    return 0;
}

/*
 * 💡 TRY THIS:
 * 
 * Run the program and try:
 * - Option 1: Check balance
 * - Option 2: Deposit $1000
 * - Option 3: Withdraw $500
 * - Option 5: See the error handling!
 * 
 * See how switch makes menus clean and organized!
 * 
 * 🎯 CHALLENGE:
 * - Add "Transfer Money" option
 * - Add PIN verification at start
 * - Use a loop to keep menu running until Exit
 */
