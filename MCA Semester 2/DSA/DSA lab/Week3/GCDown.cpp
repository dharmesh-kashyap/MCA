#include<iostream>
using namespace std;
int gcd(int x, int y);
int main(){
    system("cls");
    int x, y;
    cout<<"Enter the first number: ";
    cin>>x;
    cout<<"Enter the second number: ";
    cin>>y;
    cout<<"The greatest common diviser is: "<<gcd(x,y)<<"\n";

    return 0;
}
int gcd(int x, int y){
    if (x<=0 || y<=0){
        return 0;
    }
    else if(x==y){
        return x;
    }
    else if(x>y){
        return gcd(x-y,y);
    }
    else{
        return gcd(x, y-x);
    }
}
