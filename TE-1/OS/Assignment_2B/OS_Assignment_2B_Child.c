#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

void binarySearch(int a[], int n, int key);

int main(int argc, char * argv[]){
	int a[10], temp =0, key, i;

	for(i=0; i<argc-1; i++){
		int n = atoi(argv[i]);
		a[i] = n;
	}
	key = atoi(argv[i]);
	binarySearch(a, argc-1, key);

}

void binarySearch(int a[], int n, int key){
	int i=0, j=n-1;
	int midValue = (i+j)/2;

	while(i<=j && a[midValue]!=key){
		if(a[midValue] > key){
			j = midValue-1;
		}
		else{
			i = midValue+1;
		}
		midValue = (i+j)/2;
	}

	if(i<=j)
        	printf("FOUND @ position %d.\n", midValue+1);
    	else   
        	printf("NOT FOUND!\n");
}
