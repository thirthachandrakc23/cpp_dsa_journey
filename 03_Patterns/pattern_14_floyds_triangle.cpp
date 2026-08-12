#include<iostream>
using namespace std;
int main(){
    int n;
    cout << "enter the number of lines required: ";
    cin >> n;
    int start=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout << start << " ";
            start=start+1;
        }
        cout << endl;
    }
    return 0;
}
