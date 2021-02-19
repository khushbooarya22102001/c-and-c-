#include<iostream>
#include<climits>
using namespace std;
int findminver(bool *vis,int *dist,int v)
{
	int mv=-1;
	for(int i=0;i<v;i++)
	{
		if(!vis[i] && mv==-1 || dist[i]<dist[mv])
		{
			mv=i;
		}
	}
	return mv;
}
void dijkstra(int **edge,int src,int v)
{
	bool *vis=new bool[v];
	int *dist=new int[v];
	for(int k=0;k<v;k++)
	{
		dist[k]=INT_MAX;
		vis[k]=false;
	}
	dist[src]=0;
	for(int i=0;i<v;i++)
	{
		int minvertex=findminver(vis,dist,v);
		vis[minvertex]=true;
		for(int j=0;j<v;j++)
		{
			if(edge[minvertex][j]!=0 && !vis[j])
			{
				int cdist=dist[minvertex]+edge[minvertex][j];
				if(cdist<dist[j])
				{
					dist[j]=cdist;
				}
			}
		}
	}
	cout<<"\n result:";
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
	int **edge=new int*[v];
	for(int i=0;i<v;i++)
	{
		edge[i]=new int[v];
	
	}
	int u,w,d;
	cout<<"\n enter edges:";
	for(int i=0;i<e;i++)
	{
		cin>>u>>w>>d;
		edge[u][w]=d;
		edge[w][u]=d;
	}
	dijkstra(edge,0,v);
}
