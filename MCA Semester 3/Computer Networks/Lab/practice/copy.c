#include<stdio.h>
#include<unistd.h>
#include<fcntl.h> //used for file handling, file opening and file access 



// int open(const char *pathname, int flags);
// int open(const char *pathname, int flags, mode_t mode);


int main(){
    char buffer;
    int file1 file2;

    file1 = open("File1.txt", O_RDONLY);
    if(file1 == -1){
        printf("Error ");
        close(file1);
    }
    file_2 = open("file2.txt", O_WRONLY|O_CREAT, S_IRUsr|S_IWUSR|S_IRGRP|S_IROTH);
    while(read(File1,&buffer,1)){
        write(file2,&buffer,1);
    }
    print

}