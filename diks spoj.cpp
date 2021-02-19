#include<iostream>
#include<climits>
using namespace std;
int find(int *dist,bool *vis,int v)
{
	int minver=-1;
	for(int i=1;i<=v;i++)
	{
		if(!vis[i] && minver==-1 ||dist[i]<dist[minver])
		{
			minver=i;
		}
	}
	return minver;
}
void dijkstra(int **adj,int v,int e,int src,int dest)
{
	int *dist=new int[v];
	bool *vis=new bool[v];
	for(int i=1;i<=v-1;i++)
	{
		int mv=find(dist,vis,v);
		vis[mv]=true;
		for(int j=1;j<=e;j++)
		{
			if(adj[mv][j]!=0 && !vis[j])
			{
				if(dist[j]>dist[mv]+adj[mv][j])
				{
					dist[j]=dist[mv]+adj[mv][j];
				}
			}
		}
	}
	
}
int main()
{
	int t;
	cout<<"enter test case:";
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int v,e;
		cout<<"\n enter vertex and edge:";
		cin>>v>>e;
		int **adj;
		adj=new int*[v+1];
		for(int i=1;i<=v;i++)
		{
			adj[i]=new int[v+1];
		}
		for(int i=1;i<=e;i++)
		{
			cout<<"\n enter:";
			int x,y,wei;
			cin>>x>>y>>wei;
			adj[x][y]=wei;
		}
		int A,B;
		cout<<"\nenter A AND B";
		cin>>A>>B;
		dijkstra(adj,v,e,A,B);
	}
}
