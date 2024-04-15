#include <iostream>
#include <cmath>    
#include <vector>
using namespace std;

void FCFS(const vector<int>& arr, int head) {
    int seek_count = 0;
    int distance, cur_track;

    for (int i = 0; i < arr.size(); i++) {
        cur_track = arr[i];

        distance = abs(cur_track - head);
        seek_count += distance;
        head = cur_track;
    }

    cout << "Total number of seek operations = "
         << seek_count << endl;
    cout << "Seek Sequence is" << endl;

    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << endl;
    }
}

int main() {
    int size, head;
    cout << "Enter the size of the request array: ";
    cin >> size;

    vector<int> arr(size);
    cout << "Enter the request array:" << endl;
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << "Enter the initial position of the head: ";
    cin >> head;

    FCFS(arr, head);

    return 0; 
}
