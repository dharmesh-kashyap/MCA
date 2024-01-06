#include<iostream>
using namespace std;

int main(){

    int m , n ; 
    cout<<"Enter the Row & Column of the Matrix: \n";
    cin>>m>>n;
    int size = m*n;  
    int matrix[m][n];
    int ArrayRow[size];
    int ArrayCol[size];

    for(int i = 0; i < m ; i++){
        for(int j = 0; j < n; j++){
            cout<<"Enter the Matrix elements on: "<<i<<" "<<j<<" : ";
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
    cout<<"\n";



    // For the Row Major in an Array: 
    int k = 0;
    for(int i = 0; i < m ; i++){
        for(int j = 0; j < n; j++){

            ArrayRow[k]=matrix[i][j];
            k++;
           
        }
    }

    cout<<"The Array of row major is: \n";
    for(int i = 0; i < size ; i++){
        cout<<ArrayRow[i]<<" ";
    }

    //For the Column Major Matrix: 
    
     k = 0;  
    for(int i = 0; i < n ; i++){
        for(int j = 0; j < m; j++){
            ArrayCol[k] = matrix[j][i];
            k++;
           
        }
    }

    cout<<"\n\nThe Array of column major is: \n";
    for(int i = 0; i < size ; i++){
        cout<<ArrayCol[i]<<" ";
    }
   

    bool cond = true; 

    do{
        int row, col, choice;
        cout<<"\n\n---------Menu---------\n1. According to row major\n2. According to column Major\n3. Exit\nEnter the Choice: ";
        cin>>choice;

        switch(choice){
            case 1: 
                cout<<"Enter the Position of the target value: \n";
                cin>>row>>col;
                for(int i = 0; i < size ; i++){
                    if(i == n * row + col){
                        cout<<"The target value is: "<<ArrayRow[i]<<" At the position: "<<i<<endl;
                    }
                }   
                break;

            case 2: 
                cout<<"Enter the Position of the target value: \n";
                cin>>row>>col;
                for(int i = 0; i < size ; i++){
                    if(i== m * col + row){
                        cout<<"The target value is: "<<ArrayCol[i]<<" At the position: "<<i<<endl;
                    }
                }   
                break;

            case 3: 
                cout<<"\nExiting the Loop\n";
                cond = false;
                break;

            default: 
                cout<<"\n Enter the Valid Choice";
                break;
        }
    } while(cond == true);

}
