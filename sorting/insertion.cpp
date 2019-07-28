#include <iostream>

void insertionSort(int *array, int n) {
    for (int i = 1; i < n; i++) {
        int cur = array[i];
        int j = i - 1;
        while (j > -1 && cur > array[j]) {
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = cur;
    }
}

int main() {
    int array[6] = {6, 2, 7, 8, 3, 4};
    insertionSort(array, 6);
    for (int i = 0; i < 6; i++) {
        std::cout << array[i];
    }
    std::cout << std::endl;
}