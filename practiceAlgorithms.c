#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

void sortArray();
void swapElements();
void reverseString();
void generateArray(int arr[], int n);
void selectionSort(int arr[], int n);
void getRandomNum(int arr[], int n, int random);

int main(){
    int n = 20000;
    int arr[n];
    int random = rand() % n;
    generateArray(arr, n);
    selectionSort(arr, n);
    getRandomNum(arr, n, 1997);
}

void sortArray(int arr[], int size){
    int temp;

    for (int i = 0; i < size; i++){
        for (int j = 0; j < size - i - 1; j++){
            temp = arr[j];

            if (arr[j+1] < arr[j]){
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void swapElements(int arr[], int size){
    for (int i = 0; i < size / 2; i++){
        int temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
}

void reverseString(char str[], int size){
    for (int i = 0; i < size / 2; i++){
        int temp = str[i];
        str[i] = str[size - i - 1];
        str[size - i - 1] = temp;
    }
}

void multiplicationTable(int num){

    printf("  ");
    for (int i = 0; i <= num; i++){
        printf("%d ", i);
    }

    printf("\n");
    for (int i = 0; i <= num; i++){
        printf("%d ", i);
        for (int j = 0; j <= num; j++){
            printf("%d ", j * i);
        }
        printf("\n");
    }
}


void generateArray(int arr[], int n){
    for (int i = 0; i < n; i+=2){
        arr[i] = rand() % n;
    }
}

void selectionSort(int arr[], int n){
    int min, temp;

    for (int i = 0; i < n - 1; i++){
        min = i;
        for (int j = i+1; j < n; j++){
            if (arr[i] > arr[j]){
                min = j;
            }
        }

        temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}

void getRandomNum(int arr[], int n, int random){
    int count = 0;
    for (int i = 0; i < n; i++){
        count++;
        if (arr[i] == random){
            printf("Value located at index %d, number of operations is: %d", i, count);
            return;
        }
    }
}
