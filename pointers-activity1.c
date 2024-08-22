#include <stdio.h>

int main(){
    int num1, num2;
    int *num1Ptr = NULL;
    int *num2Ptr = NULL;

    printf("Input the first number: ");
    scanf("%d", &num1);
    printf("Input the second number: ");
    scanf("%d", &num2);

    num1Ptr = &num1;
    num2Ptr = &num2;
    printf("The sum of the entered numbers is: %d", (*num1Ptr + *num2Ptr));

    return 0;
}

