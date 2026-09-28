#include<bits/stdc++.h>
using namespace std;
bool check_sort(int arr[10],int n){
        for(int i=1;i<=n;i++){
        if(arr[i]>arr[i-1]){

        }
        else{
            return false;
        }
}
return true;
}
int main(){
    int arr[10];
    int n;
    cout << "Enter the size of array : ";
    cin >> n;
    for(int i=0;i<n;i++){
        cout << "Enter array element: ";
        cin >> arr[i];
    }
    bool result=check_sort(arr,n);
    cout << result;
    return 0;
}