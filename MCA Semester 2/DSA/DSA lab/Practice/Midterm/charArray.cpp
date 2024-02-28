#include<iostream>
using namespace std;
int main(){
    char arr[100];
    cout<<"Enter the Character array: ";
    cin>>arr;
    int counter = 0;
    for(char index : arr){
        if(index == '\0'){
            break;
        }
        counter++;
    }
    cout<<"The length of the Character array is : "<<(counter)<<endl;
    return 0;
}
