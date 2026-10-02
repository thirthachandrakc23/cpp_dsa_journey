// ========================================
// STACK - STL REVISION
// ========================================
//
// 1. WHAT IS IT?
//    - std::stack is a container adapter that follows the LIFO principle:
//      LAST IN, FIRST OUT.
//    - Think of it like a stack of plates: you place a new plate on the top,
//      and you can only take the topmost plate off first.
//
// 2. DECLARATION
//    - stack<int> s;                     // Empty stack of integers
//    - stack<string> strStack;           // Empty stack of strings
//
// 3. BASIC OPERATIONS
//    - push(val) : Pushes element onto the top of the stack.
//    - pop()     : Removes the topmost element.
//                  IMPORTANT: pop() has void return type! It does NOT return the value.
//    - top()     : Returns a reference to the topmost element (without removing it).
//    - empty()   : Returns true if the stack is empty, false otherwise.
//    - size()    : Returns the number of elements in the stack.
//
// 4. TRAVERSAL METHOD
//    - std::stack does NOT have iterators or index access (no begin(), end(), or s[i]).
//    - To view or process elements, inspect top() and pop() until empty().
//    - If you want to keep the original stack intact, create a copy before popping.
//
// 5. IMPORTANT OBSERVATIONS
//    - Always check !s.empty() before calling s.top() or s.pop() to prevent runtime crashes!
//    - To read and remove the top element:
//        int val = s.top(); // 1. Read first
//        s.pop();           // 2. Then remove
//
// 6. TIME COMPLEXITY
//    - push()  : O(1)
//    - pop()   : O(1)
//    - top()   : O(1)
//    - empty() : O(1)
//    - size()  : O(1)
//
// 7. DSA CONNECTION
//    - Valid Parentheses / Balanced Brackets matching: "()[]{}"
//    - Next Greater Element / Previous Smaller Element (Monotonic Stack)
//    - Reversing a string or array
//    - Removing adjacent duplicates or stars from strings (LeetCode 2390)
//    - Expression evaluation (Infix, Prefix, Postfix)
// ========================================

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    cout << "--- 1. DECLARATION & PUSH (LIFO ORDER) ---" << endl;
    stack<int> s;

    // Pushing elements onto the stack
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    cout << "Pushed elements: 10, 20, 30, 40 (in that order)" << endl;
    cout << "Current stack size: " << s.size() << endl;
    cout << "Current top element: " << s.top() << " (Last pushed was 40)" << endl << endl;

    cout << "--- 2. HOW TO READ AND REMOVE (top + pop) ---" << endl;
    // CRITICAL: pop() removes the element but DOES NOT RETURN it!
    // Always store s.top() first if you need the value.
    int removedValue = s.top();
    s.pop(); // Removes 40
    cout << "Value retrieved before popping: " << removedValue << endl;
    cout << "New top element after pop: " << s.top() << endl;
    cout << "Stack size after pop: " << s.size() << endl << endl;

    cout << "--- 3. TRAVERSING A STACK (COPY & POP) ---" << endl;
    // Since stack does not provide iterators, we make a copy so original stays safe
    stack<int> tempStack = s;

    cout << "Elements popped in LIFO order from top to bottom: ";
    while (!tempStack.empty()) {
        cout << tempStack.top() << " ";
        tempStack.pop();
    }
    cout << endl;
    cout << "Original stack size remains unchanged: " << s.size() << endl << endl;

    cout << "--- 4. MINI DSA EXAMPLE: REVERSING A STRING ---" << endl;
    string word = "HELLO";
    stack<char> charStack;

    // Push each character into stack
    for (char c : word) {
        charStack.push(c);
    }

    // Pop characters out (they come out in reverse order!)
    string reversedWord = "";
    while (!charStack.empty()) {
        reversedWord += charStack.top();
        charStack.pop();
    }

    cout << "Original string: " << word << endl;
    cout << "Reversed string: " << reversedWord << endl << endl;

    cout << "--- 5. MINI DSA EXAMPLE: BALANCED BRACKETS CONCEPT ---" << endl;
    // Quick demonstration of checking if simple parentheses matching works
    string expr = "(())";
    stack<char> bracketStack;
    bool isBalanced = true;

    for (char ch : expr) {
        if (ch == '(') {
            bracketStack.push(ch);
        } else if (ch == ')') {
            if (bracketStack.empty()) {
                isBalanced = false;
                break;
            }
            bracketStack.pop(); // matched a pair!
        }
    }
    if (!bracketStack.empty()) isBalanced = false;

    cout << "Checking brackets for \"" << expr << "\": " 
         << (isBalanced ? "Balanced" : "Not Balanced") << endl;

    return 0;
}
