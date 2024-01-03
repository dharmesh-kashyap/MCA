#include<iostream>
using namespace std;

int main(){
    int m, n, o, p, k = 0;
    cout << "Enter the number of rows and columns: ";
    cin >> m >> n;
    int size = m;
    int arr[m][n];

    if(m == n) {
        cout << "Enter the elements of the matrix: ";
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                cout << "Enter the element at position " << i << ", " << j << ": ";
                cin >> arr[i][j];
            }
        }

        cout << "The matrix is: " << endl;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }

        int array[size];
        int array2[size];

        // Row major order
        cout << "The array (row major order) is: ";
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == j){
                    array[k] = arr[i][j];
                    k++;
                }
            }
        }

        for(int i = 0; i < size; i++){
            cout << array[i] << " ";
        }

        // Reset k for column major order
        int l = 0;

        // Column major order
        cout << "\nThe array (column major order) is: ";
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i == j){
                    array2[l] = arr[i][j];
                    l++;
                }
            }
        }

        for(int i = 0; i < size; i++){
            cout << array2[i] << " ";
        }

        do {
            cout << "\nEnter the Choice \n 1 for Row Major Order \n 2 for Column Major Order\n 3. Exit  \t";
            int choice;
            cin >> choice;

            bool condition1;

            switch(choice){
                case 1:
                    cout << "\nEnter the row and column indices to find the target value: ";
                    cin >> o >> p;
                    k = 0;
                    condition1 = false;
                    for(int i = 0; i < size; i++){
                        condition1 = (o == i && p == i);
                        if(condition1){
                            cout << "\nThe Target value in the array is: " << array[i] << endl;
                            break;
                        }
                    }
                    if (!condition1) {
                        cout << "\nThe target value is not found in the array." << endl;
                    }
                    cout << "The array (row major order) is: ";
                    for(int i = 0; i < size; i++){
                        cout << array[i] << " ";
                    }
                    break;

                case 2:
                    cout << "Enter the row and column indices to find the target value: ";
                    cin >> o >> p;
                    k = 0;
                    condition1 = false;
                    for(int i = 0; i < size; i++){
                        condition1 = (o == i && p == i);
                        if(condition1){
                            cout << "\nThe Target value in the array is: " << array2[i] << endl;
                            break;
                        }
                    }
                    if (!condition1) {
                        cout << "\nThe target value is not found in the array." << endl;
                    }
                    cout << "The array (column major order) is: ";
                    for(int i = 0; i < size; i++){
                        cout << array2[i] << " ";
                    }
                    break;

                case 3:
                    cout << "Exiting the program." << endl;
                    return 0;

                default:
                    cout << "Invalid choice." << endl;
            }
        } while (true);
    }
    else {
        cout << "The matrix is not a square matrix" << endl;
    }

    return 0;
}
