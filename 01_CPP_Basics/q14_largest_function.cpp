#include<iostream>
using namespace std;
int largest(int num1,int num2){
    int res;
    if(num1>num2){
        res=num1;
    }
    else {
        res=num2;
    }
    return res;
}
int main(){
    int num1,num2,largest_num;
    cout << "Enter two numbers; ";
    cin >> num1 >> num2;
    largest_num=largest(num1,num2);
    cout<< "The larger number is " << largest_num;

}
