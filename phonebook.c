#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

#define CONTACT_SIZE 100

struct Contact{
    char name[50];
    char phoneNumber[15];
};

struct Contact phoneBook[CONTACT_SIZE];
int contactCount = 0;


int main(){
    int choice;
    char *choices[6] = {"Add Entry", "View Entry", "Edit Entry", "Delete Entry", "Search Entry", "Exit"};
    char processChoice;

    do{
        printf("Press: \n");
        for (int i = 0; i < 6; i++){
            printf("%d. %s\n", i+1, choices[i]);
        }
        scanf("%d", &choice);
        system("cls");

        switch(choice){
            case 1:
                do {
                    addContact();
                    printf("Entry Successfully Added! Another Process? Y or N\n");
                    scanf(" %c", &processChoice);
                    if (processChoice == 'Y' || processChoice == 'y'){
                        system("cls");
                        continue;
                    }
                    else if (processChoice == 'N' || processChoice == 'n'){
                        system("cls");
                        break;
                    }
                    else {
                        printf("Invalid choice.\n");
                        break;
                    }
                }while(processChoice != 'n' || processChoice != 'N');
                break;

            case 2:
                viewEntry();
                break;

            default:
                break;
        }

    }while(choice != 6);

    return 0;

}

//function to validate name
int validName(char name[50]){
    for (int i = 0; i < contactCount; i++){
        int result = strcmp(name, phoneBook[i].name);
        if (result == 0){
            return 1;
        }
    }
    return 0;
}
//function to validate phone number
int validNumber(char phoneNumber[]){
    int numLength = strlen(phoneNumber);

    if (numLength == 11 || numLength == 12) {
        char firstDigit = phoneNumber[0];
        char secondDigit = phoneNumber[1];
        if (numLength == 11) {
            if (firstDigit == '0' && secondDigit == '9') {
                return 1;
            }
        }
        else if (numLength == 12) {
            if (firstDigit == '6' && secondDigit == '3') {
                return 1;
            }
        }
    }
    return 0;
}
int numDuplicate(char num[]){
    for (int i = 0; i < contactCount; i++){
        int result = strcmp(num, phoneBook[i].phoneNumber);
        if (result == 0){
            return 1;
        }
    }
    return 0;
}

//function to add contact
void addContact(){
    getchar();
    if (contactCount < CONTACT_SIZE){
        int valid, validNum, numCopy;
        do{
            printf("Enter Name: \n");
            fgets(phoneBook[contactCount].name, sizeof(phoneBook[contactCount].name), stdin);
            phoneBook[contactCount].name[strcspn(phoneBook[contactCount].name, "\n")] = 0;

            valid = validName(phoneBook[contactCount].name);

            if (valid == 1){
                printf("Name already exists. Please try again.\n");
                getch();
                system("cls");
            }
        }while(valid != 0);

        do {
            printf("Enter Contact Number: \n");
            fgets(phoneBook[contactCount].phoneNumber, sizeof(phoneBook[contactCount].phoneNumber), stdin);
            phoneBook[contactCount].phoneNumber[strcspn(phoneBook[contactCount].phoneNumber, "\n")] = 0;

            validNum = validNumber(phoneBook[contactCount].phoneNumber);
            numCopy = numDuplicate(phoneBook[contactCount].phoneNumber);
            if (validNum == 1 && numCopy == 0) {
                break;
            } else {
                if (validNum == 0) {
                    printf("Invalid number. Please try again.\n");
                } else {
                    printf("Number already exists. Please try again.\n");
                }
                getch();
                system("cls");
            }
        } while (1);

        contactCount++;
    }
    else {
        printf("Your Phonebook is Full");
        return;
    }
}

//function to view added contacts
void viewEntry(){
    if (contactCount == 0){
        printf("No available contacts yet.\n");
        return;
    }
    else {
        for (int i = 0; i < contactCount; i++){
            printf("Contact %d\n", i+1);
            printf("Name: %s\n", phoneBook[i].name);
            printf("Contact Number: %s\n\n", phoneBook[i].phoneNumber);
        }
    }

    printf("Press any key to continue...\n");
    getch();
    system("cls");
    return;
}
