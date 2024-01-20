#include<iostream>
using namespace std;
int gcd(int a, int b) {
   if (a == 0 || b == 0)
   return 0;
   else if (a == b)
   return a;
   else if (a > b)
   return gcd(a-b, b);
   else return gcd(a, b-a);
}
int main() {
    system("cls");
   int a, b;
   cout<<"Enter the First number: ";
   cin>>a;
   cout<<"Enter the second number: ";
   cin>>b;
   cout<<"GCD of "<< a <<" and "<< b <<" is "<< gcd(a, b);
   return 0;
}