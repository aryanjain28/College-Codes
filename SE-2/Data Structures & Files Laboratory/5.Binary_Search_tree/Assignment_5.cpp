#include<iostream>

using namespace std;

typedef struct node
{
	struct node *left;
	struct node *right;
	int data;
}node;

typedef struct qnode
{
	struct node*x;
	struct qnode *next;
}qnode;

class queue
{
	qnode *front,*rear;
   	public:
	queue()
	{
		front=NULL;
		rear=NULL;
	}

	int isempty()
	{
		if(front==NULL)
			return 1;
		return 0;
	}

	void enque(node *i)
	{
		qnode *p;
		p=new qnode();
		p->x=i;
		p->next=NULL;

		if(front==NULL)
		{
			front=p;
			rear=p;
		}
		else
		{
			rear->next=p;
			rear=rear->next;
		}
	}

	struct node *deque()
	{
		qnode *p;
		node *temp;
		p=front;
		temp=front->x;
		if(front==rear)
		{
			front=NULL;
			rear=NULL;
		}
		else
		{
			front=front->next;
		}
		delete p;
		return temp;
	}
};

class BSTree
{
	int flag;
	struct node *root;
	public:
	BSTree()
	{
		root = NULL;
	}
	struct node *create(int n)
	{
		int x;
		cout << "Enter data : ";
		cin >> x;
		root = insert(root, x);
		
		for(int i=1; i<n; i++)
		{
			cout << "Enter data : ";
			cin >> x;
			insert(root, x);
		}
		return root;
	}
	struct node *newNode(int x)
	{
		struct node *P = new node();
		P->data = x;
		P->left = NULL;
		P->right = NULL;
		return P;
	}
	struct node *insert(struct node *T, int x)
	{
		if(T == NULL)
			return newNode(x);
		if(x < T->data)
			T->left = insert(T->left, x);
		else if(x > T->data)
			T->right = insert(T->right, x);

		return T;
	}
	struct node *find_min(struct node *T)
	{
		while(T->left!=NULL)
		{
			T = T->left;
		}
		return T;
	}
	void display(struct node *T)
	{
		if(T!=NULL)
		{
			display(T->left);
			cout << "Data : " << T->data << endl;
			display(T->right);
		}
	}
	void display_mirror(struct node *T)
	{
		if(T!=NULL)
		{
			display_mirror(T->right);
			cout << "Data : " << T->data << endl;
			display_mirror(T->left);
		}
	}
	struct node *search(struct node *T, int x)
	{
		flag = 0;
		if(T != NULL)
		{
			if(x == T->data)
			{
				flag = 1;	
				return T;				
			}
			else if(x < T->data)
			{
				search(T->left, x);
			}
			else
			{
				search(T->right, x);
			}
		}
		
		if(flag == 0)
			return NULL;
	}
	struct node *del(struct node *T, int x)
	{
		if(search(T, x) == NULL)
		{
			cout << "Element not found!\n\n";
		}
		else
		{
			//finding element
			if(T == NULL)
			{
				return T;
			}
			if(x < T->data)
			{
				T->left = del(T->left, x);
			}
			else if(x > T->data)
			{
				T->right = del(T->right, x);
			}
			//Element found!
			else
			{
				//case1 leaf node + case2 single_child
				if(T->left == NULL)
				{
					struct node *temp = T->right;
					delete(T);
					return temp;
				}
				else if(T->right == NULL)
				{
					struct node *temp = T->left;
					delete(T);
					return temp;
				}

				struct node *min = find_min(T->right);
				T->data = min->data;
				T->right = del(T->right, min->data);
			}
		}
		return T;
	}
	
	void level_wise(struct node *T)
	{
		if(T==NULL)
			return;

		queue q;
		q.enque(T);


		while(q.isempty()!=1)
		{
			
			struct node *temp = q.deque();

			if(temp!=NULL)

			if(temp->left != NULL)
				q.enque(temp->left);

			if(temp->right != NULL)
				q.enque(temp->right);

			cout << temp->data << " ";

		}
	}

};

int main()
{
	struct node *root, *min;
	BSTree t;
	int n, x, choice;

	cout << "Enter number of nodes : ";
	cin >> n;
	root = t.create(n);
	
	do
	{
		cout << "\n\n\t\t*************** TREE OPERATIONS ***************\n\n";
		cout << "\n\nPress 1 to insert an element.\n";
		cout << "Press 2 to delete an element.\n";
		cout << "Press 3 to search an element.\n";
		cout << "Press 4 to create mirror image.\n";
		cout << "Press 5 to display.\n";
		cout << "Press 6 to display level-wise.\n";
		cout << "Press 7 to find minimum.\n";
		cout << "Press 8 to create a new tree.\n";
		cout << "Press 9 to exit.\n";
		cout << "\n\nYour choice : ";
		cin >> choice;

		switch(choice)
		{
			case 1: cout << "Enter element : ";
				cin >> x;
				t.insert(root, x);
				cout << "\n\nElement inserted!";
				break;

			case 2: cout << "Enter element : ";
				cin >> x;
				t.del(root, x);
				cout << "\n\nElement deleted!";
				break;

			case 3: cout << "Enter element : ";
				cin >> x;
				node *P;
				P = t.search(root, x);
				if(P == NULL)
					cout << "\n\nElement not found!\n\n";
				else
					cout << "\n\nElement found!\n\n";
				break;

			case 4: cout << "\n\nMirror image : \n\n";
				t.display_mirror(root);
				break;

			case 5: cout << "\n\n";
				t.display(root);
				break;

			case 6: t.level_wise(root);
				break;

			case 7: struct node* min;
				min = t.find_min(root);
				cout << "\n\nMinimum : " << min->data << endl;
				break;

			case 8: cout << "Enter number of nodes : ";
				cin >> n;
				root = t.create(n);
				break;
			
			case 9: cout << "\n\nThank you!\n\n";
				break;

			default: cout << "\n\nPlease check choice!!\n\n";
		}

	}while(choice!=9);	

}
