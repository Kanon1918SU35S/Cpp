#include <iostream>
using namespace std;

// Function to merge two halves
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    int leftArr[n1], rightArr[n2];

    // Copy data to temporary arrays
    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        rightArr[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;

    // Merge the temporary arrays back into arr[]
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of leftArr[], if any
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // Copy the remaining elements of rightArr[], if any
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

// Function to implement merge sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Recursively sort the two halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int n;
    
    // User input for array size
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    
    // User input for array elements
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Given array: ";
    printArray(arr, n);

    // Perform merge sort
    mergeSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}


// Time Complexity: O(nlogn)
// Space Complexity: O(n)
// Stable: Yes
// In-Place: No
// Sorting In Place: No
// Method: Divide and Conquer
// Recurrence Relation: T(n) = 2T(n/2) + O(n)
// Best Case: O(nlogn)
// Average Case: O(nlogn)
// Worst Case: O(nlogn)
// Comparison Based: Yes
// External Sorting: Yes
// Non-Comparison Based: No
// Radix: No
// Stable: Yes
// Online: No
// Adaptive: No
// Recursive: Yes
// Parallel: No
// Distribution: No
// Comparison Based: Yes