// ========================================
// UNORDERED SET - STL REVISION
// ========================================
//
// 1. WHAT IS IT?
//    - std::unordered_set is an associative container that stores UNIQUE elements,
//      but WITHOUT any specific order.
//    - Implemented under the hood using a HASH TABLE.
//    - Designed specifically for fast average-time search, insert, and delete.
//
// 2. DECLARATION
//    - unordered_set<int> us;            // Unordered set of integers
//    - unordered_set<string> strSet;     // Unordered set of strings
//
// 3. BASIC OPERATIONS
//    - insert(val) : Inserts an element (duplicates are ignored).
//    - erase(val)  : Erases the element with value val.
//    - find(val)   : Searches for val; returns iterator to val if found, else us.end().
//    - count(val)  : Returns 1 if val exists, 0 otherwise.
//    - size()      : Returns number of elements.
//    - empty()     : Returns true if empty, false otherwise.
//    - clear()     : Removes all elements.
//
// 4. TRAVERSAL METHODS
//    - Range-based for loop : for (int x : us)
//    - Iterator-based loop  : for (auto it = us.begin(); it != us.end(); ++it)
//    - NOTE: Elements will be printed in arbitrary/unpredictable order!
//
// 5. IMPORTANT OBSERVATIONS: SET VS UNORDERED SET
//    - set:
//      * Elements are SORTED.
//      * Backed by Red-Black Tree.
//      * All operations are strictly O(log N).
//    - unordered_set:
//      * Elements are NOT SORTED (random/hash-bucket order).
//      * Backed by HASH TABLE.
//      * Operations are AVERAGE O(1), but can degrade to WORST-CASE O(N)
//        if many hash collisions occur.
//
// 6. TIME COMPLEXITY
//    - insert() : Average O(1), Worst Case O(N)
//    - erase()  : Average O(1), Worst Case O(N)
//    - find()   : Average O(1), Worst Case O(N)
//    - count()  : Average O(1), Worst Case O(N)
//
// 7. DSA CONNECTION
//    - Fast membership checking: "Have I seen this element before?"
//    - Contains Duplicate (LeetCode 217).
//    - Two Sum (checking if complement target - num exists in set).
//    - Longest Consecutive Sequence (LeetCode 128) in O(N) time.
// ========================================

#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
    cout << "--- 1. DECLARATION & INSERTION (UNIQUE + UNORDERED) ---" << endl;
    unordered_set<int> us;

    // Inserting elements with duplicates
    us.insert(50);
    us.insert(10);
    us.insert(30);
    us.insert(20);
    us.insert(10); // Duplicate! Ignored
    us.insert(50); // Duplicate! Ignored

    cout << "Elements in unordered_set: ";
    for (int x : us) {
        cout << x << " "; // Notice order is NOT sorted
    }
    cout << endl;
    cout << "Notice: Duplicates were ignored, order is not guaranteed." << endl << endl;

    cout << "--- 2. FAST LOOKUP USING find() AND count() ---" << endl;
    int target = 30;
    if (us.find(target) != us.end()) {
        cout << "Element " << target << " found in O(1) average time!" << endl;
    } else {
        cout << "Element " << target << " NOT found!" << endl;
    }

    if (us.count(99)) {
        cout << "Element 99 exists!" << endl;
    } else {
        cout << "Element 99 does NOT exist!" << endl;
    }
    cout << endl;

    cout << "--- 3. ERASE OPERATION ---" << endl;
    cout << "Size before erase: " << us.size() << endl;
    us.erase(30);
    cout << "Size after erasing 30: " << us.size() << endl;
    cout << "Elements after erasing 30: ";
    for (int x : us) cout << x << " ";
    cout << endl << endl;

    cout << "--- 4. MINI DSA EXAMPLE: CHECK FOR DUPLICATES ---" << endl;
    // Problem: Return true if any value appears at least twice in an array
    vector<int> nums = {4, 7, 2, 9, 7, 1};
    unordered_set<int> seen;
    bool hasDuplicate = false;

    for (int num : nums) {
        // If already in seen set, we found a duplicate!
        if (seen.count(num)) {
            hasDuplicate = true;
            cout << "Duplicate detected: " << num << endl;
            break;
        }
        seen.insert(num); // Mark as seen
    }

    if (!hasDuplicate) {
        cout << "All elements are unique!" << endl;
    }

    return 0;
}
