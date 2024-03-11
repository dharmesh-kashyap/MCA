#include <iostream>
// #include <climits>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of Processes: ";
    cin >> n;

    int p[n], bt[n], at[n], wt[n] = {0}, tat[n] = {0}, ct[n] = {0};

    cout << "Enter the Process details:\n";
    for (int i = 0; i < n; i++) {
        cout << "Enter the Arrival time for Process " << i + 1 << ": ";
        cin >> at[i];
        cout << "Enter the Burst time for Process " << i + 1 << ": ";
        cin >> bt[i];
        p[i] = i + 1; 
    }

    int currentTime = 0;
    int remainingTime[n];
    for (int i = 0; i < n; i++) {
        remainingTime[i] = bt[i];
    }
    int completed = 0;
    int minRemainingTime, shortest = 0;
    bool check = false;

    while (completed != n) {
        minRemainingTime = 1000000;
        for (int j = 0; j < n; j++) {
            if ((at[j] <= currentTime) && (remainingTime[j] < minRemainingTime) && (remainingTime[j] > 0)) {
                minRemainingTime = remainingTime[j];
                shortest = j;
                check = true;
            }
        }

        if (!check) {
            currentTime++;
            continue;
        }

        remainingTime[shortest]--;

        if (remainingTime[shortest] == 0) {
            completed++;
            check = false;
            int finishTime = currentTime + 1;
            ct[shortest] = finishTime;
            tat[shortest] = finishTime - at[shortest];
            wt[shortest] = tat[shortest] - bt[shortest];

            if (wt[shortest] < 0) {
                wt[shortest] = 0;
            }
        }
        currentTime++;
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
