#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include <string.h>
#include <stdlib.h>

void bubbleSort(int a[], int n);
void printArray(int a[], int n);

int main(){
	int i,n, searchNumber;
	int a[30];
	char * args[10];
	
   	printf("\nEnter the number of elements:");
	scanf("%d", &n);

	printf("Enter elements : ");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);	
	}

	printf("Bubble Sort : \n");
	bubbleSort(a, n);
	printArray(a, n);

	printf("Enter number to be searched : ");
	scanf("%d", &searchNumber);

	int j;
	for(j=0; j<n; j++);
	a[j] = searchNumber;
	printArray(a, n+1);

	//IMPORTANT : 

	for(i=0; i<n+1; i++){
		char str[sizeof(int)];				//to store the converted int value;
		sprintf(str ,"%d", a[i]);			//value of a[i] will be converted to string str.
		args[i] = malloc(sizeof(str));			//args which will be sent
		strcpy(args[i], str);				//copied string contents of str to args

	}
	args[i] = NULL;

/*	for(i=0; i<n+1; i++){
		printf("%s\n", args[i]);	
	}
*/

	pid_t pid;
	pid = fork();

	if(pid == 0){		//child process
		printf("This is child process!\n");
		printf("Process ID : %d", getpid());
		char * enviroment[10] = {NULL};
		execve("./os2", args, enviroment);
	}
}

void bubbleSort(int a[], int n){
	int temp;
	for(int i=0; i<n; i++){
		for(int j=0; j<n-1;j++){

			if(a[j] > a[j+1]){
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;		
			}
		}	
	}
}

void printArray(int a[], int n){
	for(int i=0; i<n; i++){
		printf("%d\t", a[i]);
	}
	printf("\n\n");

}


