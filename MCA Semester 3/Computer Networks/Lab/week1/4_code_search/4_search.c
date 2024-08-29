// Dharmesh kashyap, reg no: 230970133

//4. Write a program to accept an array before forking and search the array in child for an element accepted and display the result.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<sys/wait.h>

int main() 
{
	int n;
	printf("Enter the number of elements: ");
	scanf("%d", &n);
	int arr[n];
	printf("Enter %d elements: ", n);
	for (int i = 0; i < n; i++) 
	{
		scanf("%d", &arr[i]);
	}
	int searchElement;
	printf("Enter an element to search: ");
	scanf("%d", &searchElement);
	pid_t pid = fork();
	if (pid < 0) 
	{
		perror("Fork failed");
		return 1;
	}
	else if (pid == 0) 
	{
		int found = 0;
		for (int i = 0; i < n; i++) 
		{
			if (arr[i] == searchElement) 
			{
				printf("Child: Element found in the array at index : %d\n", i);
				found = 1; 
				break;
			}
		}
		if (!found) 
		{
			printf("Child: Element not found in the array.\n");
		} 
		
	} 
	else 
	{
		wait(NULL);
		printf("Parent: Child process completed.\n");
	}
	return 0;
}
