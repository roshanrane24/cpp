#include <stdio.h>
#include <stdlib.h>

int const SIZE=50;

void traverseArray(int arr[]);
void insertArray(int arr[], int value, int index);
void deleteArray(int arr[], int index);
void searchArray(int arr[], int value);

int main() {
    // Array
    int arr[50];

    for (int i = 0; i < 50; i++) {
        arr[i] = rand()%100;
    }

    // Traverse
    printf("Traverse");
    traverseArray(arr);

    // Insert
    printf("Insert");
    insertArray(arr, 99, 25);
    traverseArray(arr);

    // Delete
    printf("Delete");
    deleteArray(arr, 10);
    traverseArray(arr);

    // Search
    printf("Search");
    searchArray(arr, 2);

    // Update
    printf("Update");
    arr[15] = 999;
    traverseArray(arr);

    return 0;
}

void traverseArray(int arr[])
{
    printf("[");
    for (int i = 0; i < 50; i++) {
        printf("%d, ", arr[i]);
    }
    printf("]\n");
    printf("\n");
}

void insertArray(int arr[], int value, int index)
{
    for (int i=SIZE-1; i >= index; i--)
    {
        arr[i] = arr[i-1];
    }
    arr[index] = value;
}

void deleteArray(int arr[], int index)
{
    for (int i = index; i < SIZE-1; i++) {
        arr[i] = arr[i+1];
    }
    arr[SIZE-1] = 0;
}

void searchArray(int arr[], int value)
{
    for (int i=0; i < SIZE; i++) {
        if (arr[i] == value)
        {
            printf("value %d found at %d\n", value, i);
            return;
        }
    }
    printf("value %d not found\n", value);
}
