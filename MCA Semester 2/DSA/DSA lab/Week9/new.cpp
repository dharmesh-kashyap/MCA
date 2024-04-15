#include<iostream>
using namespace std;
int main(){
    cout<<"Enter the String: ";
    string str, str2;
    cin>>str;

    for (int i = 0; i < str.length(); i++)
    {
        str2 += str[i] + 19;
    }

    cout<<str2;
    
    return 0;
}