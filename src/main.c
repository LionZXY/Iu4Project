#include "stdio.h"
#include <stdlib.h>
#include "io/reader.h"

int compareInt(const int *firstVar, const int *twoVar) {
    return *firstVar - *twoVar;
}

void myqsort(int *array, int start, int end, int (*compare)(const int *firstVar, const int *twoVar)) {
    int i = start;
    int j = end;
    int middle = array[(start + end) / 2];
    int tmp;

    do {
        while (compare(&array[i], &middle) < 0) i++;
        while (compare(&array[j], &middle) > 0) j--;

        if (i <= j) {
            if (compare(&array[i], &array[j]) > 0) {
                tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
            }
            i++;
            j--;
        }
    } while (i <= j);

    if (i < end)
        myqsort(array, i, end, compare);
    if (start < j)
        myqsort(array, start, j, compare);
}

int main() {
    ArrayList list;
    printf("Введите числа:\n");
    if (getIntArray(&list) == EXIT_FAILURE) {
        return EXIT_FAILURE;
    }
    printf("Ваши числа:\n");
    for (int i = 0; i < list.realSize; i++) {
        printf("%d ", list.array[i]);
    }
    printf("\n");

    myqsort(list.array, 0, list.realSize - 1, &compareInt);

    for (int i = 0; i < list.realSize; i++) {
        printf("%d ", list.array[i]);
    }

    free(list.array);

    return EXIT_SUCCESS;
}


