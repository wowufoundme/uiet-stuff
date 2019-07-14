#include<iostream>

using namespace std;

int main()
{
	int arr[50],n,key,flag=0,mid;
	cout<<"Enter the no of elements: ";
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	int first=0;
	int last=n-1;
	cout<<"\n\nEnter the element to be searched: ";
	cin>>key;
	while(first<=last)
	{
		mid=(first+last)/2;
		if(key==arr[mid])
		{
			flag=1;
			break;
		}
		else if(key<arr[mid])
			last=mid-1;
		else if(key>arr[mid])
			first=mid+1; 
	}
	if(flag==0)
	{
		cout<<"Element not found!";
	}
	else{
		cout<<"Element found at "<<mid+1;
	}
	
	return 0;
}
