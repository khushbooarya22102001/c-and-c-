#include<iostream>
#include<climits>
using namespace std;
int findminver(int *dist,bool *vis,int n)
{
	int mv=-1;
	for(int i=1;i<=n;i++)
	{
		if(!vis[i] && mv==-1|| dist[i]<dist[mv])
		{
			mv=i;
		}
	}
	return mv;
}
void dijkstra(int **edge,int n,int m,int src)
{
	bool *vis=new bool[n];
	int *dist=new int[n];
	for(int i=1;i<=n;i++)
	{
		dist[i]=INT_MAX;
		vis[i]=false;
	}
	dist[src]=0;
	for(int i=1;i<=n-1;i++)
	{
		int minver=findminver(dist,vis,n);
		vis[i]=true;
		for(int j=1;j<=m;j++)
		{
			if(edge[minver][j]!=0 && !vis[j])
			{
				if(dist[j]>dist[minver]+edge[minver][j])
				{
					dist[j]=dist[minver]+edge[minver][j];
				}
			}
		}
	}
}
int main()
{
	int n,m;
	cout<<"enter no of vertices:";
	cin>>n;
	cout<<"\n enter no of edges:";
	cin>>m;
	int **edge;
	edge=new int*[n];
	for(int i=0;i<n;i++)
	{
		edge[i]=new int[m];
	}
	for(int i=1;i<=m;i++)
	{
		cout<<"\nenter";
		int beg,end,wei;
		cin>>beg>>end>>wei;
		edge[beg][end]=wei;
		edge[end][beg]=wei;
	}
	int src=1;
	dijkstra(edge,n,m,src);
}
