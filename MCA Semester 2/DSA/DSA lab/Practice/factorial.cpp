#include<iostream>
using namespace std;
int factorial(int n);
int main(){
    system("cls");
    int n;
    cout<<"Enter the Number for calculating factorial: ";
    cin>>n;
    cout<<"The factorial of "<<n<<" is: "<<factorial(n);
    return 0;
}
int factorial(int n){
    if(n <= 1){
        return n;
    }
    else{
        return n*=factorial(n-1);
    }
}
