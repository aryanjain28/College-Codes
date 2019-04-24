/*Implement stack as an abstract data type using linked list and use this ADT for conversion of infix expression to postfix, prefix and evaluation of postfix and prefix expression.
*/

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 100

using namespace std;

typedef struct node
{
	char data;
	node *next;
}node;

class stack
{
	node *top, *p;
	public:
	stack()
	{
		top = NULL;
	}
	void push(char x)
	{
		p = new node();
		p->data = x;
		p->next = top;
		top = p;
	}
	char pop()
	{
		char x;
		x = top->data;
		top = top->next;
		return x;
	}
	int empty()
	{
		if(top == NULL)
			return 1;
		return 0;
	}
	char Top()
	{
		return (top->data);
	}
};

int evaluation_postfix(char *postfix);
int evaluation_prefix(char *prefix);
void infix_to_postfix(char *infix, char *postfix);
void infix_to_prefix(char *infix, char *prefix);
void reverse(char *exp1, char *exp2);
int priority(char x);
int evaluation(char x, int o1, int o2);


int main()
{
	char infix[SIZE], postfix[SIZE], reversed[SIZE], prefix[SIZE];
	int e;

	int choice;
	cout << "\n\nPlease enter your choice : \n\n";
	cout << "Press 1 to evaluate a postfix expresion.\n";
	cout << "Press 2 to evaluate a prefix expresion.\n";
	cout << "Press 3 to convert an infix expresion to a postfix expression.\n";
	cout << "Press 4 to convert an infix expresion to a prefix expression.\n";
	cout << "Press 9 to exit.\n\n";

	while(choice!=9)
	{		
		cout << "\n\nYour choice : ";
		cin >> choice;
		switch(choice)
		{
			case 1: cout << "\nEnter postfix expression : ";
				cin >> postfix;
				e = evaluation_postfix(postfix);
				cout << "Answer is : " << e << endl;
				break;

			case 2: cout << "\nEnter prefix expression : ";
				cin >> prefix;
				e = evaluation_prefix(prefix);
				cout << "Answer is : " << e << endl;
				break;

			case 3: cout << "\nEnter infix expression : ";
				cin >> infix;
				infix_to_postfix(infix, postfix);
				cout << "Postfix expression is : " << postfix << endl;
				break;

			case 4 : cout << "\nEnter infix expression : ";
				cin >> infix;
				infix_to_prefix(infix, prefix);
				cout << "Prefix expression is : " << prefix << endl;
				break;

			case 9 : cout << "\n\nThank You! \n\n";
				break;

			default : cout << "\n\nPlease check your choice !!\n\n";
		}
	}
}

int evaluation_postfix(char *postfix)
{
	stack s;
	char x;
	int i,e;
	int op1, op2;
	i=0;
	while((x=postfix[i])!='\0')
	{
		if(isdigit(x))
		{
			s.push(x-48);
		}
		else
		{
			op2 = s.pop();
			op1 = s.pop();
			
			e = evaluation(x, op1, op2);
			s.push(e);
		}
		i++;
	}
	return (s.pop());
}


int evaluation_prefix(char *prefix)
{
	stack s;
	int op2,op1;
	char x;
	int i, e;
	int len;
	
	len = strlen(prefix);

	for(i=(len-1); i>=0; i--)
	{
		x = prefix[i];
		if(isdigit(x))
		{
			s.push(x-48);
		}
		else
		{
			op1 = s.pop();
			op2 = s.pop();
			
			e = evaluation(x, op1, op2);
			s.push(e);
		}
	}
	return (s.pop());
	
}

int evaluation(char x, int o1, int o2)
{
	if(x=='+')
	return (o1+o2);

	else if(x=='-')
	return (o1-o2);

	else if(x=='*')
	return (o1*o2);

	else if(x=='/')
	return (o1/o2);

	else if(x=='%')
	return (o1%o2);
}

void infix_to_postfix(char *infix, char *postfix)
{
	stack s;
	int i,j;
	i=0;
	j=0;
	char token, x;
	while(infix[i]!='\0')
	{
		token = infix[i];
		if(isalnum(token))
		{
			postfix[j++] = token;
		}
		else
		{
			if(token == ')')
			{
				while((x=s.pop())!='(')
				{
					postfix[j++] = x;
				}
			}
			else if(token == '(')
			{
				s.push('(');
			}
			else
			{
				while(s.empty()!=1 && (priority(s.Top()) > priority(token)))
				{
					postfix[j++] = s.pop();
				}
				s.push(token);
			}
		}
		i++;
	}
	while(!s.empty())
	{
		postfix[j++] = s.pop();
	}
	postfix[j] = '\0';
}

int priority(char x)
{
	if(x == '(')
	return 0;

	if(x=='+' || x=='-')
	return 1;

	if(x=='*' || x=='/' || x=='%')
	return 2;
	
	return 3;
}

void infix_to_prefix(char *infix, char *prefix)
{
	char reversed[SIZE];
	char postfix[SIZE];

	reverse(infix, reversed);
	infix_to_postfix(reversed, postfix);
	reverse(postfix, prefix);
}

void reverse(char *exp1, char *exp2)
{
	int i,j,x;
	x = strlen(exp1);

	for(i=x-1,j=0; i>=0,j<x; i--,j++)
	{
		if(exp1[i] == '(')
		{
			exp2[j] = ')';	
		}
		else if(exp1[i] == ')')
		{
			exp2[j] = '(';	
		}
		else
		{
			exp2[j] = exp1[i];
		}
	}
	exp2[j] = '\0';
}
