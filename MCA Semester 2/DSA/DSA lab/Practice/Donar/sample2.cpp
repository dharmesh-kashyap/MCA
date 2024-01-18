#include <iostream>
using namespace std;

int max(int m, int n) {
    return (m > n) ? m : n;
}

void printPolyReverse(int poly[], int n) {
    for (int i = n - 1; i >= 0; i--) {
        if (poly[i] != 0) {
            if (i != n - 1)
                cout << " + ";

            cout << poly[i];
            if (i != 0) {
                cout << "x";
                if (i != 1)
                    cout << "^" << i;
            }
        }
    }
}

void getPolynomial(int poly[], int size, const char* polynomialName) {
    cout << "Enter the coefficients of the " << polynomialName << " polynomial:\n";
    for (int i = 0; i < size; i++) {
        cout << "Enter the coefficient for x^" << i << ": ";
        cin >> poly[i];
    }
}

void addPolynomials(int A[], int B[], int m, int n, int result[]) {
    int size = max(m, n);
    for (int i = 0; i < size; i++)
        result[i] = 0;

    for (int i = 0; i < m; i++)
        result[i] += A[i];

    for (int i = 0; i < n; i++)
        result[i] += B[i];
}

int main() {
    int m, n;

    cout << "Enter the degree of the first polynomial: ";
    cin >> m;
    int A[m];
    getPolynomial(A, m, "first");

    cout << "\nEnter the degree of the second polynomial: ";
    cin >> n;
    int B[n];
    getPolynomial(B, n, "second");

    int size = max(m, n);
    int result[size];

    addPolynomials(A, B, m, n, result);

    cout << "\nFirst polynomial is: ";
    printPolyReverse(A, m);
    cout << "\nSecond polynomial is: ";
    printPolyReverse(B, n);
    cout << "\nSum polynomial is: ";
    printPolyReverse(result, size);

    return 0;
}
