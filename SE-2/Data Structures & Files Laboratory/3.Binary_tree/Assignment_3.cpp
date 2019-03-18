/*Create Binary tree and perform following operations:
a. Insert
b. Display
c. Depth of a tree
d. Display leaf-nodes
e. Create a copy of a tree
*/

#include<iostream>

using namespace std;

typedef struct node
{
	struct node* left;
	struct node* right;
  	char data;
}node;

class Tree
{
	public:

	node *create()
	{
		node *p;
		char x;
		cout << "Enter data : ";
		cin >> x;

		if(x=='0')
		return NULL;

		p = new node();
		p->data = x;

		cout << "\nFor left node of " << x << endl;
		p->left = create();
		cout << "\nFor right node of " << x << endl;
		p->right = create();

		return p;
	}

	void Display(node *T)
	{
		if(T!=NULL)
		{
			Display(T->left);
			cout <<"\t"<<T->data << endl;
			Display(T->right);
		}
	}

	int Depth(node *T)
	{
		int hl,hr;

		if(T==NULL)
			return 0;

		if(T->left == NULL && T->right==NULL)
		{
			return 0;
		}
	
		hl=Depth(T->left);
		hr=Depth(T->right);

		if(hl>hr)
			return 1+hl;
		return 1+hr;
	}

	void leaf_nodes(node *T)
	{
		if(T!=NULL)
		{
			if(T->left == NULL && T->right==NULL)
			{
				cout << T->data << endl;
			}

			leaf_nodes(T->left);
			leaf_nodes(T->right);
		}
	}

	node *copy(node *T)
	{
		node *P;
		P = NULL;

		if(T!=NULL)
		{
			P = new node();
			P->data = T->data;
			P->left = copy(T->left);
			P->right = copy(T->right);
		}

		return P;
	}

};

int main()
{
  int x,choice;
  Tree t;

  node *root, *root_copy;
  root = t.create();

  do
  {
    cout << "\n\nPress 1 to display a tree.\n";
    cout << "Press 2 to find depth of a tree.\n";
    cout << "Press 3 to find leaf nodes of the tree.\n";
    cout << "Press 4 to create a copy of the tree.\n";
    cout << "Press 9 to exit.\n";

    cout << "\n\nYour choice : ";
    cin >> choice;

    switch(choice)
    {
      case 1 : cout << "\nBinary tree is : \n";
                t.Display(root);
                break;

      case 2 :  x = t.Depth(root);
                 cout << "\nDepth of tree is : " << x << endl;
                 break;

      case 3 : cout << "Leaf nodes are : " << endl;
                t.leaf_nodes(root);
                break;

      case 4: root_copy = t.copy(root);
              cout << "Tree copied!" << endl;
              break;

      case 9 : cout << "\n\nThank You!\n\n";
              break;

      default : cout << "\n\nCheck choice!\n\n";
    }

  }while(choice != 9);
}

