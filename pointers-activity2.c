#include <stdio.h>

int main(){
    int num1, num2;
    int *numPtr1 = NULL, *numPtr2 = NULL;

    printf("Input the first number: ");
    scanf("%d", &num1);
    printf("Input the second number: ");
    scanf("%d", &num2);

    numPtr1 = &num1;
    numPtr2 = &num2;

    if (*numPtr1 > *numPtr2){
        printf("%d is the Maximum Number.", (*numPtr1));
    }
    else {
        printf("%d is the Maximum Number.", (*numPtr2));
    }
}
