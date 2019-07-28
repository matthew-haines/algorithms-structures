#include <iostream>
#include <stdlib.h>
#include <time.h>

void printArray(int *array, int n) {
    for (int i = 0; i < n; i++) {
        std::cout << array[i] << ' ';
    }
    std::cout << std::endl;
}

int* concatenate(int *big, int *small, int nb, int ns) {

    int *out = (int*) malloc((ns+nb)*sizeof(int));
    for (int i = 0; i < nb; i++) {
        out[i] = big[i];
    }
    for (int i = 0; i < ns; i++) {
        out[i+nb] = small[i];
    }
    return out;
}

int* quickSort(int *array, int n) {
    if (n > 1) {
        int *less = (int*) malloc(n*sizeof(int));
        int *more = (int*) malloc(n*sizeof(int));
        int *pivot = (int*) malloc(n*sizeof(int));
        pivot[0] = array[rand() % n];
        int nless = 0;
        int nmore = 0;
        int npivot = 1;
        for (int i = 0; i < n; i++) {
            if (array[i] < pivot[0]) {
                less[nless] = array[i];
                nless++;
            }
            else if (array[i] > pivot[0]) {
                more[nmore] = array[i];
                nmore++;
            }
            else {
                pivot[npivot] = array[i];
                npivot++;
            }
        }
        if (nmore == 0) {
            return concatenate(pivot, quickSort(less, nless), npivot, nless);
        }
        else if (nless == 0) {
            return concatenate(quickSort(more, nmore), pivot, nmore, npivot);
        }

        return concatenate(concatenate(quickSort(more, nmore), pivot, nmore, npivot), quickSort(less, nless), nmore+npivot-1, nless);
    }
    return array;
}

int main() {
    srand(time(NULL));
    int array[6] = {5, 3, 2, 7, 9, 2};
    int *out = quickSort(array, 6);
    printArray(out, 6);
    return 0;
}