// ========================================
// MULTIMAP - STL REVISION
// ========================================
//
// 1. WHAT IS IT?
//    - std::multimap is an associative container that stores KEY-VALUE pairs in
//      SORTED order by key, BUT ALLOWS DUPLICATE KEYS.
//    - Multiple pairs can have the exact same key.
//    - Implemented as a Red-Black Tree.
//
// 2. DECLARATION
//    - multimap<string, int> mm;         // Key: string, Value: int
//    - multimap<int, string> mm2;        // Key: int, Value: string
//
// 3. BASIC OPERATIONS
//    - insert({key, val}) : Inserts key-value pair (duplicates allowed).
//    - erase(key)         : Removes ALL pairs with the specified key!
//    - erase(it)          : Removes ONLY the pair at iterator position!
//    - find(key)          : Returns iterator to the FIRST pair with that key.
//    - count(key)         : Returns total number of pairs with that key.
//    - equal_range(key)   : Returns pair of iterators [first, last) for all entries with that key.
//    - size(), empty()    : Standard size checks.
//
// 4. IMPORTANT OBSERVATION: NO [] OPERATOR!
//    - In std::map, you can do mp["Alice"] = 10.
//    - In std::multimap, operator[] is NOT supported (compilation error)!
//      Why? Because multiple values can exist for the same key, so mm["Alice"]
//      would be ambiguous (which value should it return?).
//    - Insertion MUST be done using mm.insert({key, value}).
//
// 5. IMPORTANT DIFFERENCE: MAP VS MULTIMAP
//    - map:
//      * Keys are UNIQUE and SORTED.
//      * Supports operator[].
//      * count(key) is 0 or 1.
//    - multimap:
//      * Duplicate keys ALLOWED and SORTED.
//      * Does NOT support operator[].
//      * count(key) can be > 1.
//
// 6. TIME COMPLEXITY
//    - insert() : O(log N)
//    - erase(key) : O(log N + count)
//    - find(key) : O(log N)
//    - count(key): O(log N + count)
//
// 7. DSA CONNECTION
//    - Grouping multiple records or values under the same key in sorted order.
//    - Graph adjacency list with edge weights when multiple edges can connect same vertices.
//    - Inverted indices (e.g. mapping word to multiple document IDs).
// ========================================

#include <iostream>
#include <map> // multimap is in <map>
#include <string>

using namespace std;

int main() {
    cout << "--- 1. DECLARATION & INSERTION (DUPLICATE KEYS) ---" << endl;
    multimap<string, int> studentGrades;

    // Insertion MUST be done via insert() or emplace()
    // Notice: "Alice" has multiple different grades!
    studentGrades.insert({"Alice", 90});
    studentGrades.insert({"Bob", 85});
    studentGrades.insert({"Alice", 95}); // Duplicate key "Alice"
    studentGrades.insert({"Charlie", 78});
    studentGrades.insert({"Alice", 88}); // Third entry for "Alice"

    cout << "Contents of multimap (sorted by key):" << endl;
    for (const auto& p : studentGrades) {
        cout << p.first << " : " << p.second << endl;
    }
    cout << endl;

    cout << "--- 2. COUNT AND FIND ---" << endl;
    cout << "Number of grades for Alice: " << studentGrades.count("Alice") << endl;
    cout << "Number of grades for Bob  : " << studentGrades.count("Bob") << endl;

    // find() returns iterator to the FIRST instance of the key
    auto it = studentGrades.find("Alice");
    if (it != studentGrades.end()) {
        cout << "First grade found for Alice: " << it->second << endl;
    }
    cout << endl;

    cout << "--- 3. RETRIEVING ALL VALUES FOR A SPECIFIC KEY ---" << endl;
    // equal_range() gives [first_it, last_it) for the key
    auto range = studentGrades.equal_range("Alice");
    cout << "All grades for Alice: ";
    for (auto i = range.first; i != range.second; ++i) {
        cout << i->second << " ";
    }
    cout << endl << endl;

    cout << "--- 4. ERASE: SINGLE vs ALL OCCURRENCES ---" << endl;
    cout << "Size before erase: " << studentGrades.size() << endl;

    // Case A: Erase ONLY ONE entry of "Alice" using iterator
    studentGrades.erase(studentGrades.find("Alice"));
    cout << "After erasing ONE entry of Alice, count is: " 
         << studentGrades.count("Alice") << endl;

    // Case B: Erase ALL entries of "Bob" using key
    studentGrades.erase("Bob");
    cout << "After erasing Bob by key, Bob count is: " 
         << studentGrades.count("Bob") << endl;

    cout << "Final multimap entries:" << endl;
    for (const auto& p : studentGrades) {
        cout << p.first << " : " << p.second << endl;
    }

    return 0;
}
