#include<iostream>
using namespace std;
int main(){
    int n;
    cout << "Enter the number of lines required for square pattern: ";
    cin >> n;
    for(int i=0;i<n;i++){

        for(int k=1;k<=i;k++){
            cout << " ";    
        }
        for(int j=1;j<=2*n-(2*i+1);j++){
            cout << "*";
        }
        cout << endl;
        

    }
    return 0;
}