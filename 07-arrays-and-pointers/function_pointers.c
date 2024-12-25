#include <stdio.h>

// Function to add two integers
int sum_func(int a, int b) {
    return a + b;
}

// Function to multiply two integers
int prod_func(int a, int b) {
    return a * b;
}

// Function to subtract the second integer from the first
int sub_func(int a, int b) {
    return a - b;
}

int main(void) {
    // Array of function pointers storing references to the above functions
    int (*operations[3])(int, int) = {sum_func, prod_func, sub_func};
    int a = 7, b = 5;

    // Loop through the array of function pointers and call each function
    for (int i = 0; i < 3; i++) {
        printf("Result: %d\n", operations[i](a, b));
    }
    return 0;
}
