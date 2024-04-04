#include <iostream>
#include <algorithm> // for std::sort
using namespace std;

// Binary search function
int binarySearch(int arr[], int left, int right, int key) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if key is present at mid
        if (arr[mid] == key) {
            return mid;
        }

        // If key is greater, ignore left half
        if (arr[mid] < key) {
            left = mid + 1;
        }
        // If key is smaller, ignore right half
        else {
            right = mid - 1;
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

    // Sort the array before binary search
    sort(arr, arr + n);

    int key;
    cout << "Enter the element to search for: ";
    cin >> key;

    // Perform binary search
    int index = binarySearch(arr, 0, n - 1, key);

    if (index != -1) {
        cout << "Element found at index " << index << endl;
    } else {
        cout << "Element not found in the array.\n";
    }

    return 0;
}
