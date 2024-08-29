// Dharmesh kashyap, Reg no: 230970133

//2. Write a program using pipe to accept integer at parent and pass it to child. Child should check that number is Armstrong number or not and accordingly send a message - YES or NO to parent.

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
int main(){

    int fd[2], fd2[2]; 
    if(pipe(fd) == -1){
        printf("\n An Error occured while opening the pipe 1: ");
        return 1;
    }
    if(pipe(fd2) == -1){
        printf("\n An Error occured while opening the pipe 2 : ");
        return 1;
    }
    if(fork() > 0){
        close(fd[0]);
        close(fd2[1]);
        int num;
        char msg[20];
        printf("\nParent Process: ");
        printf("\nEnter a Number : ");
        scanf("%d",&num);
        if(write(fd[1],&num,sizeof(int)) == -1){
            printf("\n An Error occured while writing : ");
            return 2;
        }
        close(fd[1]);
        if(read(fd2[0],msg,sizeof(msg)) == -1){
            printf("\n An Error occured while reading : ");
            return 2;
        }
        printf("\nMessage: %s",msg);
        close(fd2[0]);

    }
    else{
        close(fd[1]);
        close(fd2[0]);
        printf("\nChild Process: ");
        int res,temp,sum=0,rem;
        char message[10];
        if(read(fd[0],&res,sizeof(int))==-1){
            printf("\n An Error occured while reading : ");
            return 3;
        }
        close(fd[0]);
        printf("\nNumber: %d",res);
        temp = res;
        while(temp > 0){
            rem= temp%10;
            sum=sum+(rem*rem*rem);
            temp=temp/10;
        }
        if(res == sum){
        printf("\nAmstrong number");
        strcpy(message,"Yes\n");
        }
        else{
        printf("\nNot an Amstrong number");
        strcpy(message,"No \n");
        }

        
        if(write(fd2[1],message,sizeof(message)) == -1){
            printf("\n An Error occured while writing \n");
            return 2;
        }
        close(fd2[1]);
    }
    return 0;
}

