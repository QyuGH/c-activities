#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateArray(int arr[], int n);
void selectionSort(int arr[], int n);
void insertionSort(int arr[], int n);
void getRandomNum(int arr[], int n, int random);
void printArray(int arr[], int n);

int main() {
    int n = 80000;
    int arr[n];

    srand(time(0));

    //selection sort
    generateArray(arr, n);
    clock_t start = clock();
    selectionSort(arr, n);
    clock_t end = clock();
    double selectionTime = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken for selection sort is: %fseconds\n", selectionTime);


    generateArray(arr, n);
    start = clock();
    insertionSort(arr, n);
    end = clock();
    double insertionTime = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken for insertion sort is: %fseconds\n", insertionTime);



    return 0;
}

void generateArray(int arr[], int n) {
    for (int i = 1; i < n; i+=2) {
        arr[i] = rand() % n;
        if (i + 1 < n) {
            arr[i + 1] = rand() % n;
        }
    }
}

void selectionSort(int arr[], int n) {
    int min, temp;

    for (int i = 0; i < n - 1; i++) {
        min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[min] > arr[j]) {
                min = j;
            }
        }

        temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}

void insertionSort(int arr[], int n){
    for (int i = 1; i < n; i++){
        int insert = i;
        int currentVal = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > currentVal){
            arr[j + 1] = arr[j];
            insert = j;
            j--;
        }

        arr[insert] = currentVal;
    }
}

void getRandomNum(int arr[], int n, int random) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        count++;
        if (arr[i] == random) {
            printf("Value located at index %d, number of operations is: %d\n", i, count);
            return;
        }
    }
    printf("Value %d not found in the array, number of operations is: %d\n", random, count);
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

