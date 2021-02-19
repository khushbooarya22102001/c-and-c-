#include<iostream>
#include<climits>
using namespace std;
class edge{
	public:
	int src;
	int dest;
	int weig;
};
void bellmanford(edge *input,int v,int e,int src)
{
	int *dist=new int[v];
	for(int i=0;i<v;i++)
	{
		dist[i]=INT_MAX;
	}
	dist[src]=0;
	for(int i=0;i<v-1;i++)
	{
		for(int j=0;j<e;i++)
		{
			int source=input[j].src;
			int destination=input[j].dest;
			int weight=input[j].weig;
			if(dist[source]!=INT_MAX && dist[source]+weight<dist[destination])
			{
				dist[destination]=dist[source]+weight;
			}
		}
	}
	for(int k=0;k<e;k++)
	{
		edge curr=input[k];
		int source=curr.src;
		int destination=curr.dest;
		int weight=curr.weig;
		if(dist[source]!=INT_MAX && dist[source]+weight<dist[destination])
		{
			printf("\n negative cycle");
			return;
		}
		
	}
	for(int z=0;z<v;z++)
	{
		cout<<z<<" "<<dist[z];
	}
	
}
int main()
{
	int v,e;
	cout<<"enter no of vertices:";
	cin>>v;
	cout<<"\nenter no of edges:";
	cin>>e;
	edge *input;
	input=new edge[e];
	int s,d,w;
	for(int i=0;i<e;i++)
	{
		cout<<"\n for edge "<<i+1<<"\n";
		cout<<"\n enter source:";
		cin>>input[i].src;
		cout<<"\n enter destination:";
		cin>>input[i].dest;
		cout<<"\n enter weight:";
		cin>>input[i].weig;
	}
	bellmanford(input,v,e,0);
}
