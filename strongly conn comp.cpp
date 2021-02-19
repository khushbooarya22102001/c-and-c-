#include<iostream>
#include<list>
#include<stack>
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
		void dfs(int s,bool *vis,stack<int> &st)
		{
			vis[s]=true;
			list<int>::iterator it;
			for(it=adj[s].begin();it!=adj[s].end();it++)
			{
				if(!vis[*it])
				{
					dfs(*it,vis,st);
				}
			}
			st.push(s);
		}
		graph gettranspose()
		{
			graph g2(v);
			for(int i=0;i<v;i++)
			{
				cout<<"\n i:"<<i;
				list<int>::iterator j;
				for(j=adj[v].begin();j!=adj[v].end();j++)
				{
					g2.adj[*j].push_back(v);
				}
			}
			return g2;
		}
 
		void dfsutil(int k,bool *vis)
		{
			vis[k]=true;
			
			cout<<k<<"\t";
			list<int>::iterator it;
			for(it=adj[k].begin();it!=adj[k].end();it++)
			{
				if(!vis[*it])
				{
					dfsutil(*it,vis);
				}
			}
			
		}
		void printscc()
		{
			stack<int> st;
			bool *vis=new bool[v];
			for(int i=0;i<v;i++)
			{
				vis[i]=false;
				
			}
			for(int i=0;i<v;i++)
			{
				if(!vis[i])
				{
					dfs(i,vis,st);
				}
			}
			cout<<"\ndfs done:";
			graph gr=gettranspose();
			
			for(int i=0;i<v;i++)
			{
				vis[i]=false;
			}
			while(!st.empty())
			{
				int z=st.top();
				st.pop();
				if(!vis[z])
				{
					gr.dfsutil(z,vis);
				}
				cout<<"\n";
			}
			
		}
		
};
int main()
{
	graph g1(5);
	g1.add(1,0);
	g1.add(0,2);
	g1.add(2,1);
	g1.add(0,3);
	g1.add(3,4);
	g1.printscc();
}
