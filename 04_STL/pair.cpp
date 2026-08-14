#include <bits/stdc++.h>
using namespace std;

void explainPair() {
    

    // Basic pair
    pair<int, int> p = {1, 3};

    cout << p.first << " " << p.second << endl;


    // Nested pair
    pair<int, pair<int, int>> p2 = {1, {3, 4}};

    cout << p2.first << " "
         << p2.second.first << " "
         << p2.second.second << endl;


    // Array of pairs
    pair<int, int> arr[] = {{1, 2}, {2, 5}, {5, 1}};

    cout << arr[1].second << endl;
}
     

int main() {

    explainPair();

    return 0;
}