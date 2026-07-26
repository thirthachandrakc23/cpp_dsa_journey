#include<iostream>
using namespace std;
int main(){
    int num1,num2;
    cout << "Enter two numbers to check which is largest: ";
    cin >> num1 >> num2;
    if(num1>num2){
        cout<<"The largest number is " << num1;
    }
    else{
        cout <<"The largest number is " <<num2;
    }
}
