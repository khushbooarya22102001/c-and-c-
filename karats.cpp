#include<iostream>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;
int make(string &a,string &b)
{
	int len1=a.size();
	int len2=b.size();
	if(len1<len2)
	{
		for(int i=0;i<len2-len1;i++)
		{
			a='0'+a;
		}
		return len2;
		
	}
	else if(len1>len2)
	{
		for(int j=0;j<len1-len2;j++)
		{
			b='0'+b;
		}
		return len1;
	}
	if(len1==len2)
	{
		return len1;
	}
	
	
}


string add(string x1,string y1)
{

	int i=x1.size()-1;
	int j=y1.size()-1;
	int carry=0;
	string res;
	while(i>=0|| j>=0)
	{
		int sum1=carry;
		if(i>=0)
		{
			sum1+=x1[i]-'0';
		}
		if(j>=0)
		{
			sum1+=y1[j]-'0';
		}
		res+=to_string(sum1%2);
		carry=sum1/2;
		i--,j--;
		
	}
	if(carry!=0)
	{
		res+='1';
		
	}
	reverse(res.begin(),res.end());
	return res;
}

int mul(string a,string b)
{
	return (a[0]-'0')*(b[0]-'0');
}
long int karat(string x,string y)
{
	int n=make(x,y);
	if(n==0)
	return 0;
	if(n==1)
	{
		return mul(x,y);
	}
	int f=floor(n/2);
	int s=ceil(n-f);
	string xl=x.substr(0,f);
	string xr=x.substr(f,s);
	string yl=y.substr(0,f);
	string yr=y.substr(f,s);
	long int p1=karat(xl,yl);
	long int p2=karat(xr,yr);
	long int p3=karat(add(xl,xr),add(yl,yr));
	long int p4=p3-p2-p1;
	return p1*(pow(2,2*s))+p4*(pow(2,s))+p2;
	
	
}
int main()
{
	cout<<karat("1100","1010");
	
}
