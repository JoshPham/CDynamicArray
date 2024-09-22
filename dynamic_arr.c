#include <stdio.h>
#include <stdlib.h>

void print_arr(int size, int* arrPtr);

int main() {
    int size;
    printf("Enter the length of the array: ");
    scanf("%d", &size);

    int* arrPtr = (int*) malloc(size * sizeof(int));

    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    for (int i = 0; i < size; i++) {
        int num;
        printf("Enter element %d/%d: ", i+1, size);
        scanf("%d", &num);

        *(arrPtr + i) = num;

        while ((c = getchar()) != '\n' && c != EOF);
    }


    printf("Resulting array: ");
    print_arr(size, arrPtr);

    int index;

    while (index >= -1) {
        printf("Enter index of element of array (0-%d): ", size-1);
        scanf("%d", &index);

        if (index == -1) {
            print_arr(size, arrPtr);
        }

        if (index >= size) {
            printf("Index is out of range (Size: %d)\n\n", size);
            continue;
        }

        (index > 0) && printf("Element at index %d: %d\n", index, *(arrPtr + index));

        printf("Type -1 if you want to see the full array again\n and -2 or less if you want to exit program.\n\n");
    }

    printf("Exiting program...\n");
    

    return 0;
}

void print_arr(int size, int* arrPtr) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", *(arrPtr+i));
        (i < size - 1) && printf(", ");
    }
    printf("]\n");
}