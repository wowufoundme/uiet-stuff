#include<iostream>
#include<stdlib.h>

using namespace std;

void createArray(int *arr, int &size){
	cout<<"Enter the size of the array: ";
	cin>>size;
    cout<<"Enter the elements of array: ";
    for (int i=0 ; i<size; i++)
    	cin>>arr[i];
}

void displayArray(int arr[], int size){
	cout<<endl;
	for(int i=0 ; i<size ; i++)
		cout<<arr[i]<<"\t";
	cout<<endl;
}

void insertToArray(int *arr, int &size){

	cout<<size;
	cout<<"Enter element to be added: ";
	cin>>arr[size];
	size+=1;
}

void deleteFromArray(int *arr, int &size){
	int tempVar,flag=0;
	cout<<"Enter element to be deleted: ";
	cin>>tempVar;
	for(int i=0 ; i<size ; i++)
		if(arr[i] == tempVar)
		{
			flag=1;
			for(int j=i; j<size ; j++)
				arr[j]=arr[j+1];
			--size;
		}
	if(flag==0)
		cout<<"\nElement not found!\n";
	else	
		cout<<"\nElement deleted\n";
}

void insSort(int arr[], int size){
	int j;
	for(int i=1 ; i<size ; i++)
	{	
		int hold = arr[i];
		for(j=i-1;((j>=0)&&(hold<arr[j]));j--)
			arr[j+1] = arr[j];
		arr[j+1]=hold;	
	}
	cout<<"\nSorted Array is: ";
	for(int i=0 ; i<size ; i++)
		cout<<endl<<arr[i];
	cout<<endl;
}

int main(){
	int arr[100],x,op;
	char ch;
	do{
		system("cls");
		cout<<"===  ARRAY MENU  ===\n1. Create Array\n2. Display Array\n3. Insert Another Element in Array\n4. Delete an Element in Array\n5. Sort Array\n6. Exit\n\nEnter Option: ";
		cin>>op;
		switch(op){
			case 1	:	createArray(arr, x);
						break;
			case 2	: 	displayArray(arr, x);
						break;
			case 3	: 	insertToArray(arr, x);
						break;
			case 4	: 	deleteFromArray(arr,x);
						break;
			case 5	: 	insSort(arr,x);
						break;
			case 6	: 	exit(0);
			default	:	cout<<"Wrong Choice!";
						break; 
		}
		cout<<"Do you want to operate more?(Y/y = YES) : ";
		cin>>ch;
	}while((ch=='Y')||(ch=='y'));
	return 0;
}
