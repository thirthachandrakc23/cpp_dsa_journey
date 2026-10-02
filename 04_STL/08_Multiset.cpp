// ========================================
// MULTISET - STL REVISION
// ========================================
//
// 1. WHAT IS IT?
//    - std::multiset is an associative container that stores elements in
//      SORTED order, just like std::set, BUT ALLOWS DUPLICATES.
//    - Implemented as a Red-Black Tree.
//
// 2. DECLARATION
//    - multiset<int> ms;                 // Ascending order multiset of integers
//    - multiset<int, greater<int>> ms;   // Descending order multiset
//
// 3. BASIC OPERATIONS
//    - insert(val)            : Inserts val (duplicates are allowed and stored).
//    - erase(val)             : CRITICAL! Erases ALL instances of val!
//    - erase(ms.find(val))    : Erases ONLY A SINGLE instance of val!
//    - find(val)              : Returns an iterator to the FIRST instance of val.
//    - count(val)             : Returns the count of times val occurs (O(count + log N)).
//    - lower_bound(val)       : Returns iterator to first element >= val.
//    - upper_bound(val)       : Returns iterator to first element > val.
//    - size(), empty()        : Standard size and emptiness checks.
//
// 4. IMPORTANT DIFFERENCE: SET VS MULTISET
//    - std::set:
//      * Elements are UNIQUE and SORTED.
//      * count(x) is either 0 or 1.
//    - std::multiset:
//      * Elements are DUPLICATE-FRIENDLY and SORTED.
//      * count(x) can be > 1.
//      * ms.erase(x) deletes ALL copies of x.
//
// 5. ERASE TRAP (MUST REMEMBER FOR DSA!)
//    - ms.erase(10);          -> Deletes EVERY 10 in the multiset!
//    - ms.erase(ms.find(10)); -> Deletes ONLY ONE occurrence of 10!
//
// 6. TIME COMPLEXITY
//    - insert()              : O(log N)
//    - erase(iterator)       : O(1) amortized
//    - erase(value)          : O(log N + count)
//    - find()                : O(log N)
//    - lower_bound() / upper_bound() : O(log N)
//
// 7. DSA CONNECTION
//    - Maintaining a dynamically sorted window with duplicates (e.g., Sliding Window Median).
//    - When you need min/max element lookup in O(1) (*ms.begin() or *ms.rbegin())
//      while adding and removing elements dynamically.
// ========================================

#include <iostream>
#include <set> // multiset is included in <set>

using namespace std;

int main() {
    cout << "--- 1. DECLARATION & INSERTION (SORTED WITH DUPLICATES) ---" << endl;
    multiset<int> ms;

    // Inserting elements with duplicates
    ms.insert(20);
    ms.insert(10);
    ms.insert(20);
    ms.insert(30);
    ms.insert(20);
    ms.insert(10);

    cout << "Elements in multiset: ";
    for (int x : ms) {
        cout << x << " "; // Output is sorted: 10 10 20 20 20 30
    }
    cout << endl << endl;

    cout << "--- 2. COUNT AND FIND ---" << endl;
    cout << "Total count of 20: " << ms.count(20) << endl;
    cout << "Total count of 10: " << ms.count(10) << endl;

    // find() returns iterator to the first instance of the value
    auto it = ms.find(20);
    if (it != ms.end()) {
        cout << "Found first instance of 20 at iterator position." << endl;
    }
    cout << endl;

    cout << "--- 3. THE ERASE TRAP: ALL vs SINGLE INSTANCE ---" << endl;
    // Current multiset: {10, 10, 20, 20, 20, 30}
    cout << "Current multiset: ";
    for (int x : ms) cout << x << " ";
    cout << endl;

    // Case A: Erase ONLY ONE instance of 20
    cout << "Erasing ONLY ONE instance of 20 using ms.erase(ms.find(20))..." << endl;
    ms.erase(ms.find(20)); // Deletes just one 20

    cout << "After erasing one 20: ";
    for (int x : ms) cout << x << " ";
    cout << endl;

    // Case B: Erase ALL instances of 10
    cout << "Erasing ALL instances of 10 using ms.erase(10)..." << endl;
    ms.erase(10); // Deletes all occurrences of 10

    cout << "After erasing all 10s: ";
    for (int x : ms) cout << x << " ";
    cout << endl << endl;

    cout << "--- 4. LOWER_BOUND & UPPER_BOUND ---" << endl;
    // Current elements: {20, 20, 30}
    // lower_bound(x) -> first element >= x
    // upper_bound(x) -> first element > x
    auto lb = ms.lower_bound(20);
    auto ub = ms.upper_bound(20);

    cout << "lower_bound(20) points to: " << *lb << " (first element >= 20)" << endl;
    cout << "upper_bound(20) points to: " << *ub << " (first element > 20)" << endl << endl;

    cout << "--- 5. MIN AND MAX ELEMENTS ---" << endl;
    // Smallest element is at begin()
    // Largest element is at rbegin() (reverse begin)
    cout << "Smallest element (*ms.begin()): " << *ms.begin() << endl;
    cout << "Largest element (*ms.rbegin()): " << *ms.rbegin() << endl;

    return 0;
}
