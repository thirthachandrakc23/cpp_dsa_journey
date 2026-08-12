#include<iostream>
using namespace std;
int main(){
    int n;
    cout << "Enter the number of rows: ";
    cin >> n;
    for(int i=0;i<n;i++){
        for(int k=1;k<=n-i-1;k++){
            cout << " ";
        }
        char ch='A';
        for(int j=1;j<=2*i+1;j++){
            cout << ch;
            if((2*i)/2>=j)ch=ch+1;
            else ch=ch-1;
        }
        cout << endl;
    }
    return 0;
}