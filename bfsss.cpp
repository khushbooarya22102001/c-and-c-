#include<iostream>
#include<list>
#include<iterator>
using namespace std;
void add(list<int> adj[],int u,int w)
{
	adj[u].push_back(w);
}
void bfs(list<int> adj[],int v,int s)
{
	bool *vis;
	vis=new bool[v];
	for(int i=0;i<v;i++)
	{
		vis[i]=false;
	}
	list<int> queue;
	vis[s]=true;
	queue.push_back(s);
	list<int>::iterator it;
	while(!queue.empty())
	{
		s=queue.front();
		cout<<"\t"<<s;
		queue.pop_front();
		for(it=adj[s].begin();it!=adj[s].end();it++)
		{
		
		if(!vis[*it])
		{
			vis[*it]=true;
			queue.push_back(*it);
			
		}
	}
}
int main()
{
	int v=4;
	list<int> *adj;
	adj=new list<int>[v];
	add(adj,0,1);
	add(adj,0,2);
	add(adj,1,2);
	add(adj,2,0);
	add(adj,2,3);
	add(adj,3,3);
	bfs(adj,4,0);
}
