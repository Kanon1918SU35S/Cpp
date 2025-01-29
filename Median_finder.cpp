#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class MedianFinder {
private:
    // Max-Heap to store the smaller half
    priority_queue<int> maxHeap;
    
    // Min-Heap to store the larger half
    priority_queue<int, vector<int>, std::greater<int>> minHeap;
    
public:
    // Adds a number to the data structure
    void addNum(int num) {
        maxHeap.push(num);
        
        // Balance the heaps
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        
        // Ensure that all elements in maxHeap are <= elements in minHeap
        if (!minHeap.empty() && maxHeap.top() > minHeap.top()) {
            int maxRoot = maxHeap.top();
            int minRoot = minHeap.top();
            maxHeap.pop();
            minHeap.pop();
            maxHeap.push(minRoot);
            minHeap.push(maxRoot);
        }
    }
    
    // Returns the current median
    double findMedian() {
        if (maxHeap.size() > minHeap.size()) {
            return maxHeap.top();
        }
        
        return (maxHeap.top() + minHeap.top()) / 2.0;
    }
};

int main() {
    MedianFinder* medianFinder = new MedianFinder();
    
    int num;
    int option;
    
    while (true) {
        cout << "Menu:\n";
        cout << "1. Add a number\n";
        cout << "2. Find the median\n";
        cout << "3. Exit\n";
        cout << "Please enter your choice: ";
        cin >> option;
        
        if (option == 1) {
            cout << "Enter a number to add: ";
            cin >> num;
            medianFinder->addNum(num);
            cout << "Number added.\n";
        }
        else if (option == 2) {
            cout << "Current median: " << medianFinder->findMedian() << endl;
        }
        else if (option == 3) {
            break;
        }
        else {
            cout << "Invalid option. Please try again.\n";
        }
    }
    
    delete medianFinder;
    return 0;
}
