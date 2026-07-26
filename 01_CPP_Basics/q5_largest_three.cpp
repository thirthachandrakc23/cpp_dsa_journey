#include<iostream>
using namespace std;
int main(){
    int num1,num2,num3;
    cout << "Enter three numbers to check which is largest: " ;
    cin >> num1 >>num2 >>num3;
    if(num1 > num2 && num1 > num3){
        cout<< "The largest number is " << num1;
    }
    else if(num2 > num1 && num2 > num3){
        cout<< "The largest number is " << num2;
    }
    else if(num3 > num1 && num3 > num2){
        cout<< "The largest number is " << num3;
    }
    else{
        cout<< "all are eual";
    }
    return 0;
}