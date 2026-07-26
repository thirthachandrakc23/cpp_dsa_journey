#include<iostream>
using namespace std;
int main(){
    int operation;
    float num1,num2;
    cout << "Enter the two numbers to do operation: ";
    cin >>num1 >> num2; 
    cout << "ARTHEMATIC OPERATIONS" <<endl <<"1.ADDITION" <<endl << "2.SUBRACTION" <<endl << "3.MULTIPLICATION" <<endl <<"4.DIVISON";
    cout << endl << "Enter the choice to do operation needed: ";
    cin >> operation;
    switch(operation){
        case 1:{
            cout << "The addition of two numbers is " <<num1 + num2;
            break;
        }
        case 2:{
            cout << "The subraction of two numbers is " << num1-num2;
            break;
        }
        case 3:{
            cout << "The multiplacation of two numbers is " << num1*num2;
            break;
        }
        case 4:{
            if(num2==0){
                cout << "Divison by zero not possible";
            }
            else{
                cout << "the division of two numbers is " << num1/num2;
            }
            break;
        }
        default:{
            cout << "Invalid choice";
        }

    }
    return 0;

}