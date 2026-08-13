#include<iostream>
using namespace std;
int main(){
    int n;
    cout << "Enter the number of lines required for square pattern: ";
    cin >> n;
    char ch='A';
    ch=ch+n;
    for(int i=1;i<=n;i++){
        ch=ch-i;
        for(int j=0;j<i;j++){
            cout << ch << " ";
            ch=ch+1;
        }
        cout << endl;
       
    }
    return 0;
}