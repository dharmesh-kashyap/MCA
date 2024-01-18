#include<iostream>
using namespace std;
int main(){
    system("cls");
    int row, col, size = 0;
    cout<<"Enter the row: ";
    cin>>row;
    cout<<"Enter the column: ";
    cin>>col;
    int mat[row][col];
    cout<<"\n";
    for(int i = 0; i < row ; i++){
        for(int j = 0; j < col ; j++){
            cout<<"Enter the elements at "<<i<<j<<" : ";
            cin>>mat[i][j];
        }
    }
    cout<<"\nThe matrix you've entered is:  \n";
    for(int i = 0; i < row ; i++){
        for(int j = 0; j < col ; j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<"\n";
    }

    for(int i = 0; i < row ; i++){
        for(int j = 0; j < col ; j++){
           if(mat[i][j]!=0){
            size++;
           }
        }   
    }

    int threshold;
    threshold = 2.0/3.0*(row*col);


    if(size > threshold){
        cout<<"\nIt is not a Sparse matrix ";
    }
    else{
         cout<<"\nIt is a Sparse matrix ";
        int spMat[size][3], x = 0; 
    for(int i = 0; i < row ; i++){
        for(int j = 0; j < col ; j++){
           if(mat[i][j]!=0){
            spMat[x][0] = i;
            spMat[x][1] = j;
            spMat[x][2] = mat[i][j];
            x++;
           }
        }   
    }
    cout<<"\nThe 1D representation is: ";
    for(int i = 0 ; i < size ; i++){
        cout<<spMat[i][2]<<" ";
    }

    cout<<"\nThe reconstructed matrix is: \n";
     int newmat[row][col];

      for(int i = 0; i < row ; i++){
        for(int j = 0; j < col ; j++){
           newmat[i][j] = 0;
        }   
    }

    for(int i = 0; i < size ; i ++){
        newmat[spMat[i][0]][spMat[i][1]] = spMat[i][2];
    }

     for(int i = 0; i < row ; i++){
        for(int j = 0; j < col ; j++){
           cout<<newmat[i][j]<<" ";
        }   
        cout<<"\n";
    }

    }

    return 0;
}