#include<iostream>
using namespace std;

int main()
{

    //=============================
    // Example 1
    //=============================

    cout << "Example 1" << endl;

    int sum = 0;

    // Space Complexity : O(1)
    // Only one extra variable is used.



    //=============================
    // Example 2
    //=============================

    cout << "Example 2" << endl;

    int a, b, c;

    // Space Complexity : O(1)
    // Fixed number of variables.



    //=============================
    // Example 3
    //=============================

    cout << "Example 3" << endl;

    int arr[100];

    // Space Complexity : O(1)
    // Array size is fixed (100 elements).
    // It does not depend on N.



    //=============================
    // Example 4
    //=============================

    cout << "Example 4" << endl;

    int n;
    cin >> n;

    int arr[n];

    // Space Complexity : O(N)
    // Array size depends on input.



    //=============================
    // Example 5
    //=============================

    cout << "Example 5" << endl;

    int n;
    cin >> n;

    int arr[n];
    int sum = 0;

    // Space Complexity : O(N)
    // Array depends on N.
    // sum is constant.
    // O(N) + O(1) = O(N)



    //=============================
    // Example 6
    //=============================

    cout << "Example 6" << endl;

    int n;
    cin >> n;

    int matrix[n][n];

    // Space Complexity : O(N²)
    // Matrix contains N × N elements.



    return 0;
}