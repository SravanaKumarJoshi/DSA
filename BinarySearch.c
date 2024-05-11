#include <stdio.h>

int binarySearch(int array[], int low, int high, int x) {
    if (high >= low) {
        int mid = low + (high - low) / 2;

        if (array[mid] == x) {
            return mid;
        }

        if (array[mid] > x) {
            return binarySearch(array, low, mid - 1, x);
        }

        return binarySearch(array, mid + 1, high, x);
    }

    return -1;
}

int main() {
    int array[] = {2, 4, 0, 1, 9};
    int x = 1;
    int n = sizeof(array) / sizeof(array[0]);

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (array[i] > array[j]) {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }

    int result = binarySearch(array, 0, n - 1, x);

    if (result == -1) {
        printf("Element not found");
    } else {
        printf("Element found at index: %d", result);
    }
    return 0;
}
