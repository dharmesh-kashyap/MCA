#include<iostream>
using namespace std;

int main(){

    int m , n ; 
    cout<<"Enter the Row & Column of the matrix: \n";
    cin>>m>>n;
    int size = 3*m-2;
    int matrix[m][n];
    int ArrayRow[size];
    int ArrayCol[size];

    if(m!=n){
        cout<<"\nPlease Enter the valid square Matrix\n";
    }
    else{

    for(int i = 0; i < m ; i++){
        for(int j = 0; j < n; j++){
            cout<<"Enter the Matrix element on: "<<i<<j<<" : ";
            cin>>matrix[i][j];
        }
    }
 cout<<"\nThe Matrix is: \n";
    for(int i = 0; i < m ; i++){
        for(int j = 0; j < n; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<"\n";
    }

    // For the Row Major in an Array: 
    int k = 0;
    for(int i = 0; i < m ; i++){
        for(int j = 0; j < n; j++){
           if ((i == j) || (i==j+1) || (i==j-1)){
            ArrayRow[k]=matrix[i][j];
            k++;
           }
           
        }
    }

    cout<<"\nThe Array of row major is: \n";
    for(int i = 0; i < size ; i++){
        cout<<ArrayRow[i]<<" ";
    }

    //For the Column Major Matrix: 
    k = 0;
    for(int i = 0; i < m ; i++){
        for(int j = 0; j < n; j++){
           if ((i == j) || (i==j+1) || (i==j-1)){
            ArrayCol[k]=matrix[j][i];
            k++;
           }
              
        }
    }

    cout<<"\nThe Array of column major is: \n";
    for(int i = 0; i < size ; i++){
        cout<<ArrayCol[i]<<" ";
    }

    bool cond = true; 

    do{
        int row, col, choice;
        cout<<"\n\n---------Menu---------\n1. According to row major\n2. According to Column Major\n3. Exit\nEnter the Choice: ";
        cin>>choice;

        switch(choice){
            case 1: 
                cout<<"Enter the Position of the target values: \n";
                cin>>row>>col;
                for(int i = 0; i < size ; i++){
                    if(i==2*row+col){
                        cout<<"The target value is: "<<ArrayRow[i]<<" At the position: "<<i<<endl;
                    }
                   
                }   
                break;

            case 2: 
                cout<<"Enter the Position of the target values: \n";
                cin>>row>>col;
                for(int i = 0; i < size ; i++){
                    if(i==2*col+row){
                        cout<<"The target value is: "<<ArrayCol[i]<<" At the position: "<<i<<endl;
                    }
                    
                }   
                break;

            case 3: 
                cout<<"\nExiting the Loop\n";
                cond = false;
                break;

            default: 
                cout<<"\n Enter the valid Choice";
                break;
        }
    } while(cond == true);

    }
}
