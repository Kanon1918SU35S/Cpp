#include <iostream>
#include <queue>
using namespace std;

// Function to heapify a subtree rooted at index i (Max Heap)
void heapifyMax(int arr[], int n, int i) {
    int largest = i;          // Initialize largest as root
    int left = 2 * i + 1;     // Left child index
    int right = 2 * i + 2;    // Right child index

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // If largest is not root, swap and recursively heapify the affected sub-tree
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapifyMax(arr, n, largest);
    }
}

// Function to build a Max Heap
void buildMaxHeap(int arr[], int n) {
    // Start from the last non-leaf node and apply heapifyMax to all nodes
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapifyMax(arr, n, i);
    }
}

// Function to print the heap
void printHeap(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Function to find the kth largest element using max heap
int findKthLargest(int arr[], int n, int k) {
    // Build the max heap
    buildMaxHeap(arr, n);

    // Extract max k-1 times
    for (int i = 0; i < k - 1; i++) {
        // Swap the root (max element) with the last element
        swap(arr[0], arr[n - i - 1]);
        // Heapify the reduced heap
        heapifyMax(arr, n - i - 1, 0);
    }

    // The root now contains the kth largest element
    return arr[0];
}

int main() {
    int n, k;
    
    // Take the size of the array from the user
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    // Define a static array to store elements
    int arr[n];

    // Take the array elements from the user
    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Take the kth position input from the user
    cout << "Enter the value of k to find the kth largest element: ";
    cin >> k;

    // Check for valid k value
    if (k > 0 && k <= n) {
        // Find the kth largest element
        int kthLargest = findKthLargest(arr, n, k);
        cout << "The " << k << "th largest element is: " << kthLargest << endl;
    } else {
        cout << "Invalid value of k. It must be between 1 and " << n << "." << endl;
    }

    return 0;
}
