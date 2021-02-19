#include<iostream>
using namespace std;

string add(string x1,string y1)
{
	int i=x1.size()-1;
	int j=y1.size()-1;
	int carry=0;
	string res;
	while(i>=0 ||j>=0)
	{
		int sum=carry;
		if(i>=0)
		{
			sum+=x1[i]-'0';
		}
		if(j>=0)
		{
			sum+=y1[j]-'0';
		}
		res+=sum%2;
		carry=sum/2;
	}
	if(carry!=0)
	{
		res+='1';
	}
	return res;
}
int main()
{
	cout<<add("00","01");
}
