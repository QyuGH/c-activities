#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

#define SIZE 100

struct Phonebook {
    char name[50];
    char contactNum[15];
};

struct Phonebook contact[SIZE];
int totalContact = 0;

void options();
void loopAdd();
void viewContact();
void editContact();
void deleteContact();
void searchEntry();

int main(){
    int choice;

    do{
        options();
        scanf("%d", &choice);

        switch(choice){
            case 1:
                loopAdd();
                break;
            case 2:
                viewContact();
                break;
            case 3:
                editContact();
                break;
            case 4:
                deleteContact();
                break;
            case 5:
                searchEntry();
                break;
            default:
                break;
        }
    }while(choice != 6);

    return 0;
}

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
        if (numLength == 11 && contactNum[0] == '0' && contactNum[1] == '9') {
            return 1;
        }
        else if (numLength == 12 && contactNum[0] == '6' && contactNum[1] == '3' && contactNum[2] == '9') {
            return 1;
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
                    printf("Invalid contact number, please enter a valid one.\n");
                }
                if (!duplicateNum) {
                    printf("Contact number already exists, please enter a new one.\n");
                }
            }
        }while(1);

        totalContact++;
    }
    else {
        printf("Your phonebook is full.\n");
    }
}

//function calling add and loops through it
void loopAdd(){
    char choice;

    do {
        addContact();
        printf("Entry Successfully Added! Another Process? Y or N\n");
        scanf(" %c", &choice);

        if (choice == 'Y' || choice == 'y'){
            continue;
        }
        else if (choice == 'N' || choice == 'n') {
            break;
        }
        else {
            printf("Invalid choice\n");
            break;
        }
    }while(choice == 'Y' || choice == 'y');
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
    return;
}

//function to search and view contact
void searchEntry(){
    int result, found = 0;
    char nameSearch[50];

    if (totalContact == 0){
        printf("No available contacts yet.\n");
        return;
    }

    printf("Enter name to be searched: \n");
    getchar();
    fgets(nameSearch, sizeof(nameSearch), stdin);
    nameSearch[strcspn(nameSearch, "\n")] = 0;

    for (int i = 0; i < totalContact; i++){
        result = strcmp(nameSearch, contact[i].name);
        if (result == 0){
            printf("Contact %d\n", i+1);
            printf("Name: %s\n", contact[i].name);
            printf("Contact Number: %s\n", contact[i].contactNum);
            found++;
            break;
        }
    }
    if (!found){
        printf("Contact does not exist.\n");
    }
}

// Edit contact function
void editContact() {
    char nameToEdit[50];
    int contactIndex = -1;

    if (totalContact == 0){
        printf("No available contacts yet.\n");
        return;
    }

    printf("Enter the name of the contact you want to edit: \n");
    getchar();
    fgets(nameToEdit, sizeof(nameToEdit), stdin);
    nameToEdit[strcspn(nameToEdit, "\n")] = 0;
    // Find the contact index
    for (int i = 0; i < totalContact; i++) {
        if (strcmp(nameToEdit, contact[i].name) == 0) {
            contactIndex = i;
            break;
        }
    }

    if (contactIndex == -1) {
        printf("Contact not found.\n");
        return;
    }

    // Prompt user for new details
    char newName[50];
    char newContactNum[15];
    int validNum, duplicateNum;

    printf("Enter new name (leave blank to keep current name):\n");
    fgets(newName, sizeof(newName), stdin);
    newName[strcspn(newName, "\n")] = 0; // Remove trailing newline

    // Only update name if new name is provided
    if (strlen(newName) > 0) {
        if (checkName(newName)) {
            printf("Name already exists. Please enter a different name.\n");
            return;
        }
        strcpy(contact[contactIndex].name, newName);
    }

    printf("Enter new contact number (leave blank to keep current number):\n");
    fgets(newContactNum, sizeof(newContactNum), stdin);
    newContactNum[strcspn(newContactNum, "\n")] = 0; // Remove trailing newline

    // Only update contact number if new number is provided
    if (strlen(newContactNum) > 0) {
        validNum = checkNum(newContactNum);
        duplicateNum = noDuplicate(newContactNum);

        if (validNum && duplicateNum) {
            strcpy(contact[contactIndex].contactNum, newContactNum);
        } else {
            if (!validNum) {
                printf("Invalid contact number.\n");
            }
            if (!duplicateNum) {
                printf("Contact number already exists.\n");
            }
            return;
        }
    }

    printf("Contact updated successfully.\n");
}

void deleteContact(){
    char nameDelete[50];
    int index = -1;

    if (totalContact == 0){
        printf("No available contacts yet.\n");
        return;
    }

    printf("Enter the name you want to delete.\n");
    getchar();
    fgets(nameDelete, sizeof(nameDelete), stdin);
    nameDelete[strcspn(nameDelete, "\n")] = 0;

    for (int i = 0; i < totalContact; i++){
        if (strcmp(nameDelete, contact[i].name) == 0){
            index = i;
            break;
        }
    }

    if (index == -1){
        printf("Contact does not exist.\n");
        return;
    }

    for (int i = index; i < totalContact - 1; i++){
        strcpy(contact[i].name, contact[i+1].name);
        strcpy(contact[i].contactNum, contact[i+1].contactNum);
    }

    printf("Contact deleted successfully.\n");
    totalContact--;
}

