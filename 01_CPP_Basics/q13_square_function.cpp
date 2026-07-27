#include<iostream>
using namespace std;
int square(int num){
    return num*num;
}
int main(){
    int num, res;
    cout << "ENTER THE NUMBER: ";
    cin >> num;
    res=square(num);
    cout << "The square is " <<res;
    return 0;

}