#include <stdio.h>

int main(){
    int array[5];

     //--- for loop to prompt 5 numbers to store in array ---//
    printf("Enter five numbers: \n");
    for (int i = 0; i < 5; i++){
        scanf("%d", &array[i]);
    }

    //--- assigned the first element to maxNum ---//
    int maxNum = array[0];

    //--- loop from the second index until last, comparing it to maxNum ---//
    //--- reassigns maxNum if a specific element is greater than the current maxNum ---//
    for (int i = 1; i < 5; i++){
        if (array[i] > maxNum){
            maxNum = array[i];
        }
    }

    printf("The highest number is: %d\n", maxNum);
    printf("Difference: ");

    //--- looping code that deducts maxNum to each value of every array index ---//
    for (int i = 0; i < 5; i++){
        printf("%d ", maxNum - array[i]);
    }

    return 0;
}
