#include<iostream>
#include<algorithm>
using namespace std;
class edge{
	public:
	int src;
	int dest;
	int we;
};

bool compare(edge e1,edge e2)
{
	return e1.we<e2.we;
}
int findpar(int v,int *parent)
{
	if(parent[v]==v)
	{
		return v;
	}
	return findpar(parent[v],parent);
}
void kruskal(edge *input,int n,int e)
{
	sort(input,input+e,compare);
	edge *output;
	output=new edge[n-1];
	int *parent;
	parent=new int[n];
	for(int i=0;i<n;i++)
	{
		parent[i]=i;
	}
	int count=0;
	int i=0;
	while(count!=n-1)
	{
		edge curr=input[i];
		int srcpar=findpar(curr.src,parent);
		int destpar=findpar(curr.dest,parent);
		if(srcpar!=destpar)
		{
			output[count]=curr;
			count++;
			parent[srcpar]=destpar;
		}
		i++;
	}
	cout<<"\n";
	for(int i=0;i<n-1;i++)
	{
		if(output[i].src<output[i].dest)
		{
			cout<<output[i].src<<" "<<output[i].dest<<" "<<output[i].we;
			cout<<"\n";
		}
		else{
			cout<<output[i].dest<<" "<<output[i].src<<" "<<output[i].we;
			cout<<"\n";
		}
	}
	int sum=0;
	for(int i=0;i<n-1;i++)
	{
		sum+=output[i].we;
	}
	cout<<"sum:"<<sum;
}
int main()
{
	int n,e;
	cout<<"\n enter no of vertices:";
	cin>>n;
	cout<<"\n enter no of edges:";
	cin>>e;
	edge *input;
	input=new edge[e];
	cout<<"\nenter edges:";
	for(int i=0;i<e;i++)
	{
		int s,d,w;
		cin>>s>>d>>w;
		input[i].src=s;
		input[i].dest=d;
		input[i].we=w;
	}
	kruskal(input,n,e);
}
