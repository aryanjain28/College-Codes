#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>

void bubbleSort(int a[], int m);
void selectionSort(int b[], int n);
void printArray(int x[], int size);

int main(){

	int a[10],b[10], m, n;

	pid_t pid;
	pid = fork();

	if (pid == 0){
		printf("Child process : %d.\n", getpid());
		printf("Parent process : %d.\n\n", getppid());	

		printf("CHILD Enter number of elements : ");
		scanf("%d", &m);

		for (int i=0; i<m; i++){
			scanf("%d", &a[i]);	
		}
		bubbleSort(a, m);
	}	

	else if (pid > 0){

		wait(NULL);		//parent process waits until child process executes it instructions.

		printf("Parent process : %d.\n\n", getpid());

		printf("PARENT Enter number of elements : ");
		scanf("%d", &n);

		for (int i=0; i<n; i++){
			scanf("%d", &b[i]);	
		}	
		selectionSort(b, n);
			
	}
	else {
		printf("ERROR!\n\n");	
	}

}

void bubbleSort(int a[], int m){
	int temp;

	for (int i=0; i<m; i++){
		for (int j=0; j<m-1; j++){
			if (a[j] > a[j+1]){
				temp = a[j];	
				a[j] = a[j+1];
				a[j+1] = temp;			
			}		
		}	
	}
	printf("\n\nSorted array is : \n\n");
	printArray(a, m);
	printf("\n\n");
}


void selectionSort(int b[], int n){
	int minIndex;
	int temp;

	for (int i=0; i<n-1; i++){
		minIndex = i;
		for (int j=i+1; j<n; j++){
			if (b[j] < b[minIndex]){
				minIndex = j;
			}
		}
		temp = b[i];
		b[i] = b[minIndex];
		b[minIndex] = temp;
	}
	printf("\n\nSorted array is : \n\n");
	printArray(b, n);
	printf("\n\n");
}

void printArray(int x[], int SIZE){
	for (int k=0; k<SIZE; k++){
		printf("%d ", x[k]);	
	}
}

