#include <iostream>
using namespace std;

// A utility function to return maximum of two integers
int max(int m, int n) { return (m > n) ? m : n; }

// A[] represents coefficients of the first polynomial
// B[] represents coefficients of the second polynomial
// m and n are sizes of A[] and B[] respectively
int* add(int A[], int B[], int m, int n)
{
    int size = max(m, n);
    int* sum = new int[size];

    // Initialize the product polynomial
    for (int i = 0; i < m; i++)
        sum[i] = A[i];

    // Take every term of the first polynomial
    for (int i = 0; i < n; i++)
        sum[i] += B[i];

    return sum;
}

// A utility function to print a polynomial in reverse order
void printPolyReverse(int poly[], int n)
{
    for (int i = n - 1; i >= 0; i--) {
        cout << poly[i];
        if (i != 0) {
            cout << "x^" << i;
            if (i != 1)
                cout << " ";
        }
        if (i != 0 && i != n - 1)
            cout << " + ";
    }
}

// Function to get polynomial coefficients from the user
void getPolynomial(int poly[], int size)
{
    cout << "Enter coefficients of the polynomial: ";
    for (int i = 0; i < size; i++)
    {
        cout << "Enter coefficient for x^" << i << ": ";
        cin >> poly[i];
    }
}

// Driver program to test above functions
int main()
{
    int m, n;

    cout << "Enter the degree of the first polynomial: ";
    cin >> m;
    int A[m];
    getPolynomial(A, m);

    cout << "Enter the degree of the second polynomial: ";
    cin >> n;
    int B[n];
    getPolynomial(B, n);

    cout << "First polynomial is \n";
    printPolyReverse(A, m);
    cout << "\nSecond polynomial is \n";
    printPolyReverse(B, n);

    int* sum = add(A, B, m, n);
    int size = max(m, n);

    cout << "\nSum polynomial is \n";
    printPolyReverse(sum, size);

    delete[] sum; // Don't forget to release the allocated memory

    return 0;
}
