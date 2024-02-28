#include<iostream>
using namespace std;
int toh(int n, char src_rod, char Aux_rod, char Dest_rod);
int main(){
    system("cls");
    int n;
    char A = 'A' , B = 'B', C = 'C';
    cout<<"Enter the number of disks: ";
    cin>>n;
    toh(n, A, B, C);

   
    return 0;
}
int toh(int n, char src_rod, char Aux_rod, char Dest_rod){
    if ( n == 0){
        return 0;
    }
    else{
        toh(n-1, src_rod, Dest_rod, Aux_rod);
        cout<<"Move disk "<< n<<" from rod "<<src_rod<<" to rod "<<Dest_rod<<endl;
        toh(n-1, Aux_rod, src_rod, Dest_rod );
    }
}