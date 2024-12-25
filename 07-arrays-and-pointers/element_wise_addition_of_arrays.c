#include <stdio.h>

// Function to add two arrays element-wise
void addarrays(int array1[], int array2[], int size) {
    int array3[size]; // Resultant array to store the sum
    for (int i = 0; i < size; i++) {
        array3[i] = array1[i] + array2[i];
    }

    // Print the resultant array
    for (int j = 0; j < size; j++) {
        printf("%d ", array3[j]);
    }
    printf("\n");
}

int main(void) {
    int array1[3] = {1, 2, 3};
    int array2[3] = {4, 5, 6};

    int size = sizeof(array1) / sizeof(array1[0]);
    addarrays(array1, array2, size);
    return 0;
}
