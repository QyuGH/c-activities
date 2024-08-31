#include <stdio.h>

int main(){
    int array[5];
    int i;
    int x;
    int found = 0;
    char count[5][10] = {"first", "second", "third", "fourth", "fifth"};

    for (i = 0; i < 5; i++){
        printf("Enter %s integer: ", count[i]);
        scanf("%d", &array[i]);
    }

    printf("Enter an integer to be searched: ");
    scanf("%d", &x);

    for (int j = 0; j < 5; j++){
        if (array[j] == x){
            printf("Integer is found in the array!");
            found++;
            break;
        }
    }

    if (found == 0){
        printf("Integer is not found in the array!");
    }

    return 0;

}
