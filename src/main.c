#include "stdio.h"
#include <stdlib.h>
#include "io/reader.h"

int countingSort(ArrayList *list, int k) {
    size_t arraysize = (size_t) (k + 1);
    int *countArray = calloc(arraysize, sizeof(int));
    for (int i = 0; i < list->realSize; i++) {
        if (list->array[i] > k) {
            free(countArray);
            printf("Число %d больше максимального\n", list->array[i]);
            return EXIT_FAILURE;
        }
        countArray[list->array[i]]++;
    }

    size_t arrayPos = 0;
    for (int i = 0; i < arraysize; i++) {
        for (size_t j = 0; j < countArray[i]; j++) {
            list->array[arrayPos++] = i;
        }
    }
    return EXIT_SUCCESS;
}

int main() {
    int maxInputDigital = 0;
    printf("Введите максимальное число в множестве:\n");
    if (scanf("%d", &maxInputDigital) != 1) {
        printf("Фигня какая-то... Ты точно все правильно ввел?\n");
        return EXIT_FAILURE;
    }
    getchar();


    ArrayList list;
    printf("Введите числа:\n");
    if (getIntArray(&list) == EXIT_FAILURE) {
        return EXIT_FAILURE;
    }

    if(countingSort(&list, maxInputDigital) == EXIT_SUCCESS){
        for(int i = 0; i < list.realSize; i++){
            printf("%d ", list.array[i]);
        }
    }
    free(list.array);


    return EXIT_SUCCESS;
}


