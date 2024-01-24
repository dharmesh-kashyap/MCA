#include<iostream>
using namespace std;
struct sparse
{
    int rn,cn,val;
};

int main(){
    int tdmat[100][100];   
    cout<<"Enter the no of rows:";
    int rows,cols;
    cin>>rows;
    cout<<"\nEnter The no of cols:";
    cin>>cols;
    tdmat[rows][cols];
    int k=0;
    sparse spmat[100];
    spmat[k];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout<<"Enter ("<<i<<","<<j<<") value: ";
            cin>>tdmat[i][j];
        }
    }cout<<endl;
    spmat[k].rn=rows;
    spmat[k].cn=cols;
    k++;
    cout<<"\nThe given matrix is :"<<endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (tdmat[i][j]!=0)
            {
                spmat[k].rn=i;
                spmat[k].cn=j;
                spmat[k].val=tdmat[i][j];
                k++;
            }
            cout<<tdmat[i][j]<<" ";
        }cout<<endl;
    }
    spmat[0].val=(k-1);
    cout<<"\nThe given matrix in the form of an array of triplets :"<<endl;
    cout<<"rn   cn  val"<<endl;
    for (int i=0;i<k;i++){
            cout<<spmat[i].rn<<"    "<<spmat[i].cn<<"   "<<spmat[i].val<<endl;
    }
    
    int reconmat[100][100];
    reconmat[spmat[0].rn][spmat[0].cn];
    for (int i = 0; i < spmat[0].rn; i++)
    {
        for (int j = 0; j < spmat[0].cn; j++)
        {
            reconmat[i][j]=0;
        }  
    }
    for (int i = 1; i <= spmat[0].val; i++)
    {
        reconmat[spmat[i].rn][spmat[i].cn]=spmat[i].val;
    }

    cout<<"\nThe Reconstrucnted matrix is :"<<endl;
    bool success=true;
     for (int i = 0; i < spmat[0].rn; i++)
    {
        for (int j = 0; j < spmat[0].cn; j++)
        {
            if(reconmat[i][j]!=tdmat[i][j]){
                success=false;
            }
            cout<<reconmat[i][j]<<" ";
        }cout<<endl;
    }
    if (success)
    {
        cout<<endl<<"Conversion is successful!!YaaaY!!"<<endl;
    }
}