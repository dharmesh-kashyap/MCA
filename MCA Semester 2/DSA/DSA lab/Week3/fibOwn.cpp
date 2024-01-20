#include<iostream>
using namespace std;
int fib(int n);
int main(){
    system("cls");
    int n;
    cout<<"Enter the number of terms: ";
    cin>>n;
    int x = 0;
    while(x<n){
        cout<<" "<<fib(x);
        x++;
    }
    return 0;
}
int fib(int n){
    if (n<=1){
        return n;
    }
    else{
        return (fib(n-1)+fib(n-2));
    }
}