#include<iostream>
using namespace std;
int main ()
{
 int upp_lim,low_lim;
 cout<<"Enter upper and lower limit: ";
 cin>>low_lim>>upp_lim;
 int c = low_lim;
 while(c <= upp_lim){
    int factor = 1,flag = 0;
    while(factor<=c){
        if(c%factor==0){
            flag++;
        }
        factor++;
    }
    if(flag==2){
        cout<<c<<" ";
    }
    c++;
 }

}