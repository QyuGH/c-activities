#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

#define SIZE 100

struct Phonebook {
    char name[50];
    char contactNum[13];
};

struct Phonebook contact[SIZE];
int totalContact = 0;

//print options
void options(){
    char *optionArr[6] = {"Add Entry","View Entry","Edit Entry","Delete Entry","Search Entry","Exit"};

    printf("Press: \n");
    for (int i = 0; i < 6; i++){
        printf("%d. %s\n", i+1, optionArr[i]);
    }
}

//function to be called in add contact function, returns 0 if name is available
int checkName(char name[]){
    int result;
    for (int i = 0; i < totalContact; i++){
        result = strcmp(name, contact[i].name);
        if (result == 0){
            return 1;
        }
    }
    return 0;
}

//function to check validity of number, returns 1 if number is valid
int checkNum(char contactNum[]){
    int numLength = strlen(contactNum);

    if (numLength == 11 || numLength == 12) {
        char firstDigit = contactNum[0];
        char secondDigit = contactNum[1];
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

//to check duplicate of number, returns 1 if no duplicate
int noDuplicate(char contactNum[]){
    int result;

    for (int i = 0; i < totalContact; i++){
        result = strcmp(contactNum, contact[i].contactNum);
        if (result == 0){
            return 0;
        }
    }

    return 1;
}

//add contact function
void addContact(){
    getchar();
    int validName, validNum, duplicateNum;

    if (totalContact < SIZE){

        do{
            printf("Enter name:\n");
            fgets(contact[totalContact].name, sizeof(contact[totalContact].name), stdin);
            contact[totalContact].name[strcspn(contact[totalContact].name, "\n")] = 0;

            validName = checkName(contact[totalContact].name);

            if (validName){
                printf("Name already exists. Please enter a new one.\n");
                getch();
                system("cls");
            }
        }while(validName);

        do{
            printf("Enter contact number: \n");
            fgets(contact[totalContact].contactNum, sizeof(contact[totalContact].contactNum), stdin);
            contact[totalContact].contactNum[strcspn(contact[totalContact].contactNum, "\n")] = 0;

            validNum = checkNum(contact[totalContact].contactNum);
            duplicateNum = noDuplicate(contact[totalContact].contactNum);

            if (validNum && duplicateNum) {
                break;
            } else {
                if (!validNum) {
                    printf("Invalid contact number. Please enter a valid one.\n");
                    getch();
                    system("cls");
                }
                if (!duplicateNum) {
                    printf("Contact number already exists. Please enter a new one.\n");
                    getch();
                    system("cls");
                }
            }
        }while(1);

        totalContact++;
    }
    else {
        printf("Your phonebook is full.\n");
    }
}

//view contacts function
void viewContact(){
     if (totalContact == 0){
        printf("No available contacts yet.\n");
        return;
    }
    else {
        for (int i = 0; i < totalContact; i++){
            printf("Contact %d\n", i+1);
            printf("Name: %s\n", contact[i].name);
            printf("Contact Number: %s\n\n", contact[i].contactNum);
        }
    }

    printf("Press any key to continue...\n");
    getch();
    system("cls");
    return;
}

int main(){
    int choice;
    int result;
    do{
        options();
        scanf("%d", &choice);
        system("cls");

        switch(choice){
            case 1:
                addContact();
                break;
            case 2:
                viewContact();
                break;
            default:
                break;
        }
    }while(choice != 6);

    return 0;
}
