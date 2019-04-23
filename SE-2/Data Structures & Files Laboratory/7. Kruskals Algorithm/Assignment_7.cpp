#include<iostream>
#define MAX 999

using namespace std;

typedef struct Graph
{
	int v1;
	int v2;
	int weight;
}Graph;

class Kruskal
{
	public:
	
	struct Graph G[20];
	
	int nodes, edges;
	void create();
	void Spanning();
	int find_min_pos(int n);
	int find_pos(int v, int parent[]);	
};

void Kruskal :: create()
{
	cout << "Enter number of nodes : ";
	cin >> nodes;
	cout << "Enter number of edges : ";
	cin >> edges;

	for(int i=0; i<edges; i++)
	{
		cout << "\n\n";
		cout << "Enter (V1, V2) : \n";
		cout << "V1 : ";
		cin >> G[i].v1;
		cout << "V2 : ";
		cin >> G[i].v2;
		cout << "Enter weight : ";
		cin >> G[i].weight;
	}
}

int Kruskal :: find_min_pos(int n)
{
	int p=-1, i=0;
	int small = MAX;
	
	while(i<n)
	{
		if(G[i].weight < small)
		{
			small = G[i].weight;
			p = i;
		}
		i++;
	}
	return p;
}

int Kruskal :: find_pos(int v, int parent[])
{
	while(v != parent[v])
		v = parent[v];

	return v;
}

void link(int i, int j, int parent[])
{
	if(i<j)
		parent[j] = i;
	else
		parent[i] = j;
}

void Kruskal :: Spanning()
{
	int parent[20], graph[10][10];
	int k=0, count=0, cost=0;
	
	for(int i=0; i<nodes; i++)
		parent[i] = i;

	while(count != nodes-1)
	{
		int pos = find_min_pos(edges);

		int v1 = G[pos].v1;
		int v2 = G[pos].v2;

		int i = find_pos(v1, parent);
		int j = find_pos(v2, parent);

		if(i!=j)
		{
			graph[k][0] = v1;
			graph[k][1] = v2;
			k++;
			count = count+1;
			cost = cost + G[pos].weight;
			link(i,j,parent);
		}

		G[pos].weight = MAX;
	}

	if(count==nodes-1)
	{	
		cout << "\n\nSPANNING GRAPH IS : \n\n";
		
		int l = k;
		for(int k=0; k<l; k++)
		{
			cout << "\t\t" << graph[k][0] << "\t" << graph[k][1] << endl;
		}

		cout << "\n\nTotal cost of minimum spanning tree : " << cost << endl;
	}
	else
	{
		cout << "\n\nNO SPANNING TREE MADE.\n";
	}
}

int main()
{
	Kruskal k;
	cout << "Enter Graph details : \n\n";
	k.create();
	k.Spanning();
}




