#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>

int A[50][50], B[50][50], C[50][50];
int r1, r2, c1, c2;

void *mul(void *args);
void printMatrix();

int main(){	

	printf("For matrix 1 : \n");
	printf("Enter ROWS and COLS : ");
	scanf("%d %d", &r1, &c1);

	printf("\n\nEnter elements : \n");
	for(int i=0; i<r1; i++){
		for(int j=0; j<c1; j++){
			scanf("%d", &A[i][j]);		
		}	
	}

	printf("\n\nFor matrix 2 : \n");
	printf("Enter ROWS and COLS : ");
	scanf("%d %d", &r2, &c2);

	printf("\n\nEnter elements : \n");
	for(int i=0; i<r2; i++){
		for(int j=0; j<c2; j++){
			scanf("%d", &B[i][j]);		
		}	
	}

	printMatrix();

	if(c2!=r1){
		printf("ERROR :: MULTIPLICAION NOT POSSIBLE!");	
	}
	else{
		pthread_t P[r1];
		
		for(long int i=0; i<r1; i++){
			pthread_create(&P[i], NULL, mul, (void *)i);	
		}

		for(long int i=0; i<r1; i++){
			pthread_join(P[i], NULL);	
		}

		printf("\n\nMATRIX C : \n\n");

		for(int i=0; i<c1; i++){
			for(int j=0; j<r2; j++){
				printf("%d\t", C[i][j]);		
			}
			printf("\n");	
		}
	}
}

void *mul(void *args){
	long row =  (long) args;

	for(int k = row; k<row+1; k++){
		for(int i=0; i<r1; i++){
			for(int j=0; j<c1; j++){
				C[k][i] += A[k][j] * B[j][i];
			}	
		}
	}
}

void printMatrix(){
	printf("MATRIX A : \n\n");

	for(int i=0; i<r1; i++){
		for(int j=0; j<c1; j++){
			printf("%d\t", A[i][j]);		
		}
		printf("\n");	
	}

	printf("MATRIX B : \n\n");

	for(int i=0; i<r2; i++){
		for(int j=0; j<c2; j++){
			printf("%d\t", B[i][j]);		
		}
		printf("\n");	
	}
}
