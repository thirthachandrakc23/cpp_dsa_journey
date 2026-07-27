#include<iostream>
using namespace std;
void _even_odd(int num){
    if(num%2==0){
        cout << "The number is even";
    }
    else{
        cout << "The number is odd";
    }
}
int main(){
    int num;
    cout << "Enter the number: ";
    cin >> num;
    _even_odd(num);
    return 0;
}