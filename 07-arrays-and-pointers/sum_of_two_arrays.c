#include <stdio.h>

// Function to compute the sum of two arrays
int sumarrays(int array1[], int array2[], int size1, int size2) {
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < size1; i++) {
        sum1 += array1[i];
    }

    for (int j = 0; j < size2; j++) {
        sum2 += array2[j];
    }

    return sum1 + sum2;
}

int main(void) {
    int array1[3] = {1, 2, 3};
    int array2[3] = {4, 5, 6};

    int size1 = sizeof(array1) / sizeof(array1[0]);
    int size2 = sizeof(array2) / sizeof(array2[0]);

    int result = sumarrays(array1, array2, size1, size2);
    printf("The sum of the two arrays is: %d\n", result);
    return 0;
}
