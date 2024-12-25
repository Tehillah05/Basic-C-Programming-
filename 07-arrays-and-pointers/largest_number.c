#include <stdio.h>

// Function to find the largest number in an array
int findMax(int arr[], int size) {
    int largest = arr[0]; // Start with the first element
    for (int i = 1; i < size; i++) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }
    return largest;
}

int main(void) {
    int nums[10];
    for (int i = 0; i < 10; i++) {
        printf("Please enter a number: ");
        scanf("%d", &nums[i]);
    }

    int size = sizeof(nums) / sizeof(nums[0]);
    int result = findMax(nums, size);
    printf("The largest number in the array is: %d\n", result);
    return 0;
}
