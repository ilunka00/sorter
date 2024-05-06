#include <stdio.h>
#include <stdlib.h>

#define LINE_MAX 16384

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

int isValidInteger(const char *str) {
    if (str == NULL || *str == '\0') return 0;

    while (*str) {
        if (*str < '0' || *str > '9') {
            return 0;
        }
        str++;
    }
    return 1;
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

    int *numbers = NULL;
    int numCount = 0;
    int capacity = 10;

    numbers = malloc(capacity * sizeof(int));
    if (numbers == NULL) {
        printf("Memory allocation failed\n");
        fclose(fNumbers);
        return 1;
    }

    char line[LINE_MAX];

    while (fgets(line, sizeof(line), fNumbers) != NULL) {
        if (numCount == capacity) {
            capacity *= 2;
            int *temp = realloc(numbers, capacity * sizeof(int));
            if (temp == NULL) {
                printf("Memory allocation failed\n");
                fclose(fNumbers);
                free(numbers);
                return 1;
            }
            numbers = temp;
        }

        int number;
        if (sscanf(line, "%d", &number) == 1)
            numbers[numCount++] = number;
    }

    fclose(fNumbers);

    insertionSort(numbers, numCount);

    for (int i = 0; i < numCount; i++) {
        printf("%d\n", numbers[i]);
    }

    free(numbers);

    return 0;
}
