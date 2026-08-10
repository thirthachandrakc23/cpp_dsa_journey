#include<iostream>
using namespace std;
int main(){
    int n;
    cout << "Enter the number of lines required for square pattern: ";
    cin >> n;
    for(int i=0;i<n;i++){

        for(int j=1;j<=n-i;j++){
            cout << n-i;    
        }
        cout << endl;
        

    }
    return 0;
}