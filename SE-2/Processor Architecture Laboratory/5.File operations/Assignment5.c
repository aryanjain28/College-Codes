#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<process.h>
#include<dos.h>

void main()
{
	char name[20];
	int choice;
	union REGS i, o;

	clrscr();

	do
	{
		printf("\n\n==MAIN MENU==\n\n");
		printf("1. Create directory.\n");
		printf("2. Delete directory.\n");
		printf("3. Create file.\n");
		printf("4. Delete file.\n");
		printf("9. Exit.\n");
		printf("Your choice : ");
		scanf("%d", &choice);

		switch(choice)
		{
			case 1:	printf("\nEnter name of directory to be created : ");
				scanf("%s", name);
				i.h.ah = 0x39;
				i.x.dx = FP_OFF(name);
				int86(0x21, &i, &o);
				printf("\n\nDirectory created.\n\n");
				break;

			case 2:	printf("\nEnter name of directory to be deleted : ");
				scanf("%s", name);
				i.h.ah = 0x3a;
				i.x.dx = FP_OFF(name);
				int86(0x21, &i, &o);
				printf("\n\nDirectory deleted.\n\n");
				break;

			case 3:	printf("\nEnter name of file to be created : ");
				scanf("%s", name);
				i.h.ah = 0x3c;
				i.x.dx = FP_OFF(name);
				int86(0x21, &i, &o);
				printf("\n\nFile created.\n\n");
				break;

			case 4:	printf("\nEnter name of file to be deleted : ");
				scanf("%s", name);
				i.h.ah = 0x41;
				i.x.dx = FP_OFF(name);
				int86(0x21, &i, &o);
				printf("\n\nFile deleted.\n\n");
				break;

			case 9: printf("Thank you!\n\n");
				break;
		
			default: printf("\n\nINVALID!\n\n");
		}

	}while(choice!=9);
}