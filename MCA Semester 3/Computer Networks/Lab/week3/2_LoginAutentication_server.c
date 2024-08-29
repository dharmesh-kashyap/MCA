//Dharmesh Kashyap, Reg no: 230970133

//2. Write client-server program using named pipes. Client accepts Username,password from user and passes them to server for authentication. Server haspre-stored username and passwords and it compares username and passwordsand returns message -Welcome <username> or Login Access denied.

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
	char* fifo_pipe = "login_pipe";
	mkfifo(fifo_pipe, 0777);
	char arr1[2][20],arr2[20]="Login Access Denied",users[3][2][20]={{"Dharmesh","Kashyap"},{"MCA","MCA"},{"MIT","MIT"}};
	while(1)
	{
		int flag=0;
		int fd = open(fifo_pipe, O_RDONLY);
		read(fd, arr1, sizeof(arr1));
		close(fd);
		for(int i=0;i<3;i++)
		{
			if(strcmp(arr1[0],users[i][0])==0)
				if(strcmp(arr1[1],users[i][1])==0)
				{
					strcpy(arr2,"Welcome ");
					strcat(arr2, arr1[0]);
					break;
				}
		}
	fd = open(fifo_pipe, O_WRONLY);
	write(fd,arr2,sizeof(arr2));
	close(fd);
	}
	return 0;
}

