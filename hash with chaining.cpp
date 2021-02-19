#include<iostream>
#include<list>
#include<iterator>
using namespace std;
class hash{
	public:
	int buck;
	list<int> *table;
	hash(int b)
	{
		buck=b;
		table=new list<int>[buck];
	}
	int hashfun(int key)
	{
		return key%buck;
	}
	void ins(int key)
	{
		int i=hashfun(key);
		table[i].push_back(key);
		
	}
	void del(int key)
	{
		int i=hashfun(key);
		list<int>::iterator j;
		for(j=table[i].begin();j!=table[i].end();j++)
		{
			if(*j==key)
			table[i].erase(j);
			break;
			
		}
	}
	void display()
	{
		for(int i=0;i<buck;i++)
		{
			cout<<i;
			list<int>::iterator j;
			for(j=table[i].begin();j!=table[i].end();j++)
			{
				cout<<"-->"<<*j;
			}
			cout<<endl;
		}
	}
	
};
int main()
{
	hash h(7);
	int n;
	cout<<"enter no of elements to insert:";
	cin>>n;
	int x;
	for(int i=0;i<n;i++)
	{
		cout<<"\n enter element:";
		cin>>x;
		h.ins(x);
		
	}
	h.display();

	h.del(8);
	cout<<endl;
	h.display();
	h.del(15);
	cout<<endl;
	h.display();
	h.del(8);
	cout<<"\n";
	h.display();

}
