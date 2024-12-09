#include <stdio.h>

int main(){
    int num1, num2;
    //--- declares pointer variable and setting it NULL ---//
    int *numPtr1 = NULL, *numPtr2 = NULL;

    //--- prompt for user to input value of num1 and num2 ---//
    printf("Input the first number: ");
    scanf("%d", &num1);
    printf("Input the second number: ");
    scanf("%d", &num2);

    //--- assigning pointer variables to point to variables that corresponds to their name ---//
    numPtr1 = &num1;
    numPtr2 = &num2;

    //--- using dereferencing for pointer variables to compare the value of num1 and num2 ---//
    //--- using dereferencing to print their value ---//
    if (*numPtr1 > *numPtr2){
        printf("%d is the Maximum Number.", (*numPtr1));
    }
    else {
        printf("%d is the Maximum Number.", (*numPtr2));
    }

    return 0;
}
