// ========================================
// PRIORITY QUEUE - STL REVISION
// ========================================
//
// 1. WHAT IS IT?
//    - std::priority_queue is a container adapter where the FIRST element is
//      always the GREATEST (by default) among all elements it contains.
//    - It is implemented under the hood as a HEAP (Binary Max-Heap by default).
//    - Unlike a normal queue where order is based on arrival time (FIFO),
//      priority_queue orders elements based on their PRIORITY/VALUE.
//
// 2. DECLARATION
//    - Default Max-Heap (largest element on top):
//        priority_queue<int> maxHeap;
//    - Min-Heap (smallest element on top):
//        priority_queue<int, vector<int>, greater<int>> minHeap;
//      * Syntax breakdown:
//        1. int             -> data type
//        2. vector<int>     -> underlying container
//        3. greater<int>    -> comparator for ascending order (smallest at top)
//
// 3. BASIC OPERATIONS
//    - push(val) : Inserts an element and restores heap property (O(log N)).
//    - top()     : Returns the highest priority element (largest in max-heap, smallest in min-heap).
//    - pop()     : Removes the topmost element and restores heap property (O(log N)).
//    - empty()   : Returns true if priority queue is empty, false otherwise.
//    - size()    : Returns total number of elements.
//
// 4. TRAVERSAL METHOD
//    - Does not support iterators (no begin(), end(), or []).
//    - Traverse by reading top() and popping until empty().
//
// 5. IMPORTANT OBSERVATIONS: QUEUE VS PRIORITY QUEUE
//    - Queue is FIFO: element pushed first comes out first.
//    - Priority Queue is VALUE-BASED: element with greatest (or lowest for min-heap)
//      value comes out first, regardless of when it was pushed.
//    - Always check !pq.empty() before calling pq.top() or pq.pop().
//
// 6. TIME COMPLEXITY
//    - push()  : O(log N)
//    - pop()   : O(log N)
//    - top()   : O(1)
//    - size()  : O(1)
//    - empty() : O(1)
//
// 7. DSA CONNECTION
//    - Kth Largest Element (using min-heap of size K).
//    - Kth Smallest Element (using max-heap of size K).
//    - Dijkstra's Shortest Path Algorithm (using min-heap of {distance, node}).
//    - Prim's Minimum Spanning Tree Algorithm.
//    - Merge K Sorted Lists / Arrays.
//    - Top K Frequent Elements.
// ========================================

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    cout << "--- 1. MAX-HEAP (DEFAULT: LARGEST ON TOP) ---" << endl;
    priority_queue<int> maxHeap;

    maxHeap.push(25);
    maxHeap.push(10);
    maxHeap.push(50);
    maxHeap.push(5);

    cout << "Elements inserted into maxHeap: 25, 10, 50, 5" << endl;
    cout << "Current size: " << maxHeap.size() << endl;
    cout << "Top element (largest): " << maxHeap.top() << endl << endl;

    cout << "Popping from max-heap (descending order): ";
    while (!maxHeap.empty()) {
        cout << maxHeap.top() << " "; // Prints largest first
        maxHeap.pop();
    }
    cout << endl << endl;

    cout << "--- 2. MIN-HEAP (SMALLEST ON TOP) ---" << endl;
    // Syntax for Min-Heap:
    priority_queue<int, vector<int>, greater<int>> minHeap;

    minHeap.push(25);
    minHeap.push(10);
    minHeap.push(50);
    minHeap.push(5);

    cout << "Elements inserted into minHeap: 25, 10, 50, 5" << endl;
    cout << "Current size: " << minHeap.size() << endl;
    cout << "Top element (smallest): " << minHeap.top() << endl << endl;

    cout << "Popping from min-heap (ascending order): ";
    while (!minHeap.empty()) {
        cout << minHeap.top() << " "; // Prints smallest first
        minHeap.pop();
    }
    cout << endl << endl;

    cout << "--- 3. MINI DSA EXAMPLE: FINDING 3RD LARGEST ELEMENT ---" << endl;
    // An array of numbers: {7, 10, 4, 3, 20, 15}
    // To find K-th largest, maintain a min-heap of size K:
    vector<int> nums = {7, 10, 4, 3, 20, 15};
    int k = 3;
    priority_queue<int, vector<int>, greater<int>> kMinHeap;

    for (int num : nums) {
        kMinHeap.push(num);
        if (kMinHeap.size() > (size_t)k) {
            kMinHeap.pop(); // Remove smaller elements, keeping top K largest
        }
    }

    cout << "The 3rd largest element is: " << kMinHeap.top() << endl; // Should be 10

    return 0;
}
