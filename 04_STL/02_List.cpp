// ========================================
// LIST - STL REVISION
// ========================================
//
// 1. WHAT IS IT?
//    - std::list is a sequence container implemented as a DOUBLY LINKED LIST.
//    - Elements are not stored in contiguous memory locations.
//    - Each element has pointers to both the next and previous elements.
//
// 2. DECLARATION
//    - list<int> l;                      // Empty list of integers
//    - list<int> l(4, 10);               // List of size 4, all initialized to 10: {10, 10, 10, 10}
//    - list<int> l2(l);                  // Copy of list l
//
// 3. BASIC OPERATIONS
//    - push_back(val)  : Inserts an element at the end.
//    - push_front(val) : Inserts an element at the beginning (O(1)).
//    - pop_back()      : Removes the last element.
//    - pop_front()     : Removes the first element (O(1)).
//    - front()         : Accesses the first element.
//    - back()          : Accesses the last element.
//    - insert(it, val) : Inserts value before iterator position.
//    - erase(it)       : Removes element at iterator position.
//    - remove(val)     : Removes ALL elements with the given value.
//    - size()          : Returns the number of elements.
//    - empty()         : Returns true if list is empty, false otherwise.
//    - clear()         : Removes all elements.
//
// 4. TRAVERSAL METHODS
//    - Range-based for loop : for (int x : l)
//    - Iterator-based loop  : for (auto it = l.begin(); it != l.end(); ++it)
//    - NOTE: Indexing like l[i] is NOT supported because elements are not contiguous!
//
// 5. IMPORTANT OBSERVATIONS: VECTOR VS LIST
//    - Vector:
//      * Contiguous memory array.
//      * O(1) random access (v[i]).
//      * Inefficient front insertion (O(N)) because elements must shift.
//    - List:
//      * Non-contiguous memory (Doubly Linked List).
//      * NO direct random access (cannot do l[i]).
//      * Efficient front and back insertion/deletion in O(1) time.
//      * Fast insertion and deletion at any position in O(1) if you already have the iterator.
//
// 6. TIME COMPLEXITY
//    - push_front(), push_back() : O(1)
//    - pop_front(), pop_back()   : O(1)
//    - insert(), erase() (at it) : O(1)
//    - remove(val)               : O(N) (needs to search the list)
//    - Accessing an element      : O(N) (must traverse from head or tail)
//
// 7. DSA CONNECTION
//    - Used when frequent insertions and deletions at both ends or middle are needed.
//    - Core data structure for implementing LRU Cache (Least Recently Used Cache)
//      alongside an unordered_map.
// ========================================

#include <iostream>
#include <list>

using namespace std;

int main() {
    cout << "--- 1. DECLARATION & PUSH OPERATIONS ---" << endl;
    list<int> myList;

    // Adding elements to back and front
    myList.push_back(20);       // List: {20}
    myList.push_back(30);       // List: {20, 30}
    myList.push_front(10);      // List: {10, 20, 30} -> O(1) operation!
    myList.push_front(5);       // List: {5, 10, 20, 30}

    cout << "List after push_back and push_front: ";
    for (int x : myList) {
        cout << x << " ";
    }
    cout << endl << endl;

    cout << "--- 2. FRONT, BACK, SIZE, EMPTY ---" << endl;
    cout << "Front element: " << myList.front() << endl;
    cout << "Back element: " << myList.back() << endl;
    cout << "Size of list: " << myList.size() << endl;
    cout << "Is list empty? " << (myList.empty() ? "Yes" : "No") << endl << endl;

    cout << "--- 3. POP_FRONT & POP_BACK ---" << endl;
    myList.pop_front();         // Removes 5
    myList.pop_back();          // Removes 30

    cout << "After pop_front() and pop_back(): ";
    for (int x : myList) cout << x << " ";
    cout << endl << endl;

    cout << "--- 4. INSERT AND ERASE USING ITERATOR ---" << endl;
    // Current list: {10, 20}
    auto it = myList.begin();   // it points to 10
    ++it;                       // it now points to 20

    // insert 15 before 20
    myList.insert(it, 15);      // List becomes: {10, 15, 20}
    cout << "After inserting 15 before 20: ";
    for (int x : myList) cout << x << " ";
    cout << endl;

    // erase the element 15 (it is currently pointing to 20, let's point to 15)
    it = myList.begin();
    ++it;                       // Points to 15
    myList.erase(it);           // Removes 15 -> List becomes: {10, 20}
    cout << "After erasing 15: ";
    for (int x : myList) cout << x << " ";
    cout << endl << endl;

    cout << "--- 5. REMOVE BY VALUE ---" << endl;
    // myList.remove(val) removes ALL occurrences of val from the list
    myList.push_back(10);
    myList.push_back(40);
    myList.push_back(10);
    cout << "List before remove(10): ";
    for (int x : myList) cout << x << " ";
    cout << endl;

    myList.remove(10);          // Removes ALL occurrences of 10
    cout << "List after remove(10): ";
    for (int x : myList) cout << x << " ";
    cout << endl << endl;

    cout << "--- 6. TRAVERSAL METHODS ---" << endl;
    // Method A: Range-based for loop
    cout << "Traversal using range-based loop: ";
    for (int val : myList) {
        cout << val << " ";
    }
    cout << endl;

    // Method B: Iterator-based loop
    cout << "Traversal using iterators: ";
    for (list<int>::iterator listIt = myList.begin(); listIt != myList.end(); ++listIt) {
        cout << *listIt << " ";
    }
    cout << endl;

    // NOTE: myList[0] will NOT compile! List does not support random access indexing.

    return 0;
}
