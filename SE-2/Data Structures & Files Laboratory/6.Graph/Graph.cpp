/*Consider a friends’ network on face book social web site. Model it as a graph to represent each node as a user and a link to represent the fried relationship between them. Store data such as date of birth, number of comments for each user

1. Find who is having maximum friends
2. Find who has post maximum and minimum comments
3. Find users having birthday in this month.

Hint: (Use adjacency list representation and perform DFS and BFS traversals)*/

#include<iostream>

#define MAX 30

using namespace std;

typedef struct DOB
{
	int date;
	int month;
	int year;
}DOB;

typedef struct node
{
	int id;
	int cmnts;
	struct DOB O;
	struct node *next;
}node;

void create(struct node *G[MAX]);
void insert(struct node *G[MAX], int f, int s);
void Display(struct node *G[MAX]);
void max_min_friends(struct node *G[MAX], int n);
void max_min_cmnts(struct node *G[MAX], int n);
void birthday(struct node *G[MAX], int n);

void create(struct node *G[MAX], int n, int e)
{
	for(int i=1; i<=n; i++)
	{
		struct node *p;
		p = new node();
	
		cout << endl << endl;
		cout << "Enter sequence number : ";
		cin >> p->id;
		cout << "Enter number of comments : ";
		cin >> p->cmnts;
		cout << "Enter date of birth : \n\n";
		cout << "Date : ";
		cin >> (p->O).date;
		cout << "Month : ";
		cin >> (p->O).month;
		cout << "Year : ";
		cin >> (p->O).year;
		G[i] = p;
		G[i]->next = NULL;
	}

	int f, s;
	
	for(int i=1; i<=e; i++)
	{
		cout << "\n\n\t\tFRIEND1------>FRIEND2\n\n";
		
		cout << "Enter sequence number of friend 1 :";
		cin >> f;
		cout << "Enter sequence number of friend 2 :";
		cin >> s;

		insert(G, f, s);
	}
}

void insert(struct node *G[MAX], int f, int s)
{
	struct node *p;
	p = new node();

	p->cmnts = G[s]->cmnts;
	(p->O).date = (G[s]->O).date;
	(p->O).month = (G[s]->O).date;
	(p->O).year = (G[s]->O).year;
	p->id = s;
	p->next = NULL;

	if(G[f]->next == NULL)
	{
		G[f]->next = p;
	}
	else
	{
		struct node *temp;
		temp = G[f]->next;
		
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = p;
	}
}

void Display(struct node *G[MAX], int n)
{
	cout << "\n\nUSER\t\t DOB\t\t COMMNETS\t  FRINEDS\n\n";
	
	for(int i=1; i<=n; i++)
	{
		cout << i << "\t\t";
		cout << (G[i]->O).date << "/" << (G[i]->O).month << "/" << (G[i]->O).year << "\t\t";
		cout << G[i]->cmnts << "\t\t";

		int j=0;
		struct node *temp;
		temp = G[i];
		while(temp->next != NULL)
		{
			temp = temp->next;
			j = j+1;
		}
		cout << j << "\n";
	}
}

void max_min_friends(struct node *G[MAX], int n)
{
	int f1=0, f2=0, f3=0, ID_MAX, ID_MIN;

	for(int i=1; i<=n; i++)
	{
		f1 = 0;

		struct node *temp;
		temp = G[i];

		while(temp->next != NULL)
		{
			temp = temp->next;
			f1=f1+1;
		}
		
		if(f1>f2)
		{
			f2 = f1;
			ID_MAX = i;
		}
		if(f1<=f3)
		{
			f3 = f1;
			ID_MIN = i;
		}
	}

	cout << "\n\n";
	cout << "USER #" << ID_MAX << " has max friends : " << f2 << " \n";
	cout << "USER #" << ID_MIN << " has min friends : " << f3 << "\n\n";
}

void max_min_cmnts(struct node *G[MAX], int n)
{
	int f1=0, f2=0, f3=0, f4=0, ID_MAX=1, ID_MIN=1;

	f1 = G[1]->cmnts;
	f2 = G[1]->cmnts;

	for(int i=2; i<=n; i++)
	{
		f3 = G[i]->cmnts;
		f4 = G[i]->cmnts;
		
		if(f3>f1)
		{
			f1 = f3;
			ID_MAX = i;
		}
		if(f4<f2)
		{
			f2 = f4;
			ID_MIN = i;
		}
	}

	cout << "\n\n";
	cout << "USER #" << ID_MAX << " has max comments : " << f1 << "\n";
	cout << "USER #" << ID_MIN << " has min comments : " << f2 << "\n\n";
}

void birthday(struct node *G[MAX], int n)
{
	int m, flag=0;

	up:
	cout << "\nEnter current month : ";
	cin >> m;

	if(m<=0 || m>12)
	{
		cout << "Please enter correct detalis.\n\n";
		goto up;
	}

	cout << "\n\n";
	for(int i=1; i<=n; i++)
	{
		int x = (G[i]->O).month;

		if(x == m)
		{
			flag = 1;
			cout << "User #" << i << " has birthday this month.\n";
		}
	}

	if(flag == 0)
		cout << "\n\nNO BIRTHDAY THIS MONTH.\n\n";

}

int main()
{
	struct node *G[MAX];
	
	int n, e;
	
	cout << "Enter number of users : ";
	cin >> n;
	cout << "Enter number of edges : ";
	cin >> e;
	create(G, n, e);

	int choice;
	
	do
	{
		cout << "\n\n";
		cout << "Press 1 to enter new details.\n";
		cout << "Press 2 to display details.\n";
		cout << "Press 3 to find user with max & min friends.\n";
		cout << "Press 4 to find user with max & min comments.\n";
		cout << "Press 5 to find user having birthday this month.\n";
		cout << "Press 9 to exit.\n";
		cout << "Your choice : ";
		cin >> choice;

		switch(choice)
		{
			case 1:	cout << "Enter number of users : ";
				cin >> n;
				cout << "Enter number of edges : ";
				cin >> e;
				create(G, n, e);
				break;
	
			case 2: Display(G, n);
				break;

			case 3: max_min_friends(G, n);
				break;

			case 4: max_min_cmnts(G, n);
				break;

			case 5:	birthday(G, n);
				break;

			case 9: cout << "\n\n\t\tTHANK YOU!\n\n";
				break;
	
			default: cout << "\n\n\t\tINVALID!\n\n";
				break;
		}

	}while(choice!=9);
}
