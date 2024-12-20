#include <stdio.h>
#include <stdlib.h>

/* Initial ATM cash availability in different denominations */
int atm_100_notes = 2000; // K100 notes
int atm_50_notes = 2000;  // K50 notes
int atm_20_notes = 2500;  // K20 notes
int atm_10_notes = 3000;  // K10 notes
float atm_total_cash = 500000.00; // Total cash in the ATM

float balance = 500.00; // Initial balance set to 500
int UserSelection; // Variable to store the user's menu selection

/* Menu function */
void menu()
{
    printf("\nPlease select any option below to proceed.\n");
    printf("\n1. Deposit Funds");
    printf("\n2. Withdraw Funds");
    printf("\n3. Check Balance");
    printf("\n4. Exit\n");
    printf("\nPlease enter your selection: ");
    scanf("%d", &UserSelection);
}

/* Deposit funds */
void DepositFunds()
{
    float DepositAmount;
    printf("Please enter the amount you wish to deposit: ");
    scanf("%f", &DepositAmount);

    if (DepositAmount > 0)
    {
        balance += DepositAmount; // Update user balance
        printf("You have successfully deposited K%.2f to your account. Your new balance is K%.2f\n\n", DepositAmount, balance);
    }
    else
    {
        printf("Deposit incomplete. Invalid deposit amount.\n\n");
    }
}

/* Withdraw funds */
void WithdrawFunds()
{
    float WithdrawalAmount;
    int num100 = 0, num50 = 0, num20 = 0, num10 = 0;
    int total_100 = 0, total_50 = 0, total_20 = 0, total_10 = 0;

    printf("Please enter the amount you wish to withdraw: ");
    scanf("%f", &WithdrawalAmount);

    if (WithdrawalAmount > 0 && WithdrawalAmount <= balance && WithdrawalAmount <= atm_total_cash)
    {
        printf("Specify the number of notes for each denomination:\n");

        printf("Number of K100 notes: ");
        scanf("%d", &num100);
        total_100 = num100 * 100;

        printf("Number of K50 notes: ");
        scanf("%d", &num50);
        total_50 = num50 * 50;

        printf("Number of K20 notes: ");
        scanf("%d", &num20);
        total_20 = num20 * 20;

        printf("Number of K10 notes: ");
        scanf("%d", &num10);
        total_10 = num10 * 10;

        float total_withdrawn = total_100 + total_50 + total_20 + total_10;

        if (total_withdrawn == WithdrawalAmount &&
            num100 <= atm_100_notes && num50 <= atm_50_notes &&
            num20 <= atm_20_notes && num10 <= atm_10_notes)
        {
            balance -= WithdrawalAmount; // Deduct from user balance
            atm_total_cash -= WithdrawalAmount; // Deduct from ATM total cash

            atm_100_notes -= num100;
            atm_50_notes -= num50;
            atm_20_notes -= num20;
            atm_10_notes -= num10;

            printf("You have successfully withdrawn K%.2f from your account. Your new balance is K%.2f.\n\n", WithdrawalAmount, balance);
        }
        else if (total_withdrawn != WithdrawalAmount)
        {
            printf("Error: The breakdown of denominations does not match the withdrawal amount.\n");
        }
        else
        {
            printf("Error: Insufficient notes in the ATM for the specified denominations.\n");
        }
    }
    else if (WithdrawalAmount > balance)
    {
        printf("You have insufficient funds to make this withdrawal. Try to withdraw any amount below K%.2f.\n\n", balance);
    }
    else if (WithdrawalAmount > atm_total_cash)
    {
        printf("The ATM does not have sufficient funds to complete this withdrawal.\n\n");
    }
    else
    {
        printf("Invalid withdrawal amount. Please try again.\n\n");
    }
}

/* Check balance */
void BalanceCheck()
{
    printf("Your available balance is K%.2f.\n\n", balance);
}

/* Continue transaction */
int ContinueTransaction()
{
    char selection;
    printf("Would you like to perform another transaction? (y/n): ");
    scanf(" %c", &selection);

    if (selection == 'y' || selection == 'Y')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/* Main function */
int main()
{
    printf("Welcome to Shawa's Banking Services\n");

    while (1)
    {
        menu();

        switch (UserSelection)
        {
            case 1:
                DepositFunds();
                break;
            case 2:
                WithdrawFunds();
                break;
            case 3:
                BalanceCheck();
                break;
            case 4:
                printf("Thank you for using Shawa's Banking Services. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please select a valid option.\n");
                break;
        }

        if (!ContinueTransaction())
        {
            printf("Thank you for using Shawa's Banking Services. Goodbye!\n");
            break;
        }
    }
    return 0;
}
