#include<iostream>
#include<conio.h>

using namespace std;

struct node{
	int data;
	node *next;
	node *back;
};

node *first;
node *last;

int count = 0;

void insert(){
	node *temp = new node;
	cout<<"Enter data in Node: ";
	cin>>temp->data;
	if(count==0){
		first = temp;
		temp->back = NULL;
		temp->next = NULL;
		count++;
	}
	else{
		node *var = first;
		for(int i=1; i<count; i++)
			var=var->next;
		var->next = temp;
		temp->back = var;
		temp->next = NULL;
		last = temp;
		count++;
	}
}

void deleteNode(){
	int key, check;
	bool flag=0;
	node *var = first;
	cout<<"Enter the element you want to delete: ";
	cin>>key;	
	while(var != NULL)
	{
		if(var->data == key){
			flag=1;
			break;
		}	
		var = var->next;
	}
	if(flag == 0){
		cout<<"Element not found!";
	}
	else{
		(var->back)->next = var->next;
		(var->next)->back = var->back;
		delete var;
		cout<<"Element Deleted!";
	}
}

void display(){
	node *var = first;
	while(var != NULL)
	{
		cout<<var->data<<" ";
		var = var->next;
	}
}

int main(){
	int op;
	char ch;
	do{
		system("cls");
		cout<<"---MENU---"<<endl;
		cout<<"1. Insert in the list"<<endl;
		cout<<"2. Display List"<<endl;
		cout<<"3. Delete Element from list"<<endl;
		cout<<"4. Press any other key to EXIT";
		cout<<"\nEnter your option(1-4): "<<endl;
		cin>>op;
		switch(op)
		{
			case 1	:	insert();
						break;
			case 2	: 	display();
						break;
			case 3	: 	deleteNode();
						break;
			default	: 	exit(0);
		}
		cout<<"\n\nDo you want to show menu again?(Y/N)";
		cin>>ch;
	}while((ch=='y')||(ch=='Y'));
	return 0; 
}

