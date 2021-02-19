#include<iostream>
#include<list>
#include<queue>
#include<vector>
#include<utility>
#include<climits>
using namespace std;
typedef pair<int,int> ip;
class graph{
	public:
		int v;
		list<ip> *adj;
		graph(int z)
		{
			v=z;
			adj=new list<ip>[v];
		}
		void add(int u,int v,int w)
		{
			adj[u].push_back(make_pair(v,w));
			adj[v].push_back(make_pair(u,w));
		}
		void path(int src)
		{
			priority_queue<ip,vector<ip>,greater<ip> > pq;
			vector<int> dist(v, INT_MAX); 
		
			dist[src]=0;
			pq.push(make_pair(0,src));
			while(!pq.empty())
			{
				int u=pq.top().second;
				pq.pop();
				list<ip>::iterator i;
				for(i=adj[u].begin();i!=adj[u].end();i++)
				{
					int v=(*i).first;
					int wei=(*i).second;
					if(dist[v]>dist[u]+wei)
					{
						dist[v]=dist[u]+wei;
						pq.push(make_pair(dist[v],v));
						
					}
					
				}
			}
			for(int i=0;i<v;i++)
			{
				cout<<dist[i]<<"  ";
			}
		}
		
};
int main()
{
	graph g(9);
	g.add(0,1,4);
	g.add(0,7,8);
	g.add(1,2,8);
	g.add(1,7,11);
	g.add(2,3,7);
	g.add(2,8,2);
	g.add(2,5,4);
	g.add(3,4,9);
	g.add(3,5,14);
	g.add(4,5,10);
	g.add(5,6,2);
	g.add(6,7,1);
	g.add(6,8,6);
	g.add(7,8,7);
	g.path(0);
}
