#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the no. of Processes: ";
    cin >> n;
    int p[n];
    int bt[n];
    int at[n];
    int wt[n];
    int tat[n];
    int ct[n];
    int priority[n];

    int pi = 0;
    p[0] = 0;
    int temp;

    cout << "Enter the Process details: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Process number: ";
        p[i] = pi++;
        cout << p[i] << endl;
        cout << "Enter the Arrival time: ";
        cin >> at[i];
        cout << "Enter the Burst time: ";
        cin >> bt[i];
        cout << "Enter the Priority: ";
        cin >> priority[i];
        cout << endl;
    }

    // Sorting based on Arrival Time using Bubble Sort
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (at[j] > at[j + 1])
            {
                // Swap Arrival Time
                temp = at[j];
                at[j] = at[j + 1];
                at[j + 1] = temp;

                // Swap Burst Time
                temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;

                // Swap Priority
                temp = priority[j];
                priority[j] = priority[j + 1];
                priority[j + 1] = temp;

                // Swap Process Number
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    // Calculate Completion Time
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            ct[i] = bt[i] + at[i];
        }
        else
        {
            temp = 0;
            if (ct[i - 1] < at[i])
            {
                temp = at[i] - ct[i - 1];
            }
            ct[i] = bt[i] + ct[i - 1] + temp;
        }
    }

    // Calculate Turnaround Time
    for (int i = 0; i < n; i++)
    {
        tat[i] = ct[i] - at[i];
    }

    // Calculate Waiting Time
    for (int i = 0; i < n; i++)
    {
        wt[i] = tat[i] - bt[i];
    }

    // Display Process details
    cout << "PID\tArrival\tBurst\tPriority\tCompletion\tTurnaround\tWaiting\n";
    for (int i = 0; i < n; i++)
    {
        cout << p[i] << "\t" << at[i] << "\t" << bt[i] << "\t" << priority[i] << "\t\t" << ct[i] << "\t\t" << tat[i] << "\t\t" << wt[i] << endl;
    }

    // Calculate average Waiting Time and Turnaround Time
    float totalwt = 0;
    float totaltat = 0;

    for (int i = 0; i < n; i++)
    {
        totalwt += wt[i];
        totaltat += tat[i];
    }

    cout << "Average Waiting Time: " << totalwt / n << endl;
    cout << "Average Turnaround Time: " << totaltat / n << endl;

    return 0;
}
