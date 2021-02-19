
#include<iostream>
#include<list>
#include<iterator>
using namespace std;
class Graph{
	int v;
	list<int> *adj;
	public:
		Graph(int z)
		{
			v=z;
			adj=new list<int>[v];
		}
		void add(int u,int w)
		{
			adj[u].push_back(w);
		}
		void dfsutil(int s,bool vis[])
		{
		vis[s]=true;
		cout<<"\t"<<s;
		list<int>::iterator it;
		for(it=adj[s].begin();it!=adj[s].end();it++)
		{
			if(!vis[s])
			{
				dfsutil(*it,vis);
			}
			}	
			
		}
		void dfs()
		{
			bool *vis=new bool[v];
			for(int i=0;i<v;i++)
			{
				vis[i]=false;
			}
			for(int i=0;i<v;i++)
			{
				if(vis[i]==0)
				{
					dfsutil(i,vis);
				}
			}
		}
};
int main()
{
	Graph g(4);
	g.add(0,1);
	g.add(0,2);
	g.add(1,2);
	g.add(2,0);
	g.add(2,3);
	g.add(3,3);
	g.dfs();
	return 0;
}
