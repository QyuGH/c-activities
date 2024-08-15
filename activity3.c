#include <stdio.h>

int main(){
    int array[5];

    printf("Enter five numbers: ");
    for (int i = 0; i < 5; i++){
        scanf("%d", &array[i]);
    }

    int maxNum = array[0];
    for (int i = 1; i < 5; i++){
        if (array[i] > maxNum){
            maxNum = array[i];
        }
    }

    printf("The highest number is: %d\n", maxNum);
    printf("Difference: ");
    for (int i = 0; i < 5; i++){
        printf("%d ", maxNum - array[i]);
    }

    return 0;
}
