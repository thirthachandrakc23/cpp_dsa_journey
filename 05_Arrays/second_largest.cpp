#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[5]={1,1,4,7,5};
    int max=arr[0];
    int slargest=-1;
    for(int i=0;i<5;i++){
        if(arr[i]>max){
            slargest=max;
            max=arr[i];
        }
        else if(arr[i]<max && arr[i]>slargest){
            slargest =arr[i];
        }
    }
    cout << max << endl;
    cout << slargest;
    return 0;
}