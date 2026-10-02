// ========================================
// VECTOR - STL REVISION
// ========================================
//
// 1. WHAT IS IT?
//    - A vector is a dynamic array that can grow and shrink in size automatically.
//    - Unlike fixed-size static arrays (e.g., int arr[10]), you do not need to 
//      know the size beforehand.
//
// 2. DECLARATION
//    - vector<int> v;                    // Empty vector of integers
//    - vector<int> v(5);                 // Vector of size 5, default initialized to 0
//    - vector<int> v(5, 100);            // Vector of size 5, all initialized to 100
//    - vector<int> v2(v);                // Copy of vector v
//    - vector<pair<int, int>> v_pairs;   // Vector storing pairs of integers
//
// 3. BASIC OPERATIONS
//    - push_back(val) : Adds an element at the end.
//    - pop_back()     : Removes the last element.
//    - size()         : Returns total number of elements.
//    - empty()        : Returns true if vector is empty, false otherwise.
//    - front()        : Accesses the first element.
//    - back()         : Accesses the last element.
//    - v[i]           : Direct index access (no bounds check, fast).
//    - v.at(i)        : Direct index access with bounds checking (throws error if out of bounds).
//    - clear()        : Removes all elements (size becomes 0).
//    - begin(), end() : Iterators pointing to the first element and past-the-last element.
//
// 4. TRAVERSAL METHODS
//    - Range-based for loop : for (int x : v)
//    - Index-based for loop : for (int i = 0; i < v.size(); i++)
//    - Iterator-based loop  : for (auto it = v.begin(); it != v.end(); ++it)
//
// 5. IMPORTANT OBSERVATIONS
//    - Elements are stored in contiguous memory locations (just like arrays).
//    - Supports O(1) random access using index [].
//    - push_back() is fast, but adding/removing elements from the middle or front 
//      takes O(N) time because subsequent elements must shift.
//
// 6. TIME COMPLEXITY
//    - Access (v[i], v.at(i)) : O(1)
//    - push_back()            : O(1) on average (amortized)
//    - pop_back()             : O(1)
//    - size(), empty()        : O(1)
//    - Insertion/Erasure in middle : O(N)
//
// 7. DSA CONNECTION
//    - Most commonly used container in DSA.
//    - Replaces static arrays in almost all array-based problems.
//    - Used to build Graph Adjacency Lists: vector<int> adj[V] or vector<vector<int>>.
//    - Dynamic Programming tables and memoization grids.
// ========================================

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main() {
    cout << "--- 1. DECLARATION & INITIALIZATION ---" << endl;
    vector<int> numbers;                    // Empty vector
    vector<int> fives(4, 5);                // Size 4, filled with 5: {5, 5, 5, 5}
    vector<int> copy_fives(fives);          // Copy of fives

    cout << "fives vector contains: ";
    for (int x : fives) {
        cout << x << " ";
    }
    cout << endl << endl;

    cout << "--- 2. PUSH_BACK & POP_BACK ---" << endl;
    numbers.push_back(10);                  // Add 10 at end
    numbers.push_back(20);                  // Add 20 at end
    numbers.push_back(30);                  // Add 30 at end
    numbers.push_back(40);                  // Add 40 at end
    cout << "After pushing 10, 20, 30, 40: ";
    for (int x : numbers) cout << x << " ";
    cout << endl;

    numbers.pop_back();                     // Removes 40
    cout << "After pop_back(): ";
    for (int x : numbers) cout << x << " ";
    cout << endl << endl;

    cout << "--- 3. SIZE & EMPTY ---" << endl;
    cout << "Size of vector: " << numbers.size() << endl;
    cout << "Is vector empty? " << (numbers.empty() ? "Yes" : "No") << endl << endl;

    cout << "--- 4. ACCESSING ELEMENTS ([], at, front, back) ---" << endl;
    cout << "First element (using front()): " << numbers.front() << endl;
    cout << "Last element (using back()): " << numbers.back() << endl;
    cout << "Element at index 1 (using []): " << numbers[1] << endl;
    cout << "Element at index 1 (using at()): " << numbers.at(1) << endl << endl;

    cout << "--- 5. TRAVERSAL METHODS ---" << endl;
    // Method A: Range-based for loop (preferred for simplicity)
    cout << "Method A (Range-based loop): ";
    for (int val : numbers) {
        cout << val << " ";
    }
    cout << endl;

    // Method B: Index-based loop (useful when index is needed)
    cout << "Method B (Index-based loop): ";
    for (size_t i = 0; i < numbers.size(); i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;

    // Method C: Iterator-based loop (standard STL way)
    cout << "Method C (Iterators with begin() and end()): ";
    for (vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
        cout << *it << " "; // Dereference iterator to get value
    }
    cout << endl << endl;

    cout << "--- 6. VECTOR OF PAIRS ---" << endl;
    // Often used in DSA to store {value, index} or {weight, node}
    vector<pair<int, int>> coordinates;
    coordinates.push_back({1, 2});
    coordinates.push_back({3, 4});
    coordinates.push_back({5, 6});

    cout << "Coordinates stored in vector of pairs:" << endl;
    for (auto p : coordinates) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << endl << endl;

    cout << "--- 7. CLEAR ---" << endl;
    numbers.clear();
    cout << "Size after clear(): " << numbers.size() << endl;
    cout << "Is vector empty after clear()? " << (numbers.empty() ? "Yes" : "No") << endl;

    return 0;
}
