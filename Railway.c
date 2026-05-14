#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Colors
#define RESET   "\033[0m"
#define GREEN   "\033[1;32m"
#define RED     "\033[1;31m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define CYAN    "\033[1;36m"

// Structure
struct Passenger {
    int seatNo;
    char name[50];
    char train[50];
};

struct Passenger p[100];
int count = 0;

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

// Book Ticket
void bookTicket() {

    printf("\n Enter Passenger Name : ");
    scanf("%s", p[count].name);

    printf(" Enter Train Name     : ");
    scanf("%s", p[count].train);

    p[count].seatNo = count + 1;

    printf(GREEN "\n ✔ Ticket Booked Successfully!\n" RESET);
    printf(GREEN " Seat Number: %d\n" RESET, p[count].seatNo);

    count++;
}

// Display Reservations
void displayTickets() {

    if (count == 0) {
        printf(RED "\n No reservations found!\n" RESET);
        return;
    }

    line();

    for (int i = 0; i < count; i++) {

        printf(" Seat No : %d\n", p[i].seatNo);
        printf(" Name    : %s\n", p[i].name);
        printf(" Train   : %s\n", p[i].train);

        line();
    }
}

// Main
int main() {

    int choice;

    while (1) {

        system("cls || clear");

        title("RAILWAY RESERVATION SYSTEM");

        printf(YELLOW " 1. Book Ticket\n" RESET);
        printf(YELLOW " 2. View Reservations\n" RESET);
        printf(YELLOW " 3. Exit\n" RESET);

        line();

        printf(CYAN " Enter your choice: " RESET);
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                bookTicket();
                pauseScreen();
                break;

            case 2:
                displayTickets();
                pauseScreen();
                break;

            case 3:
                printf(GREEN "\n Thank You!\n" RESET);
                exit(0);

            default:
                printf(RED "\n Invalid Choice!\n" RESET);
                pauseScreen();
        }
    }

    return 0;
}