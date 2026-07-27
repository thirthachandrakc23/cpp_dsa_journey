#include<iostream>
using namespace std;
int main(){
    long long num;
    cout << "Enter the multidigit number to count the digits: ";
    cin >> num;
    int count=1;
    for(long long i=num;i>=10;i=i/10){
        count+=1;
    }
    cout << count;
    return 0;

    }
    
       
    
