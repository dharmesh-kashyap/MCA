#include<iostream>
using namespace std;
struct array1 {  
    int arr[100];
};

int main() {
    int row, column, size = 0; // Initialize size to 0
    cout << "Enter row: " << endl;
    cin >> row; 
    cout << "Enter column: " << endl;
    cin >> column;

    int M[row][column];

    // Input matrix elements
    cout << "Enter matrix elements:" << endl;
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < column; j++){
            cout<<"Enter the Element on "<<i<<" "<<j<<": ";
            cin >> M[i][j];
        }
    }

    // Display the entered matrix
    cout << "Entered matrix:" << endl;
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < column; j++) {
            cout << M[i][j] << " ";
        }
        cout << endl;
    }

    // Count non-zero elements to determine if it's sparse
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < column; j++) {
            if(M[i][j] != 0)
                size++;
        }
    }

    int threshold = 2.0 / 3 * (row * column);

    array1 a,b,c;
    
    int k=0;

    if (size < threshold) {
        cout << "\nIt is a Sparse matrix" << endl;

        // Create 1D sparse matrix representation
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < column; j++) {
                if(M[i][j] != 0) {
                   a.arr[k] = i;
                   b.arr[k] = j;
                   c.arr[k] = M[i][j];
                   k++;
                }
            }
        }

        cout<<"The given matrix in the form of an array of triplets: \n";
        cout<<row<<"\t"<<column<<"\t"<<size;
         for(int i = 0; i < size; i++){
            cout<<"\n"<<a.arr[i]<<"\t"<<b.arr[i]<<"\t"<<c.arr[i];
         }

        // Display 1D sparse matrix representation
        cout << "\n1D sparse matrix representation:" << endl;
        for(int i = 0; i < size; i++){
            cout << c.arr[i] << " ";
        }

        int newmat[row][column];

        for(int i = 0; i < row; i++) {
            for(int j = 0; j < column; j++){
                newmat[i][j]=0;
            }
        }

        // Reconstruct the matrix
        cout << "\nReconstructed matrix:" << endl;
        for(int i = 0; i < size; i++)
            newmat[a.arr[i]][b.arr[i]] = c.arr[i];

        for(int i = 0; i < row; i++) {
            for(int j = 0; j < column; j++)
                cout << M[i][j] << " ";
            cout << endl;
        }
    } else {
        cout << "Not a sparse matrix" << endl;
    }

    return 0;
}
