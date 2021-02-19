#include<iostream>
#include<climits>
const int v=5;
using namespace std;
int findmv(int *dist,bool *vis,int v)
{
	int minv=-1;
	for(int j=0;j<v;j++)
	{
		if(!vis[j] && minv==-1 || dist[j]<dist[minv])
		{
			minv=j;
		}
	}
	return minv;
}
void dijkstra(int src,int adj[v][v])
{
	bool *vis=new bool[v];
	int *dist=new int[v];
	for(int k=0;k<v;k++)
	{
		vis[k]=false;
		dist[k]=INT_MAX;
	}
	dist[0]=0;
	for(int i=0;i<v;i++)
	{
		int mv=findmv(dist,vis,v);
		vis[mv]=true;
		for(int j=0;j<v;j++)
		{
			if(adj[mv][j]!=0 && !vis[j])
			{
				int cdist=dist[mv]+adj[mv][j];
				if(cdist<dist[j])
				{
					dist[j]=cdist;
				}
			}
			
		}
	}
	for(int z=0;z<v;z++)
	{
		cout<<z<<" "<<dist[z];
		cout<<"\n";
	}
}
int main()
{
	int v,e;
	cout<<"enter no of vertices:";
	cin>>v;
	cout<<"\n enter no of edges:";
	cin>>e;
	int adj[5][5];
	for(int i=0;i<v;i++)
	{
		for(int j=0;j<v;j++)
		{
			adj[i][j]=0;
		}
	}
	int u,w,d;
	for(int i=0;i<e;i++)
	{
		cin>>u>>w>>d;
		adj[u][w]=d;
		adj[w][u]=d;
	}
	dijkstra(0,adj);
}
