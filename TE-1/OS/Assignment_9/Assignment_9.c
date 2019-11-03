#include<stdio.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>

int main(){

	int choice, fileStatus, j=0;
	char fileName[100], bufferRead[200], bufferWrite[200], i;
		
	do{
		printf("\n1. Create file.");
		printf("\n2. Read from file.");
		printf("\n3. Write to file.");
		printf("\n9. Exit.");
		printf("\nYour choice : ");
		scanf("%d", &choice);

		switch(choice){

			case 1: printf("\nEnter file name : ");
				scanf("%s", fileName);
				fileStatus = creat(fileName, 0777);
				if(fileStatus == -1)
					printf("\nError in creating file!");
				else
					printf("\nFile creation successful");
				break;
				
			case 2: printf("\nReading from file...");
				fileStatus = open(fileName, O_RDONLY);
				printf("\n\nFile contents are : \n\n");
				read(fileStatus, bufferRead, sizeof(bufferRead));
				printf("\n\n%s\n\n", bufferRead);
				close(fileStatus);
				break;

			case 3: printf("\nWriting to file...");
				fileStatus = open(fileName, O_WRONLY);
				printf("\n\nEnter data to be written (end with #): \n\n");
				while(i!='#'){
					scanf("%c", &i);
					bufferWrite[j++] = i;				
				}
				write(fileStatus, bufferWrite, sizeof(bufferWrite));
				close(fileStatus);
				break;

			case 9: printf("Thank you!\n");
				break;
		
			default : printf("INVALID\n");
		}

	}while(choice != 9);

}
