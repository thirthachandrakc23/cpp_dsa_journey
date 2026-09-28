#include<bits/stdc++.h>
using namespace std;
int RemoveDuplicates(vector<int> &arr,int n){
    int i=0,j;
    for(j=1;j<n;j++){
        if(arr[j]!=arr[i]){
            arr[i+1]=arr[j];
            i++;
        }
    }
    return i+1;
}
int main(){
    int n;
    cout << "Enter the size of array : ";
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cout << "Enter array element: ";
        cin >> arr[i];
    }
    int result=RemoveDuplicates(arr,n);
    cout << result;
    return 0;

}