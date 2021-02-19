#include<iostream>
#include<algorithm>
using namespace std;
class edge{
	public:
	int src;
	int dest;
	int weight;
	
};
bool compare(edge e1,edge e2)
{
	return e1.weight<e2.weight;
}
int findpar(int x,int *parent)
{
	if(parent[x]==x)
	{
		return x;
	}
	return findpar(parent[x],parent);
}
void kruskal(edge *inp,int v,int e)
{
	edge *out=new edge[v-1];
	int *parent=new int[v];
	sort(inp,inp+e,compare);
	for(int i=0;i<v;i++)
	{
		parent[i]=i;
	}
	int count=0;
	int i=0;
	while(count!=v-1)
	{
		edge curr=inp[i];
		int srcpar=findpar(curr.src,parent);
		int destpar=findpar(curr.dest,parent);
		if(srcpar!=destpar)
		{
			out[count]=curr;
			count++;
			parent[srcpar]=destpar;
		}
		i++;
	}
	int sum=0;
	for(int i=0;i<v-1;i++)
	{
		sum+=out[i].weight;
	}
	cout<<"sum:"<<sum;
	
	
}

int main()
{
	int v,e;

	cout<<"enter no of vertices:";
	cin>>v;
	cout<<"\n enter no of edges:";
	cin>>e;
	edge *inp;
	inp=new edge[e];
	for(int i=0;i<e;i++)
	{
		cin>>inp[i].src>>inp[i].dest>>inp[i].weight;
	}
	kruskal(inp,v,e);
	
}
