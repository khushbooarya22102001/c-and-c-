#include<iostream>
using namespace std;
const int size=3;
class vector{
	int v[size];
	public:
		vector()
		{
			for(int i=0;i<size;i++)
			{
				v[i]=0;
			}
		}
		vector(int *x)
		{
			for(int i=0;i<size;i++)
			{
				v[i]=x[i];
			}
		}
		friend vector operator *(int a,vector b)
		{
			vector c;
			for(int i=0;i<size;i++)
			{
				c.v[i]=a*b.v[i];
			}
			return c;
		}
		int operator *(vector &y)
		{
			int sum=0;
			for(int i=0;i<size;i++)
			{
				sum+=this->v[i]*y.v[i];
			}
			return sum;
		}
};
int main()
{
	int x[3]={1,2,3};
	int y[3]={4,5,6};
	vector v1;
	vector v2;
	vector p;
	v1=x;
	v2=y;
	p=2*v1;
	cout<<"p:"<<p;
	int R=v1*v2;
	cout<<"\nR:"<<R;
	
}
