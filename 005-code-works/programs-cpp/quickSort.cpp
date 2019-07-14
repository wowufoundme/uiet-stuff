#include<iostream>

using namespace std;

int partition(int a[], int p, int r){
	int x=a[r];
	int i=p-1;
	for(int j=p;j<=r-1;j++)
		if(a[j]<=x)
		{
			i=i+1;
			int temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	int temp=a[i+1];
	a[i+1]=a[r];
	a[r]=temp;
	return (i+1);
}


quickSort(int a[], int p, int r){
	if(p<r)
	{
		int q=partition(a, p, r);
		quickSort(a, p, q-1);
		quickSort(a, q+1, r);
	}
}

int main()
{
	int arr[]={7,4,5,3,9,1,2};
	quickSort(arr,0,6);
	for(int i=0;i<=6;i++)
		cout<<arr[i]<<"\t";
	return 0;
}
