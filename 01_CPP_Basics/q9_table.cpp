#include<iostream>
using namespace std;
int main(){
    int num;
    cout << "Enter the number to get multiplication table:  ";
    cin >> num;
    for(int i=1;i<=10;i++){
        cout << num << " x " << i << " = " << num*i <<endl;
    }
}