#include<iostream>
#include<list>
#include<stack>
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
		void addEdge(int u,int w)
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
		graph transpose()
		{
			graph g2(v);
			for(int k=0;k<v;k++)
			{
				list<int>::iterator it;
				for(it=adj[v].begin();it!=adj[v].end();it++)
				{
					g2.adj[*it].push_back(v);
				}
			}
			return g2;
		}
		void dfsrec(bool *vis,int k)
		{
			vis[k]=true;
			cout<<k<<"\t";
			list<int>::iterator it;
			for(it=adj[k].begin();it!=adj[k].end();it++)
			{
				if(!vis[*it])
				{
					dfsrec(vis,*it);
				}
			}
		}
		void printSCCs()
		{
			stack<int> st;
			bool *vis=new bool[v];
			for(int i=0;i<v;i++)
			{
				vis[i]=false;
			}
			for(int j=0;j<v;j++)
			{
				if(!vis[j])
				{
					dfs(j,vis,st);
				}
			}
			graph gr=transpose();
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
					gr.dfsrec(vis,z);
				}
			}
		}
		
};	
int main() 
{ 
    graph g(5); 
    g.addEdge(1, 0); 
    g.addEdge(0, 2); 
    g.addEdge(2, 1); 
    g.addEdge(0, 3); 
    g.addEdge(3, 4); 
  
    cout << "Following are strongly connected components in "
            "given graph \n"; 
    g.printSCCs(); 
  
    return 0; 
} 
