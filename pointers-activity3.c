#include <stdio.h>

int main(){
    int size;
    printf("Input the number of elements to store in the array: ");
    scanf("%d", &size);

    int myArray[size];
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
}
