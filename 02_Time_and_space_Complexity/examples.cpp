#include<iostream>
using namespace std;

int main()
{

    //=============================
    // Example 1
    //=============================

    cout << "Example 1" << endl;

    for(int i = 0; i < 10; i++)
    {

    }

    // Time Complexity : O(1)
    // Because the loop always runs 10 times.


    //=============================
    // Example 2
    //=============================

    cout << "Example 2" << endl;

    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
    {

    }

    // Time Complexity : O(N)


    //=============================
    // Example 3
    //=============================

    cout << "Example 3" << endl;

    for(int i = 0; i < n; i++)
    {

    }

    for(int j = 0; j < n; j++)
    {

    }

    // O(N + N)
    // O(2N)
    // O(N)


    //=============================
    // Example 4
    //=============================

    cout << "Example 4" << endl;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {

        }
    }

    // O(N²)


    //=============================
    // Example 5
    //=============================

    cout << "Example 5" << endl;

    for(int i = 0; i < n; i++)
    {

    }

    for(int j = 0; j < n; j++)
    {
        for(int k = 0; k < n; k++)
        {

        }
    }

    // O(N) + O(N²)
    // O(N²)


    //=============================
    // Example 6
    //=============================

    cout << "Example 6" << endl;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            for(int k = 0; k < n; k++)
            {

            }
        }
    }

    // O(N³)

    return 0;
}
