#include<iostream>
using namespace std;
int main(){
    int num;
    cout << "Enter the number to check positive ,negative or zero: ";
    cin >> num;
    if(num>0){
        cout <<"POSITIVE";
    }
    else if(num<0){
        cout << "NEGATIVE";
    }
    else{
        cout <<"ZEROO";
    }
    return 0;
}