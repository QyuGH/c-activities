#include <stdio.h>

int main(){
    int num1, num2;

    //--- declaring pointer variables and setting it NULL ---//
    int *num1Ptr = NULL;
    int *num2Ptr = NULL;

    //--- prompt user for value of num1 and num2 ---//
    printf("Input the first number: ");
    scanf("%d", &num1);
    printf("Input the second number: ");
    scanf("%d", &num2);

    //--- assign both pointer variables to point to each variable corresponding to their name ---//
    num1Ptr = &num1;
    num2Ptr = &num2;
    //--- using dereferencing for both pointers to add value of num1 and num2 ---//
    printf("The sum of the entered numbers is: %d\n", (*num1Ptr + *num2Ptr));

    return 0;
}

