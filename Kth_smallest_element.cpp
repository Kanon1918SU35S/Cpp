#include <iostream>
#include <queue>
using namespace std;

// Function to heapify a subtree rooted at index i (Min Heap)
void heapifyMin(int arr[], int n, int i) {
    int smallest = i;          // Initialize smallest as root
    int left = 2 * i + 1;      // Left child index
    int right = 2 * i + 2;     // Right child index

    // If left child is smaller than root
    if (left < n && arr[left] < arr[smallest]) {
        smallest = left;
    }

    // If right child is smaller than smallest so far
    if (right < n && arr[right] < arr[smallest]) {
        smallest = right;
    }

    // If smallest is not root, swap and recursively heapify the affected sub-tree
    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        heapifyMin(arr, n, smallest);
    }
}

// Function to build a Min Heap
void buildMinHeap(int arr[], int n) {
    // Start from the last non-leaf node and apply heapifyMin to all nodes
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapifyMin(arr, n, i);
    }
}

// Function to print the heap
void printHeap(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Function to find the kth smallest element using min heap
int findKthSmallest(int arr[], int n, int k) {
    // Build the min heap
    buildMinHeap(arr, n);

    // Extract the min k-1 times
    for (int i = 0; i < k - 1; i++) {
        // Swap the root (min element) with the last element
        swap(arr[0], arr[n - i - 1]);
        // Heapify the reduced heap
        heapifyMin(arr, n - i - 1, 0);
    }

    // The root now contains the kth smallest element
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
    cout << "Enter the value of k to find the kth smallest element: ";
    cin >> k;

    // Check for valid k value
    if (k > 0 && k <= n) {
        // Find the kth smallest element
        int kthSmallest = findKthSmallest(arr, n, k);
        cout << "The " << k << "th smallest element is: " << kthSmallest << endl;
    } else {
        cout << "Invalid value of k. It must be between 1 and " << n << "." << endl;
    }

    return 0;
}
