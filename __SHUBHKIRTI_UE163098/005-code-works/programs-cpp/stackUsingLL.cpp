#include <conio.h>
#include <iostream>

using namespace std;

int COUNT = 0;	
int FLAG = 0;

struct node{
	int data;
	node *link;
};

node *start=NULL;

bool isEmpty(){
	if(start == NULL)
		return true;
	else 
		return false;
}

void push(){
	node *temp = new node;
	cout<<"\nEnter data in node: ";
	cin>>temp->data;
	temp->link = start;
	start = temp;
}

void peek(){
	node *var = start;
	cout<<"Peeked Element at top: "<<var->data;
}

void pop()
{
	if(isEmpty())
	{
		cout<<"Stack Empty!";
		exit(0);
	}
	node *var = start;
	start = start->link;
	delete var;
}

int main()
{
	int op;
	char ch;
	do{
		system("cls");
		cout<<"---MENU---"<<endl;
		cout<<"1. Push"<<endl;
		cout<<"2. Peek"<<endl;
		cout<<"3. Delete Element from list"<<endl;
		cout<<"4. Display number of elements in the list"<<endl;
		cout<<"7. Press any other key to EXIT";
		cout<<"\nEnter your option(1-5): "<<endl;
		cin>>op;
		switch(op)
		{
			case 1	:	insertNodeStart();
						break;
			case 2	: 	insertNodeEnd();
						break;
			case 3	: 	insertNodeMiddle();
						break;
			case 4	: 	displayList();
						break;
			case 5	: 	deleteElement();
						break;
			case 6	:	cout<<"\n\nThe number of elements in the list is : "<<COUNT;
						break;
			default	: 	exit(0);
		}
		cout<<"\n\nDo you want to show menu again?(Y/N)";
		cin>>ch;
	}while((ch=='y')||(ch=='Y'));
	return 0; 
} 	
