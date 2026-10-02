// ========================================
// STL ALGORITHMS - REVISION
// ========================================
//
// 1. WHAT ARE STL ALGORITHMS?
//    - The C++ Standard Template Library provides a powerful collection of 
//      ready-to-use algorithms for searching, sorting, reversing, and transforming data.
//    - Most algorithms operate on sequences defined by iterators: [begin, end).
//    - Key headers needed:
//      * #include <algorithm> (for sort, reverse, min_element, max_element, next_permutation, find)
//      * #include <numeric>   (for accumulate)
//      * #include <utility>   (for swap, pair)
//
// 2. ALGORITHMS COVERED IN THIS FILE:
//    1. sort()              : Sort in ascending / descending order
//    2. Sorting pairs       : Default comparison behavior for pair<T1, T2>
//    3. reverse()           : Reverse range in-place
//    4. max_element()       : Find iterator to maximum value
//    5. min_element()       : Find iterator to minimum value
//    6. next_permutation()  : Generates next lexicographical permutation
//    7. swap()              : Swaps values of two variables
//    8. accumulate()        : Calculates sum of elements in range
//    9. find()              : Searches for an element in range
//
// 3. TIME COMPLEXITY SUMMARY:
//    - sort()               : O(N log N) (Introsort: QuickSort + HeapSort + InsertionSort)
//    - reverse()            : O(N)
//    - max_element()        : O(N)
//    - min_element()        : O(N)
//    - accumulate()         : O(N)
//    - find()               : O(N)
//    - swap()               : O(1)
//    - next_permutation()   : O(N) per step
// ========================================

#include <iostream>
#include <vector>
#include <algorithm> // sort, reverse, min/max_element, next_permutation, find
#include <numeric>   // accumulate
#include <utility>   // pair, swap

using namespace std;

int main() {
    // =========================================================================
    // 1. SORT() - ASCENDING & DESCENDING
    // =========================================================================
    cout << "--- 1. SORT() ---" << endl;
    vector<int> nums = {40, 10, 50, 20, 30};

    // Ascending order: sort(first_it, last_it)
    sort(nums.begin(), nums.end());
    cout << "Sorted in Ascending order : ";
    for (int x : nums) cout << x << " ";
    cout << " (Complexity: O(N log N))" << endl;

    // Descending order: pass greater<int>() comparator
    sort(nums.begin(), nums.end(), greater<int>());
    cout << "Sorted in Descending order: ";
    for (int x : nums) cout << x << " ";
    cout << endl << endl;

    // =========================================================================
    // 2. SORTING VECTOR OF PAIRS
    // =========================================================================
    cout << "--- 2. SORTING VECTOR OF PAIRS ---" << endl;
    // Default pair comparison:
    // 1. First compares p.first.
    // 2. If p.first is equal, then compares p.second.
    vector<pair<int, int>> pairs = {{3, 10}, {1, 50}, {2, 40}, {1, 20}};

    sort(pairs.begin(), pairs.end());

    cout << "Pairs sorted by first, then second element:" << endl;
    for (const auto& p : pairs) {
        cout << "{" << p.first << ", " << p.second << "} ";
    }
    cout << "\nNotice: For key 1, {1, 20} came before {1, 50} because 20 < 50." << endl << endl;

    // =========================================================================
    // 3. REVERSE()
    // =========================================================================
    cout << "--- 3. REVERSE() ---" << endl;
    vector<int> revVec = {1, 2, 3, 4, 5};
    reverse(revVec.begin(), revVec.end()); // Reverses in-place: O(N)

    cout << "Reversed vector: ";
    for (int x : revVec) cout << x << " ";
    cout << endl << endl;

    // =========================================================================
    // 4 & 5. MAX_ELEMENT() AND MIN_ELEMENT()
    // =========================================================================
    cout << "--- 4 & 5. MAX_ELEMENT() AND MIN_ELEMENT() ---" << endl;
    vector<int> values = {45, 12, 89, 34, 78};

    // NOTE: min_element and max_element return ITERATORS, not the values directly!
    // We must dereference (*) the iterator to get the actual value.
    auto maxIt = max_element(values.begin(), values.end());
    auto minIt = min_element(values.begin(), values.end());

    cout << "Maximum element: " << *maxIt << endl;
    cout << "Minimum element: " << *minIt << endl;
    // You can also get their 0-based indices by subtracting begin():
    cout << "Index of max element: " << (maxIt - values.begin()) << endl;
    cout << "Index of min element: " << (minIt - values.begin()) << endl << endl;

    // =========================================================================
    // 6. NEXT_PERMUTATION()
    // =========================================================================
    cout << "--- 6. NEXT_PERMUTATION() ---" << endl;
    // next_permutation rearranges elements into the lexicographically NEXT greater permutation.
    // Returns true if next permutation exists, false if already at the highest/last permutation.
    // IMPORTANT: To generate ALL permutations, start with a SORTED array!
    vector<int> perm = {1, 2, 3};

    cout << "Generating all permutations of {1, 2, 3}:" << endl;
    do {
        cout << "{ ";
        for (int x : perm) cout << x << " ";
        cout << "}" << endl;
    } while (next_permutation(perm.begin(), perm.end()));
    cout << endl;

    // =========================================================================
    // 7. SWAP()
    // =========================================================================
    cout << "--- 7. SWAP() ---" << endl;
    int a = 100, b = 200;
    cout << "Before swap: a = " << a << ", b = " << b << endl;
    swap(a, b); // Swaps in O(1)
    cout << "After swap : a = " << a << ", b = " << b << endl << endl;

    // =========================================================================
    // 8. ACCUMULATE()
    // =========================================================================
    cout << "--- 8. ACCUMULATE() ---" << endl;
    // Syntax: accumulate(start_it, end_it, initial_sum);
    // Requires #include <numeric>
    vector<int> sumVec = {10, 20, 30, 40, 50};
    int totalSum = accumulate(sumVec.begin(), sumVec.end(), 0);
    cout << "Sum of elements {10, 20, 30, 40, 50} with init 0: " << totalSum << endl << endl;

    // =========================================================================
    // 9. FIND()
    // =========================================================================
    cout << "--- 9. FIND() ---" << endl;
    // Syntax: find(start_it, end_it, target_val);
    // Returns iterator to first occurrence, or end_it if not found.
    vector<int> listNums = {10, 25, 40, 55, 70};
    int searchVal = 40;

    auto findIt = find(listNums.begin(), listNums.end(), searchVal);
    if (findIt != listNums.end()) {
        cout << searchVal << " was found at index: " << (findIt - listNums.begin()) << endl;
    } else {
        cout << searchVal << " was not found." << endl;
    }

    return 0;
}
