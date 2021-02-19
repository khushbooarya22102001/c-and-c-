#include<iostream>
#include<climits>
using namespace std;
class edge{
	public:
	int src;
	int dest;
	int wt;
};
void bellman(edge *inp,int v,int e,int source)
{
	int *dist=new int[v];
	for(int i=0;i<v;i++)
	{
		dist[i]=INT_MAX;
	}
	dist[0]=0;
	for(int i=0;i<v-1;i++)
	{
	    
		for(int j=0;j<e;j++)
		{
			int u=inp[j].src;
			int k=inp[j].dest;
			int z=inp[j].wt;
			if(dist[u]!=INT_MAX && dist[u]+z<dist[k])
			{
			    cout<<"\ninside:";
				dist[k]=dist[u]+z;
				cout<<"\n distance:"<<dist[k]<<"\t";
				
				cout<<"\n";
			}
			
		}
	}
	for(int j=0;j<e;j++)
	{
		int u=inp[j].src;
		int k=inp[j].dest;
		int z=inp[j].wt;
		if(dist[u]!=INT_MAX && dist[u]+z<dist[k])
		{
			cout<<"\n negative weight cycle";
			return;
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
	cout<<"enter no. of vertices:";
	cin>>v;
	cout<<"enter no of edges:";
	cin>>e;
	edge *inp=new edge[e];
	int s,d,w;
	for(int i=0;i<e;i++)
	{
		cin>>s>>d>>w;
		inp[i].src=s;
		inp[i].dest=d;
		inp[i].wt=w;
	}
	bellman(inp,v,e,0);
}
