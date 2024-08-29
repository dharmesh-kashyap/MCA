//Dharmesh Kahshyap, Regno: 230970133

//6. Write a program using pipe to accept a string and pass it to child. Child will check the string whether it is palindrome or not. If palindrome then return message PALLINDROME otherwise NOT PALLINDROME to Parent.

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
int isPallindrome(char[]);

int main(){
    int fd1[2],fd2[2];
    pipe(fd1);
    pipe(fd2);
    int pid = fork();
    if (pid>0)
    {
      close(fd1[0]);
      close(fd2[1]);
      char str[100];
      printf("\nEnter a string : ");
      scanf("%s",str);
      int len = strlen(str);
      write(fd1[1],&len,sizeof(int));  
      write(fd1[1],str,strlen(str));
      close(fd1[1]);
      char result[100];
      read(fd2[0],&len,sizeof(int));
      read(fd2[0],result,sizeof(char)*len);
      printf("%s",result);
      close(fd2[0]);
    }
    else{
        close(fd1[1]);
        close(fd2[0]);
        int len=0;
        char res_str[100];
        read(fd1[0],&len,sizeof(int));
        read(fd1[0],res_str,sizeof(char)*len);
        close(fd1[0]);
        int flag = 0,i=0;
        for(i=0;i < len/2 ;i++){
        if(res_str[i] != res_str[len-i-1]){
            flag = 1;
            break;
        }
        }
        char pallindrome[100];
        if(flag == 0){
            strcpy(pallindrome,"\nPalindrome\n");
        }
        else{
            strcpy(pallindrome,"\nIt is Not a Plaindrome\n");
        }
        len = strlen(pallindrome);
        write(fd2[1],&len,sizeof(int));
        write(fd2[1],pallindrome,sizeof(char)*len);
        close(fd2[1]);
    }
    
    return 0;
}
