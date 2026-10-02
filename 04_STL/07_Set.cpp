// ========================================
// SET - STL REVISION
// ========================================
//
// 1. WHAT IS IT?
//    - std::set is an associative container that stores UNIQUE elements in
//      SORTED order (ascending by default).
//    - Implemented under the hood as a Self-Balancing Binary Search Tree (Red-Black Tree).
//
// 2. DECLARATION
//    - set<int> s;                       // Ascending order set of ints
//    - set<int, greater<int>> descSet;   // Descending order set of ints
//
// 3. BASIC OPERATIONS
//    - insert(val) : Inserts an element. If it already exists, insertion is IGNORED.
//    - erase(val)  : Removes the element with value val.
//    - erase(it)   : Removes element at iterator position.
//    - find(val)   : Returns an iterator to val if found; else returns s.end().
//    - count(val)  : Returns 1 if val exists, 0 otherwise (since all elements are unique).
//    - size()      : Returns number of elements.
//    - empty()     : Returns true if set is empty, false otherwise.
//    - clear()     : Removes all elements.
//    - begin(), end() : Iterators to the beginning and past-the-end.
//
// 4. TRAVERSAL METHODS
//    - Range-based for loop : for (int x : s)
//    - Iterator-based loop  : for (auto it = s.begin(); it != s.end(); ++it)
//    - NOTE: Elements in a set are CONST. You cannot modify an element in-place
//      (e.g., *it = 10 is illegal) because modifying it would break the tree's sorted order!
//
// 5. IMPORTANT OBSERVATIONS
//    - DUPLICATES ARE NEVER STORED: Inserting an existing element does nothing.
//    - ALWAYS SORTED: Elements are automatically kept in sorted order.
//    - NO RANDOM ACCESS: s[i] is NOT allowed.
//
// 6. TIME COMPLEXITY
//    - insert() : O(log N)
//    - erase()  : O(log N)
//    - find()   : O(log N)
//    - count()  : O(log N)
//    - size()   : O(1)
//
// 7. DSA CONNECTION
//    - Removing duplicates from an array while keeping it sorted.
//    - Checking if an element exists in sorted data in O(log N).
//    - Finding next greater or smaller element using lower_bound() / upper_bound().
// ========================================

#include <iostream>
#include <set>

using namespace std;

int main() {
    cout << "--- 1. DECLARATION & INSERTION (UNIQUE + SORTED) ---" << endl;
    set<int> s;

    // Inserting elements (even in random order and with duplicates)
    s.insert(40);
    s.insert(10);
    s.insert(30);
    s.insert(20);
    s.insert(10); // Duplicate! Will be ignored
    s.insert(30); // Duplicate! Will be ignored

    cout << "Elements in set after inserting {40, 10, 30, 20, 10, 30}: ";
    for (int x : s) {
        cout << x << " "; // Output will be strictly sorted and unique: 10 20 30 40
    }
    cout << endl;
    cout << "Notice: Duplicates were ignored, and elements are sorted automatically." << endl << endl;

    cout << "--- 2. FIND & COUNT ---" << endl;
    // Checking if 20 exists using find()
    auto it = s.find(20);
    if (it != s.end()) {
        cout << "Element 20 found in the set!" << endl;
    } else {
        cout << "Element 20 NOT found!" << endl;
    }

    // Checking if 99 exists using count()
    // In set, count(x) is either 1 (present) or 0 (absent)
    if (s.count(99)) {
        cout << "Element 99 exists!" << endl;
    } else {
        cout << "Element 99 does NOT exist!" << endl;
    }
    cout << endl;

    cout << "--- 3. ERASE OPERATION ---" << endl;
    cout << "Size before erase: " << s.size() << endl;
    s.erase(20); // Erases 20
    cout << "Set after erasing 20: ";
    for (int x : s) cout << x << " ";
    cout << endl;
    cout << "Size after erase: " << s.size() << endl << endl;

    cout << "--- 4. TRAVERSAL METHODS ---" << endl;
    // Method A: Range-based for loop
    cout << "Range-based traversal: ";
    for (int val : s) {
        cout << val << " ";
    }
    cout << endl;

    // Method B: Iterator-based loop
    cout << "Iterator-based traversal: ";
    for (set<int>::iterator iter = s.begin(); iter != s.end(); ++iter) {
        cout << *iter << " ";
    }
    cout << endl << endl;

    cout << "--- 5. DESCENDING ORDER SET ---" << endl;
    // We can pass greater<int> to store elements in descending order
    set<int, greater<int>> descSet = {5, 2, 8, 1, 9};
    cout << "Set with greater<int> comparator: ";
    for (int x : descSet) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
