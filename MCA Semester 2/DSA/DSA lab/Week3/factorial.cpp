#include<iostream>
using namespace std;

int factorial(int n){
    if(n<=1){
        return 1;
    }
    else{
        return n*=factorial(n-1);
    }
}
int main(){
    system("cls");
    int n;
    cout<<"Enter the value : ";
    cin>>n;
    cout<<"The value of factorial is: "<<factorial(n)<<"\n";

} 