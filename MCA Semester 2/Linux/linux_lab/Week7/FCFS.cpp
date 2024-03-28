#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the no. of Process: ";
    cin >> n;
    int p[n];
    int bt[n];
    int at[n];
    int wt[n];
    int tat[n];
    int ct[n];

    int pi = 0;
    p[0] = 0;
    int temp;

    cout << "Enter the  Process number: ";
    for (int i = 0; i < n; i++)
    {
        cout << "The process no: ";
        p[i] = pi++;
        cout << p[i] << endl;
        cout << "Enter the Arrival time: ";
        cin >> at[i];
        cout << "Enter the Burst time: ";
        cin >> bt[i];
        cout << endl;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {

            if (at[i] < at[j])
            {
                int temp = at[j];
                at[j] = at[i];
                at[i] = temp;

                int temp2 = bt[j];
                bt[j] = bt[i];
                bt[i] = temp2;

                int temp3 = p[j];
                p[j] = p[i];
                p[i] = temp3;
            }
        }
    }

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

    for (int i = 0; i < n; i++)
    {
        tat[i] = ct[i] - at[i];
    }

    for (int i = 0; i < n; i++)
    {
        wt[i] = tat[i] - bt[i];
    }
    cout << "Entered details: " << endl;
    cout << "|   PID  \t|\t   Arrival   \t|\t   burst   \t|\t  Completion  \t|\t  TAT  \t|\t  waiting  \t|\n";
    for (int i = 0; i < n; i++)
    {
        cout << "\t" << p[i] << "\t\t";
        cout << "\t" << at[i] << "\t\t";
        cout << "\t" << bt[i] << "\t\t";
        cout << "\t" << ct[i] << "\t\t";
        cout << "\t" << tat[i] << "\t\t";
        cout << "\t" << wt[i] << "\t\t";
        cout << endl;
    }

    float totalwt = 0;
    float totaltat = 0;

    for (int i = 0; i < n; i++)
    {
        totalwt += wt[i];
        totaltat += tat[i];
    }

    cout << "avg waiting time: " << totalwt / n << endl;
    cout << "avg turnaround time: " << totaltat / n << endl;

    return 0;
}
