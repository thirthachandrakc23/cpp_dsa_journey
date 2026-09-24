#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[5]={1,7,4,6,9};
    int small=arr[0];
    int ssmallest=INT_MAX;
    for(int i=0;i<5;i++){
        if(arr[i]<small){
            ssmallest=small;
            small=arr[i];
        }
        else if(arr[i]!=small && arr[i]<ssmallest){
            ssmallest=arr[i];
        }

    }
    cout << small << endl;
    cout << ssmallest;
    return 0;
}
