#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
//#include<sys/wait.h>
int main()
{
pid_t pid1,n,pid;
n = fork();
if( n == 0 )
{
printf("hello this is a child process.\n");
pid = getpid();
printf("process id = %d\n",pid);
}
else if( n >=1 )
{
wait(NULL);
printf("hello this is a parent process.\n");
pid = getpid();
printf("process id = %d\n",pid);
}
else
{
printf("Process creation failed\n");
}
return 0;
}
