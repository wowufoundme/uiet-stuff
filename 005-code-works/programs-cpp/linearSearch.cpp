#include<iostream>
#include<conio.h>

using namespace std;

int main(){
	int i, j, key, arr[10]={12,35,53,232,299,119,765,284,554,1133}, flag=0;
	cout<<"The array in the memory is: \n\n";
	for(i=0; i<10; i++)
		cout<<arr[i]<<"  ";
	cout<<"\n\n\nEnter the element to be searched: ";
	cin>>key;
	for(j=0; j<10; j++)
		if(arr[j] == key)
		{
			flag=1;
			break;
		}
	if(flag==0)
		cout<<"\nElement not found!";
	else
		cout<<"\nElement found at "<<j+1;
	getch();
	return 0;
}
