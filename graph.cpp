#include<iostream>
#include<list>
#include<iterator>
using namespace std;
class Graph{
	int v;
	list<int> *adj;
	public:
		Graph(int v)
		{
			this->v=v;
			adj=new list<int>[v];
		}
		void adde(int u,int w)
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
			list<int> que;
			vis[s]=true;
			que.push_back(s);
			list<int>::iterator it;
			while(!que.empty())
			{
				s=que.front();
				cout<<s<<" ";
				que.pop_front();
				for(it=adj[s].begin();it!=adj[s].end();it++)
				{
					if(!vis[*it])
					{
						vis[*it]=true;
						que.push_back(*it);
					}
				}
			}
		}
	
};
int main()
{
	Graph g(4);
	g.adde(0,1);
	g.adde(0,2);
	g.adde(1,2);
	g.adde(2,0);
	g.adde(2,3);
	g.adde(3,3);
	cout<<"ans:";
	g.bfs(2);
}
