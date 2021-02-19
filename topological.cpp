#include<iostream>
#include<stack>
#include<list>
#include<iterator>
using namespace std;
class graph{
	int v;
	list<int> *adj;
	public:
		graph(int z)
		{
			v=z;
			adj=new list<int>[v];
		}
		void add(int u,int w)
		{
			cout<<"edge pushed\t";
			adj[u].push_back(w);
		}
		void toporec(int k,bool *vis,stack<int> s)
		{
			cout<<"k:"<<k<<"\t";
			vis[k]=true;
			list<int>::iterator it;
			for(it=adj[k].begin();it!=adj[k].end();it++)
			{
				if(!vis[*it])
				{
					toporec(*it,vis,s);
				}
			}
			s.push(k);
		}
		void topo()
		{
			stack<int> s;
			bool *vis=new bool[v];
			for(int i=0;i<v;i++)
			{
				cout<<"i:"<<i<<"\t";
				vis[i]=false;
			}
			for(int i=0;i<v;i++)
			{
				if(vis[i]==false)
				{
					toporec(i,vis,s);
				}
				
			}
			cout<<"s top:"<<s.top();
			while(!s.empty())
			{
				cout<<s.top()<<" ";
				s.pop();
			}
		}
};
int main()
{
	graph g(6);
	g.add(5,2);
	g.add(5,0);
	g.add(4,0);
	g.add(4,1);
	g.add(2,3);
	g.add(3,1);
	g.topo();
}
