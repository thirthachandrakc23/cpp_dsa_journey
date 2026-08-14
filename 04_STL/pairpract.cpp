#include <bits/stdc++.h>
using namespace std;
void practpair(){
    pair<int , int> p={2,3};
    cout << p.first << p.second << endl ;


    pair<int , pair<int ,int>> p2={4,{6,7}};
    cout << p2.first << p2.second.first << p2.second.second;
    cout << endl;

    pair<int ,int> arr[3]={{1,2},{3,4},{5,6}};
    cout << arr[1].first << arr[1].second << arr[2].first << arr[2].second;
}
int main(){
    practpair();
    return 0;
}
