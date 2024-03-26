#include <iostream>
using namespace std;

void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void bubbleSort(int arr[], int size);
void selectionSort(int arr[], int size);
void insertionSort(int arr[], int size);

void displayArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int choice, size;

    cout << "Enter the size of the array: ";
    cin >> size;
    int arr[size];

    cout << "Enter " << size << " elements:\n";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    do
    {
        cout << "\nSorting Techniques Menu:\n";
        cout << "1. Quick Sort\n";
        cout << "2. Bubble Sort\n";
        cout << "3. Selection Sort\n";
        cout << "4. Insertion Sort\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            quickSort(arr, 0, size - 1);
            cout << "Sorted array using Quick Sort: ";
            displayArray(arr, size);
            break;
        case 2:
            bubbleSort(arr, size);
            cout << "Sorted array using Bubble Sort: ";
            displayArray(arr, size);
            break;
        case 3:
            selectionSort(arr, size);
            cout << "Sorted array using Selection Sort: ";
            displayArray(arr, size);
            break;
        case 4:
            insertionSort(arr, size);
            cout << "Sorted array using Insertion Sort: ";
            displayArray(arr, size);
            break;
        case 5:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
            break;
        }
    } while (choice != 5);

    return 0;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = partition(arr, low, high);

        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

int partition(int arr[], int low, int high) {
    int key = arr[low];
    int i = low + 1;
    int j = high;

    while (i < high && key >= arr[i]) {
        i++;
    }

    while (key < arr[j]) {
        j--;
    }

    while (i < j) {
         int temp;
         temp = arr[i];
         arr[i] = arr[j];
         arr[j] = temp;
        while (i < high && key >= arr[i]) {
            i++;
        }
        while (key < arr[j]) {
            j--;
        }
    }

    if (i >= j) {
         int temp;
         temp = arr[low];
         arr[low] = arr[j];
         arr[j] = temp;
    }

    return j;
}

void bubbleSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {   
                int temp;
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void selectionSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
         int temp;
            temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
    }
}

void insertionSort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
