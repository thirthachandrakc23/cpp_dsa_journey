// ========================================
// UNORDERED MAP - STL REVISION
// ========================================
//
// 1. WHAT IS IT?
//    - std::unordered_map is an associative container that stores KEY-VALUE pairs
//      with UNIQUE keys, but in NO PARTICULAR ORDER.
//    - Implemented under the hood as a HASH TABLE.
//    - The #1 go-to data structure in coding interviews for fast lookups.
//
// 2. DECLARATION
//    - unordered_map<string, int> ump;   // Key: string, Value: int
//    - unordered_map<int, int> freq;     // Key: int, Value: int
//
// 3. BASIC OPERATIONS
//    - ump[key] = val      : Inserts or updates the value for key.
//    - ump.insert({k, v})  : Inserts key-value pair if key doesn't exist.
//    - ump.erase(key)      : Removes the entry with key.
//    - ump.find(key)       : Returns iterator if key found, else ump.end().
//    - ump.count(key)      : Returns 1 if key exists, 0 otherwise.
//    - ump.size()          : Returns total number of key-value pairs.
//    - ump.empty()         : Checks if map is empty.
//    - ump.clear()         : Removes all pairs.
//
// 4. COMPARISON: MAP VS UNORDERED_MAP (INTERVIEW FAVORITE!)
//    --------------------------------------------------------------------------
//    Feature           | std::map                | std::unordered_map
//    ------------------+-------------------------+-----------------------------
//    Internal Structure| Red-Black Tree (BST)    | Hash Table
//    Ordering          | Sorted by keys          | Random / Unordered
//    Average Search    | O(log N)                | O(1)
//    Average Insert    | O(log N)                | O(1)
//    Average Erase     | O(log N)                | O(1)
//    Worst Case Time   | O(log N)                | O(N) (due to hash collisions)
//    Allowed Key Types | Needs < operator defined| Needs std::hash defined
//    --------------------------------------------------------------------------
//
// 5. TIME COMPLEXITY
//    - Insert, Search, Erase : AVERAGE O(1), WORST-CASE O(N)
//    - Size, Empty           : O(1)
//
// 6. DSA CONNECTION
//    - Frequency counting when order doesn't matter (O(N) total time).
//    - Two Sum (storing seen elements: index mapping).
//    - Subarray Sum Equals K (storing prefix sum frequencies).
//    - Group Anagrams (mapping sorted string or signature to vector of strings).
//    - Longest Substring Without Repeating Characters.
// ========================================

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

int main() {
    cout << "--- 1. DECLARATION & INSERTION (KEY-VALUE, UNORDERED) ---" << endl;
    unordered_map<string, int> capitalPopulations;

    // Inserting key-value pairs
    capitalPopulations["Tokyo"] = 37;
    capitalPopulations["Delhi"] = 32;
    capitalPopulations["Shanghai"] = 28;
    capitalPopulations["Sao Paulo"] = 22;

    cout << "Contents of unordered_map (Notice: order is NOT sorted):" << endl;
    for (const auto& p : capitalPopulations) {
        cout << p.first << " : " << p.second << " million" << endl;
    }
    cout << endl;

    cout << "--- 2. LOOKUP USING find() AND [] ---" << endl;
    string city = "Tokyo";
    if (capitalPopulations.find(city) != capitalPopulations.end()) {
        cout << city << " population: " << capitalPopulations[city] << " million" << endl;
    }

    if (capitalPopulations.count("Paris") == 0) {
        cout << "Paris is not in the map." << endl;
    }
    cout << endl;

    cout << "--- 3. ERASE OPERATION ---" << endl;
    cout << "Size before erase: " << capitalPopulations.size() << endl;
    capitalPopulations.erase("Delhi");
    cout << "Size after erasing Delhi: " << capitalPopulations.size() << endl << endl;

    cout << "--- 4. FREQUENCY COUNTING (CLASSIC DSA PATTERN) ---" << endl;
    // Given an array of integers, count the frequency of each number
    vector<int> nums = {4, 1, 2, 4, 3, 2, 4, 1, 4};
    unordered_map<int, int> freq;

    for (int x : nums) {
        freq[x]++; // O(1) average per insertion/update
    }

    cout << "Frequency of each element (O(N) total time):" << endl;
    for (const auto& entry : freq) {
        cout << "Element " << entry.first << " appears " << entry.second << " time(s)" << endl;
    }
    cout << endl;

    cout << "--- 5. MINI DSA EXAMPLE: TWO SUM CHECK ---" << endl;
    // Check if any two numbers add up to target
    vector<int> arr = {2, 7, 11, 15};
    int target = 9;
    unordered_map<int, int> seenIndex; // stores value -> index
    bool foundPair = false;

    for (int i = 0; i < arr.size(); i++) {
        int complement = target - arr[i];
        if (seenIndex.find(complement) != seenIndex.end()) {
            cout << "Two sum pair found! Values: " << complement << " + " << arr[i] 
                 << " = " << target << " (at indices " << seenIndex[complement] 
                 << " and " << i << ")" << endl;
            foundPair = true;
            break;
        }
        seenIndex[arr[i]] = i;
    }

    if (!foundPair) {
        cout << "No two sum pair found." << endl;
    }

    return 0;
}
