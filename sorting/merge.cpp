#include <iostream>
#include <stdlib.h>

int* copy(int *array, int start, int end) {
    int outlen = end-start;
    int *out = (int*) malloc(outlen * sizeof(int));
    for (int i = 0; i < outlen; i++) {
        out[i] = array[start+i];
    }
    return out;
}

int max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

int* merge(int *a, int *b, int na, int nb) {
    int *out = (int*) malloc((na+nb)*sizeof(int));
    int ia = 0;
    int ib = 0;
    for (int i = 0; i < (na+nb); i++) {
        if (ia == na) {
            out[i] = b[ib];
            ib++;
        }
        else if (ib == nb) {
            out[i] = a[ia];
            ia++;
        }
        else if (a[ia] > b[ib]) {
            out[i] = a[ia];
            ia++;
        }
        else {
            out[i] = b[ib];
            ib++;
        }
    }
    return out;
}

int* mergeSort(int *array, int n) {
    if (n > 1) {
        int middle = n / 2;
        int *a = copy(array, 0, middle);
        int *b = copy(array, middle, n);
        int *outa = mergeSort(a, middle);
        int *outb = mergeSort(b, n-middle);
        int *out = merge(outa, outb, middle, n-middle);
        return out;
    }
    return array;
}

int main() {
    int array[8] = {5, 2, 56, 7, 1, 4, 3, 8};
    int *out = mergeSort(array, 8);
    for (int i = 0; i < 8; i++) {
        std::cout << out[i] << ' ';
    }
    std::cout << std::endl;
    return 0;
}