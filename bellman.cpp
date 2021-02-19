
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
	for(int i=0;i<4;i++)
	{
	    cout<<"\ni:"<<i;
		for(int j=0;j<8;i++)
		{
		    
			edge current=input[j];
			int source=current.src;
			int destination=current.dest;
			int weight=current.weig;
			if(dist[source]!=INT_MAX && dist[source]+weight<dist[destination])
			{
				dist[destination]=dist[source]+weight;
			}
		}
	}
//	for(int k=0;k<e;k++)
//	{
//		edge curr=input[k];
//		int source=curr.src;
//		int destination=curr.dest;
//		int weight=curr.weig;
//		if(dist[source]!=INT_MAX && dist[source]+weight<dist[destination])
//		{
//			printf("\n negative cycle");
//			return;
//		}
//		
//	}
    cout<<"\n distance:";
	for(int z=0;z<v;z++)
	{
		cout<<z<<" "<<dist[z];
	}
	
}
int main()
{
	int v=5;
	int e=8;
	edge *input;
	input=new edge[e];
	input[0].src=0;
	input[0].dest=1;
	input[0].weig=-1;
	
	input[1].src=0;
	input[1].dest=2;
	input[1].weig=4;
	
	input[2].src=1;
	input[2].dest=2;
	input[2].weig=3;
	
	input[3].src=1;
	input[3].dest=3;
	input[3].weig=2;
	
	input[4].src=1;
	input[4].dest=4;
	input[4].weig=2;
	
	input[5].src=3;
	input[5].dest=2;
	input[5].weig=5;
	
	input[6].src=3;
	input[6].dest=1;
	input[6].weig=1;
	
	input[7].src=4;
	input[7].dest=3;
	input[7].weig=-3;

	bellmanford(input,v,e,0);
}
