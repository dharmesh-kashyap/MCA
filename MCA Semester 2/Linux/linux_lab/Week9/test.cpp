#include<iostream>
using namespace std;
int mutex = 1;
int empty = 5;
int full = 0;
int x = 0;

void producer(){
    --mutex;
    --empty;
    ++full;
    x++;
    cout<<"Producer produced item : "<<x<<endl;
    ++mutex;

}

void consumer(){
    --mutex;
    ++empty;
    --full;
    cout<<"Producer produced item : "<<x<<endl;
    x--;
    ++mutex;

}
void buffer_val(){
    cout<<"\nValue of full"<<full<<endl;
    cout<<"Value of empty: "<<empty<<endl;
}

int main(){
    return 0;

    int n, i = 0 ;

    do{
        cout<<"Enter the choice: \n";
        cin>>n;
        switch(n){
            case 1:
                
            break;
            case 2: 
            break;
            case 3:
            break;
            case 4: 
            break;

        }
    }while( i == 0);

}