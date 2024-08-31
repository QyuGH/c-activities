#include <stdio.h>

void printRectangle(){
    for (int i = 1; i <= 5; i++){
        for (int j = 1; j <= 10; j++){
            printf("* ");
        }
        printf("\n");
    }
}

void printSquare(){
    for (int i = 1; i <= 8; i++){
        for (int j = 1; j <= 8; j++){
            printf("* ");
        }
        printf("\n");
    }
}

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

    printf("\"Drawing and Solving using Function\"\n");
    printf("1. RECTANGLE\n");
    printf("2. SQUARE\n");
    printf("3. TRIANGLE\n");
    printf("Enter your choice: ");
    scanf("%d", &shapeChoice);


    int rectangleHeight, rectangleWidth;
    int sideLength;
    int base, triangleHeight;
    switch (shapeChoice){
        case 1:
            printRectangle();
            printf("Enter width: ");
            scanf("%d", &rectangleWidth);
            printf("Enter height: ");
            scanf("%d", &rectangleHeight);
            printf("Area of Rectangle is: %d", (rectangleHeight * rectangleWidth));
            break;
        case 2:
            printSquare();
            printf("Enter side length: ");
            scanf("%d", &sideLength);
            printf("Area of Square: %d", (sideLength * sideLength));
            break;
        case 3:
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
