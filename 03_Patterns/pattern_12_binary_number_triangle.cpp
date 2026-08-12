#include<iostream>
using namespace std;
int main(){
    int n;
    cout << "enter the number of lines required: ";
    cin >> n;
    int start=1;
    for(int i=0;i<n;i++){
        if(i%2==0)start=1;
        for(int j=0;j<=i;j++){
            cout << start;
            start=1-start;

        }
        cout << endl;

    }
}
