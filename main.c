#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMBERS 1000

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Add filename please:\n%s <filename>\n", argv[0]);
        return 1;
    }

    FILE *fNumbers = fopen(argv[1], "r");
    if (fNumbers == NULL) {
        printf("Could not open the file\n");
        return 1;
    }

    int numbers[MAX_NUMBERS];
    int numCount = 0;

    while (fscanf(fNumbers, "%d", &numbers[numCount]) != EOF && numCount < MAX_NUMBERS) {
        numCount++;
    }

    fclose(fNumbers);

    insertionSort(numbers, numCount);

    for (int i = 0; i < numCount; i++) {
        printf("%d\n", numbers[i]);
    }

    return 0;
}
