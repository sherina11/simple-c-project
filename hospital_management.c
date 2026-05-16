#include <stdio.h>
#include <stdlib.h>

struct Patient {
    int id;
    char name[50];
};

struct Patient p[100];
int count = 0;

void addPatient() {
    printf("\nEnter Patient ID: ");
    scanf("%d", &p[count].id);

    printf("Enter Patient Name: ");
    scanf("%s", p[count].name);

    count++;

    printf("\nPatient Added Successfully!\n");
}

void displayPatients() {

    if(count == 0) {
        printf("\nNo patient records found!\n");
        return;
    }

    printf("\n--- Patient Records ---\n");

    for(int i = 0; i < count; i++) {
        printf("ID: %d | Name: %s\n",
               p[i].id,
               p[i].name);
    }
}

int main() {

    int choice;

    while(1) {

        printf("\n===== HOSPITAL MANAGEMENT SYSTEM =====\n");
        printf("1. Add Patient\n");
        printf("2. View Patients\n");
        printf("3. Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                addPatient();
                break;

            case 2:
                displayPatients();
                break;

            case 3:
                exit(0);

            default:
                printf("\nInvalid Choice!\n");
        }
    }

    return 0;
}