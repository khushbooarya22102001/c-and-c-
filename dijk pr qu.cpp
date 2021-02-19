#include<iostream>
#include<climits>
#include<list>
#include<queue>
#include<utility>
using namespace std;
typedef pair<int,int> ip;
class graph{
	public:
		int n;
		list<ip> *adj;
		graph(int n)
		{
			this->n=n;
			adj=new list<ip>[n];
		}
		void add(int u,int v,int w)
		{
			adj[u].push_back(make_pair(v,w));
			adj[v].push_back(make_pair(u,w));
		}
		void dijkstra(int n,int m,int src)
		{
			priority_queue<ip,vector<ip>,greater<ip> >pq;
			int *dist=new int[n];
			for(int i=1;i<=n;i++)
			{
				dist[i]=INT_MAX;
			}
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
				int weight=(*i).second;
				if(dist[v]>dist[u]+weight)
				{
					dist[v]=dist[u]+weight;
					pq.push(make_pair(dist[v],v));
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(i==src)
			{
				continue;
			}
			else if(dist[i]==INT_MAX)
			{
				cout<<"-1";
			}
			else{
				cout<<dist[i]<<" ";
			}
		}
		}
};
int main()
{
	int t;
	cout<<"enter test case:";
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int n,m;
		cout<<"\nenter vertex and edge:";
		cin>>n>>m;
		graph g(n);
		for(int i=1;i<=m;i++)
		{
			cout<<"\nenter edge: ";
			int beg,end,wei;
			cin>>beg>>end>>wei;
			g.add(beg,end,wei);
		}
		int src;
		cout<<"\n enter source:";
		cin>>src;
	}
}
