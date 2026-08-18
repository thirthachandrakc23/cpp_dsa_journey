#include<bits/stdc++.h>
using namespace std;
void explainvector(){


    vector<int> v;

    v.push_back(1);
    v.emplace_back(2);

    vector<pair<int, int>>vec;

    vec.push_back({1,2});
    vec.emplace_back(1,2);   

    vector<int> vec(5,100);

    vector<int> vec(5);

    vector<int> vec1(5,20);
    vector<int> vec2(vec1);
}
int main(){
    explainvector();
    return 0;
}