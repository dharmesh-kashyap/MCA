#include<iostream>
using namespace std;

int main(){
    int Array[] = {11,2,8};
    int n = 3;
    int min_index;
    for (int i = 0; i < n-2; i++)
    {
        min_index = i;
        for (int  j = i + 1; j < n -1 ; j++)
        {
            if (Array[j]<Array[min_index])
            {
                min_index = j;
            }
            
        }
        swap(Array[i], Array[min_index]);
    }

    for (int i = 0; i < 3; i++)
    {
        cout<<Array[i]<<" ";
    }
    
    
}