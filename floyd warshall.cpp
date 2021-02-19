#include<iostream>
#include<climits>
const int V=4;
using namespace std;

void floydwarshall(int graph[][V])
{
	int dist[V][V];
	for(int i=0;i<V;i++)
	{
		for(int j=0;j<V;j++)
		{
			dist[i][j]=graph[i][j];
		}
	}
	for(int k=0;k<V;k++)
	{
		for(int i=0;i<V;i++)
		{
			for(int j=0;j<V;j++)
			{
				if(dist[i][k]+dist[k][j]<dist[i][j])
				{
					dist[i][j]=dist[i][k]+dist[k][j];
				}
			}
		}
	}

	for(int i=0;i<V;i++)
	{
		for(int j=0;j<V;j++)
		{
			if(dist[i][j]==INT_MAX)
			{
				cout<<"INT_MAX   ";
			}
			else{
				cout<<dist[i][j]<<" ";
			}
		}
		cout<<"\n";
	}
}
int main()
{
	int V=4;
	int graph[4][4]={{0 ,3, INT_MAX, 5},
	{2, 0, INT_MAX, 8},
	{INT_MAX, 1, 0,INT_MAX},
	{INT_MAX, INT_MAX, 2, 0}};
	floydwarshall(graph);
}
