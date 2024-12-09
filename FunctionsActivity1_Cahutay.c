#include <stdio.h>
//--- For more info, check my github: https://github.com/QyuGH/c-activities.git ---//

//---The first loop in the function below determines the height of the rectangle---//
//---Everytime its condition is satisfied, it runs through the second for loop to print the width of the rectangle---//
void printRectangle(){
    for (int i = 1; i <= 5; i++){
        for (int j = 1; j <= 10; j++){
            printf("* ");
        }
        printf("\n");
    }
}

//---This behaves the same as the printRectangle function---//
//---Since it is a square, I've set its condition to run until the width and height are both 8---//
void printSquare(){
    for (int i = 1; i <= 8; i++){
        for (int j = 1; j <= 8; j++){
            printf("* ");
        }
        printf("\n");
    }
}

//---The first loop/outer loop of this code behaves the same (determines the height) as the function above---//
//---The first inner loop adds spaces first before the "*" to get the clean triangle output---//
//---The second inner loop then prints the "*" after all the spaces are added from the first inner loop---//
void printTriangle(){
    for (int i = 1; i <= 5; i++){
        for (int j = 1; j <= 5 - i; j++){
            printf(" ");
        }

        for (int k = 1; k <= i * 2 - 1; k++){
            printf("*");
        }

        printf("\n");
    }
}

int main(){
    int shapeChoice;

    //---code to prompt user to choose shapes---//
    printf("\"Drawing and Solving using Function\"\n");
    printf("1. RECTANGLE\n");
    printf("2. SQUARE\n");
    printf("3. TRIANGLE\n");
    printf("Enter your choice: ");
    scanf("%d", &shapeChoice);


    int rectangleHeight, rectangleWidth;
    int sideLength;
    int base, triangleHeight;

    //--- calling the functions based from the user's choice inside the switch statement ---//
    //--- I did not create a seperate function of the formula for solving the shapes' area ---//
    //--- I just solved it right away then printing its result ---//
    switch (shapeChoice){
        case 1:
            printf("You've Chosen Rectangle!\n");
            printRectangle();
            printf("Enter width: ");
            scanf("%d", &rectangleWidth);
            printf("Enter height: ");
            scanf("%d", &rectangleHeight);
            printf("Area of Rectangle is: %d", (rectangleHeight * rectangleWidth));
            break;
        case 2:
            printf("You've Chosen Square!\n");
            printSquare();
            printf("Enter side length: ");
            scanf("%d", &sideLength);
            printf("Area of Square: %d", (sideLength * sideLength));
            break;
        case 3:
            printf("You've Chosen Triangle!\n");
            printTriangle();
            printf("Enter base: ");
            scanf("%d", &base);
            printf("Enter height: ");
            scanf("%d", &triangleHeight);
            printf("Area of Rectangle is: %.2f", ((float)triangleHeight * (float)base) / 2);
            break;
        default:
            break;
    }

    return 0;
}
