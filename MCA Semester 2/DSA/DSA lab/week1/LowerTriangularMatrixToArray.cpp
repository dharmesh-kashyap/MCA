#include<iostream>
using namespace std;

int main(){

    int m , n ; 
    cout<<"Enter the Row & column of the matrix: \n";
    cin>>m>>n;
    int size = (n*(n+1))/2;
    int matrix[m][n];
    int ArrayRow[size];
    int ArrayCol[size];

    if(m!=n){
        cout<<"\nPlease Enter the Valid Square Matrix\n";
    }
    else{

    for(int i = 0; i < m ; i++){
        for(int j = 0; j < n; j++){
            cout<<"Enter the Matrix elementon: "<<i<<j<<" ";
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
           if (i>=j){
            ArrayRow[k]=matrix[i][j];
            k++;
           }
           else{
            cout<<"0 ";
           }
        }
    }

    cout<<"The Array of row matrix is: \n";
    for(int i = 0; i < size ; i++){
        cout<<ArrayRow[i]<<" ";
    }

    //For the Column Major Matrix: 
    k = 0;
    for(int i = 0; i < m ; i++){
        for(int j = 0; j < n; j++){
           if (i<=j){
            ArrayCol[k]=matrix[j][i];
            k++;
           }
           else{
            cout<<"0 ";
           }
    }

    cout<<"\nThe Array of column matrix is: \n";
    for(int i = 0; i < size ; i++){
        cout<<ArrayCol[i]<<" ";
    }

    bool cond = true; 

    do{
        int row, col, choice;
        cout<<"\n---------Menu---------\n1. According to row major\n2. According to Column Major\n3. Exit\nEnter the Choice: ";
        cin>>choice;

        switch(choice){
            case 1: 
                cout<<"Enter the Position of the tagetted values: \n";
                cin>>row>>col;
                for(int i = 0; i < size ; i++){
                    if(i==(row*(row+1))/2+col){
                        cout<<"The target value is: "<<ArrayRow[i]<<" At the position: "<<i<<endl;
                    }
                    else{
                        cout<<"\nNo value found\n";
                    }
                }   
                break;

            case 2: 
                cout<<"Enter the Position of the tagetted values: \n";
                cin>>row>>col;
                for(int i = 0; i < size ; i++){
                    if(i==(n*row)+col-(row*(row+1)/2)){
                    // if(i==(row*(row+1))/2+col){
                        cout<<"The target value is: "<<ArrayCol[i]<<" At the position: "<<i<<endl;
                    }
                    else{
                        cout<<"\nNo value found\n";
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
}
