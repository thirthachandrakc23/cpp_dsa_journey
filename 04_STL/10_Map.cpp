// ========================================
// MAP - STL REVISION
// ========================================
//
// 1. WHAT IS IT?
//    - std::map is an associative container that stores data in KEY-VALUE pairs:
//      pair<const Key, Value>.
//    - Keys are UNIQUE and always maintained in SORTED order.
//    - Implemented under the hood as a Self-Balancing BST (Red-Black Tree).
//
// 2. DECLARATION
//    - map<string, int> ageMap;          // Key: string, Value: int
//    - map<int, int> freqMap;            // Key: int, Value: int
//    - map<int, string, greater<int>> m; // Keys stored in descending order
//
// 3. BASIC OPERATIONS
//    - mp[key] = value     : Inserts or updates the value associated with key.
//    - mp.insert({key, val}): Inserts key-value pair if key doesn't exist.
//    - mp.erase(key)       : Removes the entry with key.
//    - mp.find(key)        : Returns iterator to entry if key exists, else mp.end().
//    - mp.count(key)       : Returns 1 if key exists, 0 otherwise.
//    - mp.size()           : Returns number of key-value pairs.
//    - mp.empty()          : Checks if map is empty.
//    - mp.clear()          : Removes all elements.
//
// 4. TRAVERSAL & PAIR ACCESS
//    - Each element in a map is a pair:
//      * pair.first  -> The KEY
//      * pair.second -> The VALUE
//    - Traversal with range-based loop:
//      for (const auto& p : mp) {
//          cout << p.first << " -> " << p.second << endl;
//      }
//
// 5. IMPORTANT OBSERVATION: THE mp[key] PITFALL!
//    - Accessing mp[key] creates a new entry with DEFAULT value (0 for int, "" for string)
//      if key does not already exist!
//    - To check for existence without inserting a default entry, use find() or count()!
//
// 6. TIME COMPLEXITY
//    - Insertion mp[k] = v : O(log N)
//    - Access mp[k]        : O(log N)
//    - find()              : O(log N)
//    - erase()             : O(log N)
//    - size()              : O(1)
//
// 7. DSA CONNECTION
//    - Counting frequencies of elements when output needs to be in sorted order.
//    - Coordinate compression.
//    - Maintaining sorted intervals or ranges (e.g. TreeMap problems).
//    - Finding previous/next key using lower_bound() / upper_bound().
// ========================================

#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

int main() {
    cout << "--- 1. DECLARATION & INSERTION (KEY-VALUE) ---" << endl;
    map<string, int> marks;

    // Method 1: Using [] operator
    marks["Math"] = 95;
    marks["English"] = 88;
    marks["Science"] = 92;

    // Method 2: Using insert()
    marks.insert({"History", 85});

    // Updating an existing key
    marks["English"] = 90; // Overwrites 88 with 90

    cout << "Map contents (Notice: keys are sorted alphabetically):" << endl;
    for (const auto& p : marks) {
        cout << p.first << " : " << p.second << endl;
    }
    cout << endl;

    cout << "--- 2. ACCESSING ELEMENTS & THE [] PITFALL ---" << endl;
    cout << "Math marks: " << marks["Math"] << endl;

    // Caution: Reading a non-existent key with [] creates it!
    cout << "Size before accessing non-existent 'Art': " << marks.size() << endl;
    cout << "Accessing marks['Art']: " << marks["Art"] << " (default value 0 created!)" << endl;
    cout << "Size after accessing 'Art': " << marks.size() << endl << endl;

    // SAFE WAY to check existence: find() or count()
    if (marks.find("Music") != marks.end()) {
        cout << "Music exists!" << endl;
    } else {
        cout << "Music does NOT exist (and was NOT created)!" << endl;
    }
    cout << endl;

    cout << "--- 3. ERASE OPERATION ---" << endl;
    marks.erase("Art"); // Remove the unwanted "Art" entry
    cout << "Size after erasing 'Art': " << marks.size() << endl << endl;

    cout << "--- 4. TRAVERSAL METHODS ---" << endl;
    // Method A: Range-based loop
    cout << "Method A (Range-based loop):" << endl;
    for (const auto& p : marks) {
        cout << "Subject: " << p.first << ", Score: " << p.second << endl;
    }

    // Method B: Iterator-based loop
    cout << "\nMethod B (Iterator-based loop):" << endl;
    for (map<string, int>::iterator it = marks.begin(); it != marks.end(); ++it) {
        cout << it->first << " -> " << it->second << endl;
    }
    cout << endl;

    cout << "--- 5. CLASSIC DSA EXAMPLE: FREQUENCY COUNTING ---" << endl;
    // Count the frequency of each number in an array
    vector<int> numbers = {2, 5, 2, 8, 5, 2, 8, 1};
    map<int, int> freq;

    for (int num : numbers) {
        freq[num]++; // If num doesn't exist, initializes to 0, then increments to 1
    }

    cout << "Frequency of each element (in sorted order of keys):" << endl;
    for (const auto& entry : freq) {
        cout << "Number " << entry.first << " occurs " << entry.second << " time(s)" << endl;
    }

    return 0;
}
