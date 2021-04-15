#include <stdio.h>

void swap(int *a, int *b);
int partition(int arr[], int low, int high);
void quick_sort(int arr[], int low, int high);
void print_array(int arr[], int s);

int main() {

    int arr[] = { 10, 7, 8, 9, 1, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);

    quick_sort(arr, 0, n - 1);

    print_array(arr, n);

    return 0;
}

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high) {

    int pivot = arr[high];
    int i = (low - 1);
    int j;

    for (j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return (i + 1);

}

void quick_sort(int arr[], int low, int high) {

    if (low < high) {
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }

}

void print_array(int arr[], int s) {
    int i;

    for (i = 0; i < s; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
}