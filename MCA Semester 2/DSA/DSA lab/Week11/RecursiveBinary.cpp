#include <iostream>
using namespace std;

// Binary search function with recursion
int binarySearchRecursive(int arr[], int left, int right, int key) {
    if (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if key is present at mid
        if (arr[mid] == key) {
            return mid;
        }

        // If key is greater, search right half recursively
        if (arr[mid] < key) {
            return binarySearchRecursive(arr, mid + 1, right, key);
        }
        // If key is smaller, search left half recursively
        else {
            return binarySearchRecursive(arr, left, mid - 1, key);
        }
    }
    // Key not found, return -1
    return -1;
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements in sorted order:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int key;
    cout << "Enter the element to search for: ";
    cin >> key;

    // Perform binary search recursively
    int index = binarySearchRecursive(arr, 0, n - 1, key);

    if (index != -1) {
        cout << "Element found at index " << index << endl;
    } else {
        cout << "Element not found in the array.\n";
    }

    return 0;
}
