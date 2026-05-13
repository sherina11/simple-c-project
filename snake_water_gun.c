#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

// Main
int main() {

    int userChoice, computerChoice;

    srand(time(0));

    system("cls || clear");

    title("SNAKE WATER GUN GAME");

    printf(YELLOW " 1. Snake\n" RESET);
    printf(YELLOW " 2. Water\n" RESET);
    printf(YELLOW " 3. Gun\n" RESET);

    line();

    printf(CYAN " Enter your choice: " RESET);
    scanf("%d", &userChoice);

    computerChoice = (rand() % 3) + 1;

    printf("\n");

    // Display computer choice
    if (computerChoice == 1)
        printf(" Computer chose: Snake\n");

    else if (computerChoice == 2)
        printf(" Computer chose: Water\n");

    else
        printf(" Computer chose: Gun\n");

    // Game Logic
    if (userChoice == computerChoice) {

        printf(YELLOW "\n It's a Draw!\n" RESET);

    } else if (
        (userChoice == 1 && computerChoice == 2) ||
        (userChoice == 2 && computerChoice == 3) ||
        (userChoice == 3 && computerChoice == 1)
    ) {

        printf(GREEN "\n ✔ You Win!\n" RESET);

    } else {

        printf(RED "\n ✘ Computer Wins!\n" RESET);
    }

    line();

    return 0;
}