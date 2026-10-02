// ========================================
// QUEUE - STL REVISION
// ========================================
//
// 1. WHAT IS IT?
//    - std::queue is a container adapter that follows the FIFO principle:
//      FIRST IN, FIRST OUT.
//    - Think of it like a line of people waiting at a ticket counter:
//      the first person to join the line is the first person to get served.
//
// 2. DECLARATION
//    - queue<int> q;                     // Empty queue of integers
//    - queue<string> strQueue;           // Empty queue of strings
//
// 3. BASIC OPERATIONS
//    - push(val) : Inserts an element at the back/rear of the queue.
//    - pop()     : Removes the element at the front of the queue.
//                  IMPORTANT: pop() has void return type! It does NOT return the element.
//    - front()   : Accesses the first element (the one next in line to be removed).
//    - back()    : Accesses the last element (the most recently pushed element).
//    - empty()   : Returns true if the queue is empty, false otherwise.
//    - size()    : Returns the total number of elements in the queue.
//
// 4. TRAVERSAL METHOD
//    - std::queue does not have iterators (no begin(), end(), or q[i]).
//    - To traverse, inspect front() and pop() until empty().
//    - Use a copy if you need to keep the original queue intact.
//
// 5. IMPORTANT OBSERVATIONS
//    - Elements enter at the BACK and leave from the FRONT.
//    - In stack: we inspect top().
//      In queue: we inspect front() (and sometimes back()).
//    - Always verify !q.empty() before calling q.front() or q.pop() to prevent crashes.
//
// 6. TIME COMPLEXITY
//    - push()  : O(1)
//    - pop()   : O(1)
//    - front() : O(1)
//    - back()  : O(1)
//    - empty() : O(1)
//    - size()  : O(1)
//
// 7. DSA CONNECTION
//    - Breadth-First Search (BFS) in Graphs and Grids.
//    - Level Order Traversal of Binary Trees.
//    - First non-repeating character in a stream of characters.
//    - Scheduling tasks and CPU job queues.
// ========================================

#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {
    cout << "--- 1. DECLARATION & PUSH (FIFO ORDER) ---" << endl;
    queue<string> ticketLine;

    // People joining the line (pushed to back)
    ticketLine.push("Alice");
    ticketLine.push("Bob");
    ticketLine.push("Charlie");
    ticketLine.push("David");

    cout << "Queue size: " << ticketLine.size() << endl;
    cout << "Front of queue (first in line): " << ticketLine.front() << endl;
    cout << "Back of queue (last person in line): " << ticketLine.back() << endl << endl;

    cout << "--- 2. HOW TO READ AND REMOVE (front + pop) ---" << endl;
    // Just like stack, pop() removes the front element but does not return it!
    string servedPerson = ticketLine.front(); // 1. Read front value
    ticketLine.pop();                         // 2. Remove front element

    cout << "Served and removed: " << servedPerson << endl;
    cout << "New front of queue: " << ticketLine.front() << endl;
    cout << "Queue size after pop: " << ticketLine.size() << endl << endl;

    cout << "--- 3. TRAVERSING A QUEUE (COPY & POP) ---" << endl;
    // We create a copy so the original queue is not destroyed
    queue<string> tempLine = ticketLine;

    cout << "Serving remaining people in FIFO order: ";
    while (!tempLine.empty()) {
        cout << tempLine.front() << " ";
        tempLine.pop();
    }
    cout << endl;
    cout << "Original queue size remains unchanged: " << ticketLine.size() << endl << endl;

    cout << "--- 4. MINI DSA EXAMPLE: BFS LEVEL ORDER SIMULATION ---" << endl;
    // Simulating node traversal in a small graph/tree
    queue<int> nodeQueue;
    nodeQueue.push(1); // start node

    cout << "Simulating BFS node processing:" << endl;
    while (!nodeQueue.empty()) {
        int currentNode = nodeQueue.front();
        nodeQueue.pop();
        cout << "Processed node: " << currentNode << endl;

        // Simulate pushing child nodes (e.g., node 1 has children 2 and 3)
        if (currentNode == 1) {
            nodeQueue.push(2);
            nodeQueue.push(3);
        }
    }

    return 0;
}
