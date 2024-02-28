#include<iostream>
using namespace std;
int max(int m, int n){
    if(m > n){
        return m;
    }
    else{
        return n;
    }
}

int getArray(int Array[],int size, const char* polynomial){
    cout<<"\nEnter the number of members of "<<polynomial<<" polynomial: \n";
    cout<<"Enter the Coefficients of the "<<polynomial<<" polynomial: \n";
    for(int i = 0; i < size ; i++){
        cout<<"Enter the coefficients at x^"<<i<<" : ";
        cin>>Array[i];
    }
}

void printArray(int array[], int size) {
    for (int i = size-1; i >= 0 ; i--) {
        if (i == 0) {
            cout << array[i] << " ";
        } else {
            cout << array[i] << "x^" << i << " ";
        }

        if (i > 0) {
            cout << "+ ";
        }
    }
    cout << endl;
}


int AdditionPoly(int A[], int B[], int C[], int x, int y, int z){
    for(int i = 0; i < x; i++){
        A[i]=0;
    }

    for(int i = 0; i < y; i++){
        A[i]+=B[i];
    }

    for(int i = 0; i < z; i++){
        A[i]+=C[i];
    }
}



int main(){
    system("cls");
    int m, n, size;

    cout<<"\nEnter the Coefficient: ";
    cin>>m;
    int Array1[m];
    getArray(Array1, m, "First");

    cout<<"\nEnter the Coeficient: ";
    cin>>n;
    int Array2[n];
    getArray(Array2, n, "Second");
    
    size = max(m,n);
    int result[size];
    AdditionPoly(result,Array1, Array2, size, m, n );
   
    cout<<"\nThe First Polynomial: ";
    printArray(Array1, m);
    cout<<"\nThe second Polynomial: ";
    printArray(Array2, n);
    cout<<"\nThe Resultatnt polynomial after Addition: ";
    printArray(result, size);
    cout<<"\n";
    return 0;

}