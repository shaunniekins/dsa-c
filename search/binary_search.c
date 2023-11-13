#include <stdio.h>

int binarySearch(int arr[], int low, int high, int target) {
    while (low <= high) {
        int mid = low + (high - low) / 2;

        // If the target is found, return its index
        if (arr[mid] == target) {
            return mid;
        }

        // If the target is greater, ignore the left half
        if (arr[mid] < target) {
            low = mid + 1;
        }

        // If the target is smaller, ignore the right half
        else {
            high = mid - 1;
        }
    }

    // Target not found in the array
    return -1;
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 10;

    int result = binarySearch(arr, 0, n - 1, target);

    if (result != -1) {
        printf("Element found at index: %d\n", result);
    } else {
        printf("Element not found in the array\n");
    }

    return 0;
}
