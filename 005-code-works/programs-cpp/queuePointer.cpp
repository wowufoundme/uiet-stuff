#include<iostream>

using namespace std;

struct node{
	int data;
	node *link;
};

node *front=NULL;
node *rear=NULL;

void enqueue()
{
	if((front==NULL)&&(rear==NULL))
	{
		node *temp=new node;
		cout<<"Enter data: ";
		cin>>temp->data;
		front=temp;
		rear=temp;
		temp->link=NULL;
	}
	else
	{
		node *temp=front;
		while(temp->link!=NULL)
			temp=temp->link;
		node *var=new node;
		cout<<"Enter data: ";
		cin>>var->data;
		var->link=temp->link;
		temp->link=var;
		rear=var;
	}
}

void dequeue()
{
	node *temp=front;
	cout<<temp->link<<" dequeued!";
	front=front->link;
	delete temp;
}

int peek()
{
	return front->data;
}

bool isempty()
{
	if((front==NULL)&&(rear==NULL))
		return true;
	else
		return false;
}

void showq()
{
	node *temp=front;
	cout<<endl;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->link;
	}
	cout<<endl;
}

int main()
{
	char ch;
	int op;
	do{
		system("cls");
		cout<<"1. Enqueue"<<endl;
		cout<<"2. Dequeue"<<endl;
		cout<<"3. Peek in Queue"<<endl;
		cout<<"4. Show Queue"<<endl;
		cout<<"Enter your option: "<<endl;
		cin>>op;
		switch(op)
		{
			case 1: enqueue();
					break;
			case 2: dequeue();
					break;
			case 3:	cout<<peek()<<endl;
					break;
			case 4: showq();
					break;
			default: cout<<"Wrong Choice Entered!";
		}
		cout<<"Do you want to perform again?(Y/N): ";
		cin>>ch;
	}while((ch=='Y')||(ch=='y'));
	return 0;
}
