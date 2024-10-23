#include "sort_d.h"

// Swap function for double
void swap(double& a, double& b) {
    double temp = a;
    a = b;
    b = temp;
}

// Partition function for quicksort (double)
int partition(double arr[], int low, int high) {
    double pivot = arr[high];  // Pivot is a double
    int i = low - 1;

    for (int j = low; j <= high - 1; ++j) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);  // Swap using double
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Quicksort implementation for double
void quicksort_d(double* arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);  // Partition the array
        quicksort_d(arr, low, pi - 1);  // Recursively sort the left part
        quicksort_d(arr, pi + 1, high);  // Recursively sort the right part
    }
}
