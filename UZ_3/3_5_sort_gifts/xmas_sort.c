#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Hilfsfunktion, die zwei Zahlen vertauscht
void swap(int* a, int* b) { 
    int temp = *a;
    *a = *b;
    *b = temp;
} 

void xmas_sort(int* array, const int n){
/*     if (n == 1){
        return;
    } */

    for (int i = 0; i < n-1; i += 0){
        if (array[i] > array[i+1]){
            swap(&array[i], &array[i+1]);
            if (i != 0) {
                i--;
            } else {
                i++;
            }
        } else {
            i++;
        }
    }

}