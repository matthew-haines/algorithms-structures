#include <iostream>

void bubbleSort(int *array, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = n-1; j > i; j--) {
            if (array[j] > array[j-1]) {
                int temp = array[j];
                array[j] = array[j-1];
                array[j-1] = temp;
            }
        }
    }
}