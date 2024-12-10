#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateArray(int arr[], int n);
void selectionSort(int arr[], int n);
void insertionSort(int arr[], int n);
void getRandomNum(int arr[], int n, int random);
void printArray(int arr[], int n);

int main() {
    int n = 80000; //--- size of the array ---//
    int arr[n];

    srand(time(0)); //--- seeds the random number generator for different results each run ---//

    //--- measure time for selection sort ---//
    generateArray(arr, n); //--- initialize the array with random numbers ---//
    clock_t start = clock(); //--- start clock ---//
    selectionSort(arr, n);
    clock_t end = clock(); //--- stop clock ---//
    double selectionTime = (double)(end - start) / CLOCKS_PER_SEC; //--- calculate elapsed time ---//
    printf("Time taken for selection sort is: %.2fmilliseconds\n", selectionTime * 1000);

    //--- measure time for insertion sort ---//
    generateArray(arr, n); //--- reinitialize the array to ensure fairness ---//
    start = clock(); //--- start clock ---//
    insertionSort(arr, n);
    end = clock(); //--- stop clock ---//
    double insertionTime = (double)(end - start) / CLOCKS_PER_SEC; //--- calculate elapsed time ---//
    printf("Time taken for insertion sort is: %.2fmilliseconds\n", insertionTime * 1000);

    return 0;
}

//--- fills the array with random integers between 0 and n-1 ---//
void generateArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % n; //--- generate random number within range of n ---//
    }
}

//--- sorts the array using Selection Sort ---//
void selectionSort(int arr[], int n) {
    int min, temp;

    for (int i = 0; i < n - 1; i++) {
        min = i; //--- assume the current element is the smallest ---//
        for (int j = i + 1; j < n; j++) {
            if (arr[min] > arr[j]) { //--- find the actual smallest element in the unsorted portion ---//
                min = j;
            }
        }

        //--- swap the smallest element with the current element ---//
        temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}

//--- sorts the array using Insertion Sort ---//
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int insert = i; //--- initial position for inserting the current value ---//
        int currentVal = arr[i];
        int j = i - 1;

        //--- shift larger elements to the right to make space ---//
        while (j >= 0 && arr[j] > currentVal) {
            arr[j + 1] = arr[j];
            insert = j; //--- track where the current value will be inserted ---//
            j--;
        }

        arr[insert] = currentVal; //--- place the current value in its correct position ---//
    }
}

//--- this function is uncalled in the main function ---//
//--- only used for testing the operations to find a specific value in an array ---//
//--- searches for a specific value and counts operations ---//
void getRandomNum(int arr[], int n, int random) {
    int count = 0; //--- variable that counts each operation ---//
    for (int i = 0; i < n; i++) {
        count++;
        if (arr[i] == random) { //--- value found ---//
            printf("Value located at index %d, number of operations is: %d\n", i, count);
            return;
        }
    }
    //--- value not found after scanning the array ---//
    printf("Value %d not found in the array, number of operations is: %d\n", random, count);
}

//--- prints all elements of the array ---//
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
