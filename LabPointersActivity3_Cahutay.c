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
        scanf("%d", &myArray[i]); //--- scanning each input and assigned to every index of myArray ---//
    }

    //--- below is a pointer array, each of its index will point to each index of another array ---//
    int *arrPtr[size];
    for (int i = 0; i < size; i++){
        arrPtr[i] = &myArray[i]; //--- assigning every index or arrPtr to point to each index of myArray ---//
    }

    //--- below is a for loop that runs until it reached the number of size - 1 ---//
    printf("The elements you entered are: \n");
    for (int i = 0; i < size; i++){
        //--- it then prints every value of the index from the arrPtr ---//
        //--- used dereference to access the value of their pointed index ---//
        printf("Element - %d: %d\n", i, *arrPtr[i]);
    }

    return 0;
}
