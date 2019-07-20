#include<iostream>

using namespace std;

void merge(int a[], int p, int q, int r)
{
	int n1=q-p+1;
	int n2=r-q;
	int l[n1+1];
	int rt[n2+1];
	for(int i=0;i<n1;i++)
		l[i]=a[p+i-1];
	for(int j=0;j<n2;j++)
		rt[j]=a[q+j];
	l[n1]=500;
	rt[n2]=500;
	int i=0,j=0;
	for(int k=p;k<r;k++)
	{
		if(l[i]<rt[j])
		{
			a[k]=l[i];
			i=i+1;
		}
		else
		{
			a[k]=rt[j];
			j=j+1;
		}
	}
}

void mergesort(int a[], int p, int r)
{
	if(p<r)
	{
		int q=(p+r)/2;
		mergesort(a,p,q);
		mergesort(a,q+1,r);
		merge(a,p,q,r);
	}
}

int main()
{
	int a[]={7,3,5,4,12,9};
	mergesort(a,0,5);
	for(int i=0;i<=5;i++)
		cout<<a[i]<<"\t";
	return 0;
}
