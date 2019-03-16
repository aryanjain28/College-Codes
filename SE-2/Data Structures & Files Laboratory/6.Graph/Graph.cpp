/*Consider a friends’ network on face book social web site. Model it as a graph to represent each node as a user and a link to represent the fried relationship between them. Store data such as date of birth, number of comments for each user

1. Find who is having maximum friends
2. Find who has post maximum and minimum comments
3. Find users having birthday in this month.

Hint: (Use adjacency list representation and perform DFS and BFS traversals)*/

#include<iostream>
#define MAX 30

using namespace std;

class DOB
{
	public:
		int Date,Month,Year;

		void BDate(int Year, int Month, int Date)
		{
			this->Date = Date;
			this->Month = Month;
			this->Year = Year;
		}
};

typedef struct node
{
	struct node *next;
	DOB Object;
	int Cmnts;
	int ID;
}node;

node *User[MAX];

int DateOfBirth(string x)
{
	int P;

	cout << "Enter " << x << " : ";
	cin >> P;
	return P;
}

void display(int n)
{
	cout << "\n\n";
	for(int i=0; i<n; i++)
	{
		cout << User[i]->ID << "\t";
		cout << User[i]->Cmnts << "\t";
		cout << (User[i]->Object).Date << "/" << (User[i]->Object).Month << "/" << (User[i]->Object).Year << endl << endl;
	}
}

int search(int FriendID, int n)
{
	for(int i=0; i<n; i++)
	{
		if(User[i]->ID == FriendID)
		{
			return i;
		}
	}
	return -1;
}

void input(int n)
{
	int f, FriendID;
	for(int i=0; i<n; i++)
	{
		User[i] = new node();
	
		cout << "\nEnter ID : ";
		cin >> User[i]->ID;
		cout << "Enter number of comments : ";
		cin >> User[i]->Cmnts;
		cout << "\nEnter birthday : \n";
		(User[i]->Object).BDate(DateOfBirth("Year"), DateOfBirth("Month"), DateOfBirth("Date"));
		User[i]->next = NULL;
	}

	display(n);
}

void BirthDay(int Month, int n)
{
	int flag = 0;
	for(int i=0; i<n; i++)
	{
		if((User[i]->Object).Month == Month)
		{
			flag = 1;
			cout << "User with ID " << User[i]->ID << " has birthday this month!\n";
			
		}
	}
	if(flag == 0)
		cout << "No birthdays this month!" << endl;
}

int main()
{
	int n;
	cout << "How many users : ";
	cin >> n;

	input(n);
//	BirthDay(12, n);
	max
}
