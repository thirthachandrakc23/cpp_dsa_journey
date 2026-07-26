#include<iostream>
using namespace std;
int main(){
    int num;
    cout <<"Enter the number to check odd or even: ";
    cin >> num;
    if(num%2==0){
        cout <<"The entered number is even";
    }
    else{
        cout <<"The entered number is odd";
    }
    return 0;


}