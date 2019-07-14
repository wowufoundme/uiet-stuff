#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>

using namespace std;

int q[50];
int front=-1;
int rear=-1;

void enqueue();
void dequeue();
void showq();
int peek();
bool isfull();
bool isempty();

void enqueue()
{
	if(isfull())
		cout<<"Overflow!";
	else
	{
		if(rear==-1)
			front++;
		rear++;
		cout<<"Enter data: ";
		cin>>q[rear];
	}
}

void dequeue()
{
	if(isempty())
		cout<<"Underflow!";
	else
	{
		if(front==0)
			rear--;
		front--;
		cout<<"Queue Dequeued!";
	}
}

int peek()
{
	return q[front];	
}

bool isfull()
{
	if(rear==49)
		return true;
	else
		return false;
}

bool isempty()
{
	if(rear==-1)
		return true;
	else 
		return false;
}

void showq()
{
	cout<<endl;
	for(int i=0;i<=rear;i++)
		cout<<q[i]<<" ";
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
