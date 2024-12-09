#include <stdio.h>

int main(){
    int size;

    //--- this code prompts the user to input a number that will be assigned as the size of the array ---//
    printf("Input the number of elements to store in the array: ");
    scanf("%d", &size);

    printf("Input %d number of elements in the array: \n", size);
    int myArray[size]; //--- assigned value of size variable as the size of array ---//
    for (int i = 0; i < size; i++){
        printf("Element - %d: ", i);
        scanf("%d", &myArray[i]);
    }

    int *arrPtr[size];
    for (int i = 0; i < size; i++){
        arrPtr[i] = &myArray[i];
    }

    printf("The elements you entered are: \n");
    for (int i = 0; i < size; i++){
        printf("Element - %d: %d\n", i, *arrPtr[i]);
    }

    return 0;
}
