#include<iostream>
#include<vector>
using namespace std;
void addedge(vector<int> adj[],int u,int w)
{
	adj[u].push_back(w);
	adj[w].push_back(u);
	
}
void print(vector<int> adj[],int v)
{
	vector<int>::iterator it;
	for(int i=0;i<v;i++)
	{
		cout<<i;
		for(it=adj[i].begin();it!=adj[i].end();it++)
		{
			cout<<"->"<<*it;
		}
		cout<<"\n";
	}
}
int main()
{
	int v=4;
	int e=5;
	cout<<"enter no of vertices:";
	cin>>v;
	vector<int> *adj;
	adj=new vector<int>[v];
	cout<<"\n enter no. of edges:";
	cin>>e;
	for(int i=0;i<e;i++);
	{
		int e1,e2;
		cout<<"\n enter edge1 and edge2:";
		cin>>e1>>e2;
		addedge(adj,e1,e2);
	}
    addedge(adj,0,1);
    addedge(adj,1,2);
    addedge(adj,2,3);
    addedge(adj,0,3);
    addedge(adj,1,3);
	print(adj,v);
}
