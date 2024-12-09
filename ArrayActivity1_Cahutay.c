#include <stdio.h>

int main(){
    int array[5];
    int i;
    int x;
    int found = 0;

    //--- an array that stores the string to be used in the loop ---//
    char count[5][10] = {"first", "second", "third", "fourth", "fifth"};

    //--- loop to prompt user 5 numbers store in an array ---//
    for (i = 0; i < 5; i++){
        printf("Enter %s integer: ", count[i]);
        //--- The count[i] above, i only used the first dimension of the array because it access all the elements from the second dimension ---//
        //--- Because the first dimension holds the overall list of each list of the string array ---//
        scanf("%d", &array[i]);
    }

    //--- this prompts user to enter the number they want to search ---//
    printf("Enter an integer to be searched: ");
    scanf("%d", &x);

    //--- this for loop runs until the condition is true ---//
    //--- it will compare the value of array[j] to x, if they are equal then the code breaks ---//
    for (int j = 0; j < 5; j++){
        if (array[j] == x){
            printf("Integer is found in the array!");
            found++; //--- this will increment when if condition is true ---//
            break;
        }
    }

    /*
        if the code reached this point, then that means the condition from the code above wasn't
        satisfied setting found to 0 till the end, satisfying the condition below
    */
    if (found == 0){
        printf("Integer is not found in the array!");
    }

    return 0;

}
