#include<iostream>
#include<list>
#include<iterator>
using namespace std;
class graph{
	int v;
	list<int> *adj;
	public:
	graph(int x)
	{
		v=x;
		adj=new list<int>[v];
		
	}
	void add(int u,int w)
	{
		adj[u].push_back(w);
	}
	void bfs(int s)
	{
		bool *vis=new bool[v];
		for(int i=0;i<v;i++)
		{
			vis[i]=false;
		}
		list<int> queue;
		list<int>::iterator it;
		vis[s]=true;
		queue.push_back(s);
		while(!queue.empty())
		{
			s=queue.front();
			cout<<s<<"\t";
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
		
		
	}
};
int main()
{
	graph g(4);
	g.add(0,1);
	g.add(0,2);
	g.add(1,2);
	g.add(2,0);
	g.add(2,3);
	g.add(3,3);
	g.bfs(2);
}
