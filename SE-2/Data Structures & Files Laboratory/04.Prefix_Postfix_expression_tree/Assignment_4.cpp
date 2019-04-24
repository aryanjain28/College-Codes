/*Construct and expression tree from postfix/prefix expression and perform recursive and non-recursive inorder, pre-order and post-order transversals*/

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 100

using namespace std;

typedef struct tnode
{
	struct tnode *left;
	struct tnode *right;
	char data;
}tnode;

typedef struct node
{
	struct node *next;
	struct tnode *data;
}node;


class stack
{
	node *top, *p;
	public:
	stack()
	{
		top = NULL;
	}
	void push(struct tnode *T)
	{
		p = new node();
		p->data = T;
		p->next = top;
		top = p;
	}
	struct tnode *pop()
	{
		struct tnode *T;
		T = top->data;
		top = top->next;
		return T;
	}
	int empty()
	{
		if(top == NULL)
			return 1;
		return 0;
	}
	struct tnode *Top()
	{
		return (top->data);
	}
};

struct tnode *postfix_tree(char *postfix)
{
	stack s;
	struct tnode *T;
	int i=0;

	while(postfix[i] != '\0')
	{
		char token = postfix[i];

		T = new tnode();
		T->data = token;	
	
		if(isalnum(token))
		{
			T->left = NULL;
			T->right = NULL;
		}
		else
		{
			T->right = s.pop();			
			T->left = s.pop();
		}

		s.push(T);
		i++;
	}
	return s.Top();
}

struct tnode *prefix_tree(char *prefix)
{
	stack s;
	struct tnode *T;
	int i=0;
	
	for(i=0; prefix[i]!='\0'; i++)
	{}
	i = i-1;

	while(i >= 0)
	{
		char token = prefix[i];

		T = new tnode();
		T->data = token;	
	
		if(isalnum(token))
		{
			T->left = NULL;
			T->right = NULL;
		}
		else
		{
			T->left = s.pop();
			T->right = s.pop();						
		}

		s.push(T);
		i--;
	}
	return s.Top();
}


void preorder(struct tnode *T)
{
	if(T!=NULL)
	{
		cout << T->data;
		preorder(T->left);
		preorder(T->right);
	}
}

void inorder(struct tnode *T)
{
	if(T!=NULL)
	{
		inorder(T->left);
		cout << T->data;
		inorder(T->right);
	}
}

void postorder(struct tnode *T)
{
	if(T!=NULL)
	{
		postorder(T->left);
		postorder(T->right);
		cout << T->data;
	}
}

void inorder_non_recursive(struct tnode *T)
{

	stack s;
	while(T!=NULL)
	{
		s.push(T);
		T=T->left;
	}

	while(s.empty()!=1)
	{
		T=s.pop();
		cout<<T->data;
		T=T->right;
		while(T!=NULL)
		{
			s.push(T);
			T=T->left;
		}
	}
}

void preorder_non_recursive(struct tnode *T)
{

	stack s;
	while(T!=NULL)
	{
		cout<<T->data;
		s.push(T);
		T=T->left;
	}

	while(s.empty()!=1)
	{
		T=s.pop();
		T=T->right;

		while(T!=NULL)
		{
			cout<<T->data;
			s.push(T);
			T=T->left;
		}
	}
}

void postorder_non_recursive(struct tnode *T)
{
	stack s,s1;
	tnode *temp;
	while(T!=NULL)
	{
		s.push(T);
		s1.push(NULL);
		T=T->left;			
	}
	while(s.empty()!=1)
	{
		T=s.pop();
		temp=s1.pop();
		if(temp==NULL)
		{
			s.push(T);
			s1.push((tnode *)1);
			T=T->right;		
				while(T!=NULL)
				{
					s.push(T);
					s1.push(NULL);
					T=T->left;			
				}	
			
		}
		else
		cout<<T->data;	
	}
}


int main()
{
	struct tnode *root;
	char postfix[SIZE], prefix[SIZE];
 	int choice1, choice2;

	do
	{
		cout << "\n\nPress 1 for Prefix.\n";
		cout << "Press 2 for Postfix.\n";
		cout << "Press 9 to exit.\n\n";
		cout << "Your choice : ";
		cin >> choice1;
		cout << endl;

		switch(choice1)
		{
			case 1:	cout << "Enter prefix expression : ";
				cin >> prefix;
				root = prefix_tree(prefix);
				goto next;

			case 2: cout << "Enter postfix expression : ";
				cin >> postfix;
				root = postfix_tree(postfix);
				goto next;

			case 9: cout << "\t\t\n\nThank you!\t\t\n\n";
				break;			

			default : cout << "\t\t\n\nPlease check choice!";
				break;

			next:

			do
			{
				cout << "\n\n\t\t************ Prefix & Postfix tree! *************\t\t\n\n";

				cout << "RESURSIVE : \n\n";
				cout << "Press 1 for preoreder transversal.\n";
				cout << "Press 2 for inoreder transversal.\n";
				cout << "Press 3 for postoreder transversal.\n\n";
				cout << "NON-RECURSIVE : \n\n";
				cout << "Press 4 for preoreder transversa.\n";
				cout << "Press 5 for inoreder transversal.\n";
				cout << "Press 6 for postoreder transversal.\n\n";
				cout << "Press 9 to change expression.\n\n";
				cout << "Choice : ";
				cin >>choice2;	
				cout << endl;

				switch(choice2)
				{
					case 1: cout << "Preorder : ";
						preorder(root);
						cout << endl;
						break;

					case 2: cout << "Inorder : ";
						inorder(root);
						cout << endl;
						break;

					case 3: cout << "Postorder : ";
						postorder(root);
						cout << endl;
						break;

					case 4: cout << "Preorder : ";
						preorder_non_recursive(root);
						cout << endl;
						break;

					case 5: cout << "Inorder : ";
						inorder_non_recursive(root);
						cout << endl;
						break;

					case 6: cout << "Postorder : ";
						postorder_non_recursive(root);
						cout << endl;
						break;

					case 9: break;
			
					default: cout << "\t\t\n\nPlease check choice!";
				}
			}while(choice2!=9);	
		}
		
	}while(choice1!=9);
}
