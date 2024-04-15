#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of Processes: ";
    cin >> n;

    int p[n]; 
    int bt[n]; 
    int at[n]; 
    int wt[n]; 
    int tat[n]; 
    int ct[n]; 

    cout << "Enter the Process details:\n";
    for (int i = 0; i < n; i++) {
        cout << "Enter the Arrival time for Process " << i + 1 << ": ";
        cin >> at[i];
        cout << "Enter the Burst time for Process " << i + 1 << ": ";
        cin >> bt[i];
        p[i] = i + 1; 
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (at[j] > at[j + 1]) {
                int temp = at[j];
                at[j] = at[j + 1];
                at[j + 1] = temp;
                
                temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;
                
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    int currentTime = 0;     
for (int i = 0; i < n; i++) {
    if (currentTime < at[i]) {
        currentTime = at[i]; 
    }
    currentTime += bt[i]; 
    ct[i] = currentTime; 
}


    for (int i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }

    cout << "PID\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n";
    for (int i = 0; i < n; i++) {
        cout << p[i] << "\t" << at[i] << "\t" << bt[i] << "\t" << ct[i] << "\t\t" << tat[i] << "\t\t" << wt[i] << endl;
    }

    float avgWaitingTime = 0;
    float avgTurnaroundTime = 0;
    for (int i = 0; i < n; i++) {
        avgWaitingTime += wt[i];
        avgTurnaroundTime += tat[i];
    }
    avgWaitingTime /= n;
    avgTurnaroundTime /= n;

    cout << "Average Waiting Time: " << avgWaitingTime << endl;
    cout << "Average Turnaround Time: " << avgTurnaroundTime << endl;

    return 0;
}
