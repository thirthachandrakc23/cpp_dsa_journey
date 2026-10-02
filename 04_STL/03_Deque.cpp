// ========================================
// DEQUE (DOUBLE-ENDED QUEUE) - STL REVISION
// ========================================
//
// 1. WHAT IS IT?
//    - std::deque stands for "Double-Ended Queue".
//    - It allows fast insertion and deletion at BOTH the beginning and the end.
//    - Unlike std::list, deque provides O(1) random access indexing (dq[i]).
//
// 2. DECLARATION
//    - deque<int> dq;                    // Empty deque of integers
//    - deque<int> dq(5, 10);             // Deque of size 5, all elements initialized to 10
//    - deque<int> dq2(dq);               // Copy of deque dq
//
// 3. BASIC OPERATIONS
//    - push_back(val)  : Adds element at the back.
//    - push_front(val) : Adds element at the front.
//    - pop_back()      : Removes element from the back.
//    - pop_front()     : Removes element from the front.
//    - front()         : Accesses the first element.
//    - back()          : Accesses the last element.
//    - dq[i]           : Direct index access (random access).
//    - dq.at(i)        : Direct index access with bounds checking.
//    - size()          : Returns the number of elements.
//    - empty()         : Returns true if deque is empty, false otherwise.
//    - clear()         : Removes all elements.
//
// 4. TRAVERSAL METHODS
//    - Range-based for loop : for (int x : dq)
//    - Index-based loop     : for (int i = 0; i < dq.size(); i++)
//    - Iterator-based loop  : for (auto it = dq.begin(); it != dq.end(); ++it)
//
// 5. IMPORTANT OBSERVATIONS: WHY USE DEQUE OVER VECTOR OR LIST?
//    - Vector vs Deque:
//      * Vector only supports fast push_back/pop_back (push_front is O(N)).
//      * Deque supports BOTH push_front/pop_front and push_back/pop_back in O(1).
//    - List vs Deque:
//      * List does NOT support random access (no list[i]).
//      * Deque DOES support random access (dq[i]) in O(1).
//    - Under the hood, deque is implemented as a sequence of fixed-size chunks/pages,
//      not a single contiguous block (like vector) or individual node pointers (like list).
//
// 6. TIME COMPLEXITY
//    - push_front(), push_back() : O(1)
//    - pop_front(), pop_back()   : O(1)
//    - Random Access (dq[i])     : O(1)
//    - size(), empty()           : O(1)
//    - Insertion/Erasure in middle : O(N)
//
// 7. DSA CONNECTION
//    - Sliding Window Maximum (Monotonic Deque technique) - classic Hard problem.
//    - 0-1 BFS (Shortest path in graphs where edge weights are 0 or 1).
//    - Checking if a string is a palindrome by comparing front and back.
// ========================================

#include <iostream>
#include <deque>

using namespace std;

int main() {
    cout << "--- 1. DECLARATION & INSERTION AT BOTH ENDS ---" << endl;
    deque<int> dq;

    dq.push_back(30);       // Deque: {30}
    dq.push_back(40);       // Deque: {30, 40}
    dq.push_front(20);      // Deque: {20, 30, 40} -> O(1)
    dq.push_front(10);      // Deque: {10, 20, 30, 40} -> O(1)

    cout << "Deque after pushing from front and back: ";
    for (int x : dq) {
        cout << x << " ";
    }
    cout << endl << endl;

    cout << "--- 2. FRONT, BACK, SIZE, EMPTY ---" << endl;
    cout << "Front element: " << dq.front() << endl;
    cout << "Back element: " << dq.back() << endl;
    cout << "Size of deque: " << dq.size() << endl;
    cout << "Is deque empty? " << (dq.empty() ? "Yes" : "No") << endl << endl;

    cout << "--- 3. RANDOM ACCESS INDEXING ([], at) ---" << endl;
    cout << "Element at index 0: " << dq[0] << endl;
    cout << "Element at index 2: " << dq[2] << endl;
    cout << "Element at index 3 (using at()): " << dq.at(3) << endl << endl;

    cout << "--- 4. POP_FRONT & POP_BACK ---" << endl;
    dq.pop_front();         // Removes 10
    dq.pop_back();          // Removes 40

    cout << "After pop_front() and pop_back(): ";
    for (int x : dq) cout << x << " ";
    cout << endl << endl;

    cout << "--- 5. TRAVERSAL METHODS ---" << endl;
    // Method A: Range-based for loop
    cout << "Method A (Range-based): ";
    for (int x : dq) cout << x << " ";
    cout << endl;

    // Method B: Index-based loop (Supported by deque, unlike list!)
    cout << "Method B (Index-based): ";
    for (size_t i = 0; i < dq.size(); i++) {
        cout << dq[i] << " ";
    }
    cout << endl;

    // Method C: Iterator-based loop
    cout << "Method C (Iterators)  : ";
    for (deque<int>::iterator it = dq.begin(); it != dq.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl << endl;

    cout << "--- 6. CLEAR ---" << endl;
    dq.clear();
    cout << "Size after clear(): " << dq.size() << endl;
    cout << "Is deque empty after clear()? " << (dq.empty() ? "Yes" : "No") << endl;

    return 0;
}
