#include<iostream>
#define MAX 999

using namespace std;

class Dijkstra
{
	int G[20][20];

	public:
		int v,e, v1,v2, weight;

		void accept()
		{
			cout << "Enter graph details : \n\n";
			cout << "Enter number of vertex : ";
			cin >> v;
			cout << "Entre number of edges : ";
			cin >> e;
		
			for(int i=0; i<v; i++)
			{
				for(int j=0; j<v; j++)
				{
					G[i][j] = 0;
				}
			}

			for(int i=0; i<e; i++)
			{
				cout << endl << endl;
				cout << "Enter vertex 1 : ";
				cin >> v1;
				cout << "Enter vertex 2 : ";
				cin >> v2;

				cout << "Enter weight between v1 & v2 : ";
				cin >> weight;

				G[v1][v2] = weight;
				G[v2][v1] = weight;
			}
		}

		void display()
		{
			cout << "\n\nGraph representation : \n\n";
			for(int i=0; i<v; i++)
			{
				for(int j=0; j<v; j++)
				{
					cout << "\t" <<  G[i][j]; 
				}
				cout << endl;
			}
		}

		void Dijkstra_algo(int start)
		{
			int copy[20][20], from[10], distance[10], visited[10];

			for(int i=0; i<v; i++)
			{
				for(int j=0; j<v; j++)
				{
					if(G[i][j] == 0)
						copy[i][j] = MAX;
					else
						copy[i][j] = G[i][j];
				}
			}

			for(int i=0; i<v; i++)
			{
				visited[i] = 0;
				from[i] = start;
				distance[i] = copy[start][i];
			}
			distance[start] = 0;
			visited[start] = 1;

			int count = v;
			int next;

			while(count>0)
			{
				int min = MAX;
				for(int i=0; i<v; i++)
				{
					if(visited[i]==0 && distance[i] < min)
					{
						min = distance[i];
						next = i;
					}
				}

				visited[next] = 1;	
				
				for(int i=0; i<v; i++)
				{
					if(visited[i] == 0 && distance[i] > (min+copy[next][i]))
					{
						distance[i] = min+copy[next][i];
						from[i] = next;
					}
				}
			
				count--;
			}

			for(int i=0; i<v; i++)
			{
				cout << "Distance of " << i << " from " << start << " : " << distance[i] << endl;
				
			}
			
		}
};

int main()
{
	Dijkstra o;
	int s;

	o.accept();
	o.display();
	cout << "\n\nEnter starting vertex : ";
	cin >> s;
	cout << "\n\n";
	o.Dijkstra_algo(s);
}
