#include<iostream>
using namespace std;
void add(int num1,int num2,int num3){
    num3=num1=num2;
    cout << "The addition of two number is " << num3;
}
int main(){
    int num1,num2,num3;
    cout << "Enter two numbers to add: ";
    cin >>num1 >>num2;
    add(num1,num2,num3);
    return 0;

}