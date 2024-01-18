#include<iostream>
using namespace std;

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
        for(int j = 0; j < column; j++)
            cin >> M[i][j];
    }

    // Display the entered matrix
    cout << "Entered matrix:" << endl;
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < column; j++) 
            cout << M[i][j] << " ";
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

    if (size <= threshold) {
        cout << "Sparse matrix" << endl;
        int sp_mat[size][3], x = 0;

        // Create 1D sparse matrix representation
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < column; j++) {
                if(M[i][j] != 0) {
                    sp_mat[x][0] = i;
                    sp_mat[x][1] = j;
                    sp_mat[x][2] = M[i][j];
                    x++;
                }
            }
        }

        // Display 1D sparse matrix representation
        cout << "1D sparse matrix representation:" << endl;
        for(int i = 0; i < size; i++)
            cout << sp_mat[i][2] << " ";

        // Reconstruct the matrix
        cout << "\nReconstructed matrix:" << endl;
        for(int i = 0; i < size; i++)
            M[sp_mat[i][0]][sp_mat[i][1]] = sp_mat[i][2];

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
