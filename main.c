#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME 50
#define MAX_PIN 6

typedef struct {
    char name[MAX_NAME];
    char pin[MAX_PIN];
    int balance;
} Account;

void printLine() {
    printf("===========================================\n");
}

int menu() {
    int answ;
    printLine();
    printf("ATM SYSTEM MENU\n");
    printLine();
    printf("1. Deposit\n2. Withdraw\n3. Check Balance\n4. Exit\n");
    printLine();
    printf("Select an option: ");
    scanf("%d", &answ);
    return answ;
}

void deposit(Account *acc) {
    int dp;
    printf("\n--- Deposit Menu ---\nBalance: %d EUR\n", acc->balance);
    printf("Enter amount to deposit: ");
    scanf("%d", &dp);
    if (dp > 0) {
        acc->balance += dp;
        printf("Successfully deposited: %d EUR\nNew Balance: %d EUR\n", dp, acc->balance);
    } else {
        printf("Invalid deposit amount!\n");
    }
}

void withdraw(Account *acc) {
    int wd;
    printf("\n--- Withdraw Menu ---\nBalance: %d EUR\n", acc->balance);
    if (acc->balance == 0) {
        printf("Insufficient funds.\n");
        return;
    }
    printf("Enter amount to withdraw: ");
    scanf("%d", &wd);
    if (wd > acc->balance) {
        printf("Insufficient funds.\n");
    } else if (wd <= 0) {
        printf("Invalid withdrawal amount!\n");
    } else {
        acc->balance -= wd;
        printf("Successfully withdrew: %d EUR\nNew Balance: %d EUR\n", wd, acc->balance);
    }
}

void checkBalance(const Account *acc) {
    printf("\n--- Account Balance ---\nAccount Holder: %s\nBalance: %d EUR\n", acc->name, acc->balance);
}

int authenticate(Account *acc) {
    char input_pin[MAX_PIN];
    printf("\nPlease enter your 4-digit PIN: ");
    scanf("%s", input_pin);
    if (strcmp(acc->pin, input_pin) == 0) {
        printf("Authentication successful.\n");
        return 1;
    } else {
        printf("Authentication failed.\n");
        return 0;
    }
}

int main() {
    Account user = {"John Doe", "1234", 0};
    system("title ATM System");

    printf("Welcome to the Advanced ATM System\n");
    if (!authenticate(&user)) {
        printf("Exiting due to failed authentication.\n");
        return 1;
    }

    int option;
    do {
        option = menu();
        switch (option) {
            case 1:
                deposit(&user);
                break;
            case 2:
                withdraw(&user);
                break;
            case 3:
                checkBalance(&user);
                break;
            case 4:
                printf("Thank you for using the ATM system!\n");
                break;
            default:
                printf("Invalid option. Try again.\n");
        }
    } while (option != 4);

    return 0;
}
