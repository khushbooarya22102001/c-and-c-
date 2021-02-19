#include<iostream>
using namespace std;
void swap(int &a,int &b)
{
	int temp=a;
	a=b;
	b=temp;
}
void heapify(int a[],int n,int i)
{
	int lar=i;
	int l=2*i+1;
	int r=2*i+2;
	if(l<n && a[l]>a[lar])
	{
		lar=l;
	}
	if(r<n && a[r]>a[lar])
	{
		lar=r;
	}
	if(lar!=i)
	{
		swap(a[i],a[lar]);
		heapify(a,n,lar);
	}
	
}
void heapsort(int arr[],int n)
{
	for(int i=n/2-1;i>=0;i--)
	{
		heapify(arr,n,i);
	}
	for(int j=n-1;j>0;j--)
	{
		swap(arr[0],arr[j]);
		heapify(arr,j,0);
	}

}
int main()
{
	int n;
	cout<<"enter no of elements:";
	cin>>n;
	int *arr;
	arr=new int[n];
	cout<<"\n enter elements of array:";
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	heapsort(arr,n);
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
}
