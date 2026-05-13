#include <stdio.h>
#include <stdlib.h>

// Colors
#define RESET   "\033[0m"
#define GREEN   "\033[1;32m"
#define RED     "\033[1;31m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define CYAN    "\033[1;36m"

// Functions
void line() {
    printf(BLUE "+--------------------------------------+\n" RESET);
}

void title(char text[]) {
    line();
    printf(BLUE "| %-36s |\n" RESET, text);
    line();
}

void pauseScreen() {
    printf(YELLOW "\nPress Enter to continue..." RESET);
    getchar();
    getchar();
}

// Main
int main() {

    int choice;
    float balance = 1000, amount;

    while (1) {

        system("cls || clear");

        title("ATM BANKING SYSTEM");

        printf(YELLOW " 1. Check Balance\n" RESET);
        printf(YELLOW " 2. Deposit Money\n" RESET);
        printf(YELLOW " 3. Withdraw Money\n" RESET);
        printf(YELLOW " 4. Exit\n" RESET);

        line();

        printf(CYAN " Enter your choice: " RESET);
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                printf(GREEN "\n Current Balance = Rs. %.2f\n" RESET, balance);
                pauseScreen();
                break;

            case 2:
                printf("\n Enter amount to deposit: ");
                scanf("%f", &amount);

                balance += amount;

                printf(GREEN "\n ✔ Amount Deposited Successfully!\n" RESET);
                pauseScreen();
                break;

            case 3:
                printf("\n Enter amount to withdraw: ");
                scanf("%f", &amount);

                if (amount > balance) {

                    printf(RED "\n ✘ Insufficient Balance!\n" RESET);

                } else {

                    balance -= amount;

                    printf(GREEN "\n ✔ Withdrawal Successful!\n" RESET);
                }

                pauseScreen();
                break;

            case 4:
                printf(GREEN "\n Thank You for Using ATM!\n" RESET);
                exit(0);

            default:
                printf(RED "\n Invalid Choice!\n" RESET);
                pauseScreen();
        }
    }

    return 0;
}