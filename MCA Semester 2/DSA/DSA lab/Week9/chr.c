#include<stdio.h>
int main()
{
    int n;
    printf("Enter chacracter length:\n");
    scanf("%d" ,&n);
    char arr[100];
    printf("Enter The Elements:\n");
    for(int i=0;i<n;i++)
    {
        scanf(" %c" ,&arr[i]);
    }
    char arr2[n];
    for(int i=0;i<n;i++)
    {
        arr2[i]=arr[i]+19;
        printf("%c" ,arr2[i]);
        
    }

}
