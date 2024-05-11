#include <stdio.h>
#define MAX_SIZE 100

void createArray(int arr[MAX_SIZE], int *size) {
    printf("Enter the size of the array: ");
    scanf("%d", size);

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < *size; i++) {
        scanf("%d", &arr[i]);
    }
}

void displayArray(int arr[MAX_SIZE], int size) {
    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertElement(int arr[MAX_SIZE], int *size) {
    if (*size == MAX_SIZE) {
        printf("Array is full. Cannot insert.\n");
        return;
    }

    int index, element;
    printf("Enter the index where you want to insert: ");
    scanf("%d", &index);

    if (index < 0 || index > *size) {
        printf("Invalid index.\n");
        return;
    }

    printf("Enter the element to insert: ");
    scanf("%d", &element);

    for (int i = *size; i > index; i--) {
        arr[i] = arr[i - 1];
    }
    arr[index] = element;
    (*size)++;
}

void deleteElement(int arr[MAX_SIZE], int *size) {
    if (*size == 0) {
        printf("Array is empty. Cannot delete.\n");
        return;
    }

    int index;
    printf("Enter the index of the element to delete: ");
    scanf("%d", &index);

    if (index < 0 || index >= *size) {
        printf("Invalid index.\n");
        return;
    }

    for (int i = index; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
}

int searchElement(int arr[MAX_SIZE], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i;  
        }
    }
    return -1; 
}

void reversePrintArray(int arr[MAX_SIZE], int size) {
    printf("Reverse Array: ");
    for (int i = size - 1; i >= 0; i--) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[MAX_SIZE];
    int size = 0;
    int choice;

    do {
        printf("\n1. Create Array\n");
        printf("2. Display Array\n");
        printf("3. Insert Element\n");
        printf("4. Delete Element\n");
        printf("5. Search Element\n");
        printf("6. Reverse Print Array\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createArray(arr, &size);
                break;
            case 2:
                displayArray(arr, size);
                break;
            case 3:
                insertElement(arr, &size);
                break;
            case 4:
                deleteElement(arr, &size);
                break;
            case 5: {
                int key;
                printf("Enter the element to search: ");
                scanf("%d", &key);
                int index = searchElement(arr, size, key);
                if (index != -1) {
                    printf("Element found at index %d\n", index);
                } else {
                    printf("Element not found\n");
                }
                break;
            }
            case 6:
                reversePrintArray(arr, size);
                break;
            case 7:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}
