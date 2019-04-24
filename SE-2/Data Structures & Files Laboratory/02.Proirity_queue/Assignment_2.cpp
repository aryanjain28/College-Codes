/*Implement priority queue as ADT using single linked list for servicing patients in an hospital with priorities as i) Serious (top priority) ii) medium illness (medium priority) iii) General (Least priority).
*/

#include<iostream>
#include<string.h>

#define MAX 100

using namespace std;

typedef struct patient
{
	char name[MAX];
	int id;
	struct patient *next;
}patient;

class pqueue
{
	patient *front, *rear;
	public:
		pqueue();
		int empty();
		void penqueue(char *name, int x);
		void pdequeue();
		void print();
};

pqueue :: pqueue()
{
	front = NULL;
	rear = NULL;
}

int pqueue :: empty()
{
	if(front == NULL && rear == NULL)
		return 1;
	return 0;
}

void pqueue :: penqueue(char *name, int x)
{	
	patient *p;
	p = new patient();
	p->id = x;
	strcpy(p->name, name);
	p->next = NULL;	
	
	if(empty()==1) //first element
	{
		front = p;
	}
	else
	{
		rear->next = p;
	}
	rear = p;
}

void pqueue :: pdequeue()
{
	patient *p;
	p = front;
	
	cout << "\n\nPatient name : " << p->name << endl;
	cout << "Patient id : " << p->id << endl;	

	if(front == rear)
	{
		front = NULL;
		rear = NULL;
	}
	else
	{
		front = front->next;
	}

	delete p;
}

void pqueue :: print()
{
	patient *q;
	q = front;
	if(q == NULL)
	{
		cout << "No more patients left in this category.\n\n";
	}
	else
	{
		patient *p;
		cout << "\n\n";
		for(p = front; p!=NULL; p=p->next)
		{
			cout << "Patient name : " << p->name << endl;
			cout << "Patient ID : " << p->id << endl << endl;
		}
	}
}

class pq
{
	public:
		pqueue q[3];
		void arrival();
		void service();
		void print();
};

void pq :: arrival()
{
	char name[MAX];
	int id;
	
	cout << "\n\nName : ";
	cin >> name;
	cout << "ID : ";
	cin >> id;

	cout << "\n\nPress 1 for damn serious.\n";
	cout << "Press 2 for serious.\n";
	cout << "Press 3 for normal.\n";
	cout << "Press 9 to exit.\n\n";
	cout << "Choice : ";
	int choice;
	cin >> choice;
	switch(choice)
	{
		case 1: q[0].penqueue(name, id);
			break;

		case 2: q[1].penqueue(name, id);
			break;

		case 3: q[2].penqueue(name, id);
			break;

		default: cout << "Please check your choice.\n\n";
	}
}

void pq :: service()
{
	int i=0;
	
	while(i<3 && q[i].empty())
	{
		i++;
	}
	if(i==3)
	{
		cout << "No more patients.\n\n";
	}
	else
	{
		q[i].pdequeue();
	}
}

void pq :: print()
{
	cout << "Damn serious patients : \n\n";
	q[0].print();

	cout << "\n\nSerious patients : \n\n";
	q[1].print();

	cout << "\n\nNormal patients : \n\n";
	q[2].print();
}

int main()
{
	pqueue op;
	pq o;

	int choice;

	do
	{
		cout << "\n\n###############################################\n\n";
		cout << "Press 1 for arrival.\n";
		cout << "Press 2 for service.\n";
		cout << "Press 3 for print.\n";
		cout << "Press 9 to exit.\n\n";
		cout << "Choice : ";
		cin >> choice;

		switch(choice)
		{
			case 1:	o.arrival();
				break;
		
			case 2: o.service();
				break;
	
			case 3: cout << "\n\n";
				o.print();
				break;

			case 9 : cout << "\n\nThank You!!\n\n";
				break;

			default : cout << "\n\nPlease check your choice.\n\n";
		}
	}while(choice != 9);
}
