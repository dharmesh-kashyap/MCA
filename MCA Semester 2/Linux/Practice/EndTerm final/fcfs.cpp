#include<iostream>
using namespace std;
int main(){
    cout<<"Enter the number of process: ";
    int n;
    cin>>n;

    int pid[n];
    int at[n];
    int bt[n];
    int ct[n];
    int tat[n];
    int wt[n];

    for (int i = 0; i < n; i++)
    {
        pid[i] = i;
        cout<<"Enter the Arrival Time and Burst Time of proccess : " << i << " :\n";
        cout<<"Arrival time: ";
        cin>>at[i];
        cout<<"Burst Time: ";
        cin>>bt[i];
    }

    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; i < n - i - 1 ; i++)
        {
            if (at[j] > at[j+1])
            {
                swap(at[j], at[j+1]);
                swap(bt[j], bt[j+1]);
                swap(pid[j], pid[j+1]);
            }
            
        }
        
    }

    for (int i = 0; i < n; i++)
    {
        if (i == 0 )
        {
            ct[i] = at[i] + bt[i];
        } else{
            int temp = 0; 
            if (ct[i-1] < at[i])
            {
                temp =  at[i] - ct[i-1];
            }
            
            ct[i] = ct[i-1] + bt[i] + temp;
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
    
    int totalTAT = 0;
    int totalWT = 0;

    for (int i = 0; i < n; i++)
    {
        totalTAT += tat[i];
        totalWT += wt[i];
    }


    cout<<"PID\tAt\tBT\tCT\tTAT\tWT\n";
    for (int i = 0; i < n; i++)
    {
        cout<<pid[i]<<"\t"<<at[i]<<"\t"<<bt[i]<<"\t"<<ct[i]<<"\t"<<tat[i]<<"\t"<<wt[i]<<endl;

    }

    cout<<"The average turn around time : "<<totalTAT/n<<endl;
    cout<<"The average waiting time: "<<totalWT/n<<endl;

    return 0;
}