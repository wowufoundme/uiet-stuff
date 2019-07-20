#include <conio.h>
#include <iostream>

using namespace std;

int COUNT = 0;	
int FLAG = 0;

struct node{
	int data;
	node *link;
};

node *start;

void insertNode(){
	node *temp = new node;
	cout<<"\nEnter data in node: ";
	cin>>temp->data;
	if(COUNT == 0){
		start = temp;
		temp->link=start;
		COUNT++;
	}
	else{	
		node *var = start;
		while(var->link != start)
			var = var->link;
		var->link = temp;
		temp->link = start;
		COUNT++;
	}
}

void displayList(){
	if (COUNT == 0){
		cout<<"List is empty!";
	}
	else{
		node *var = start;
		cout<<var->data<<"\t";
		var = var->link;
		while(var != start)
		{
			cout<<var->data<<"\t";
			var = var->link;
		}
	}
}

/*
 *	Delete an element from the List
 *	This function deletes a node from the list. It asks which node to delete.
 *	It also checks if the element is present in the starting of the list or not.
 */
 
void deleteElement()
{
	int elem;
	FLAG = -1;
	cout<<"\nEnter Element to be deleted: ";
	cin>>elem;
	node *var = start;
	if(var->data == elem){
		node *temp = start;
		while(temp->link != start)
			temp = temp->link;
		temp->link = start->link;		
		delete var;
		COUNT--;
		FLAG = 1;
	}
	else{
		node *tmp;
		tmp = start;
		int check,i,j;
		for(i=1;i<COUNT;i++)
		{
			var = var->link;
			if(var->data == elem)
			{
				check = i;
				FLAG = 1;
				break;
			}
			else
				FLAG = -1;
		}
		if(FLAG == 1){
			for(j=1;j<check;j++)
				tmp = tmp->link;
			tmp->link = var->link;
			delete var;
			COUNT--;
		}
	}
	if(FLAG == -1)
		cout<<"\nElement not found in the list!\n";
	else if(FLAG == 1)
		cout<<"\nElement Deleted!\n";
	getch();
}

int main(){
	insertNode();
	insertNode();
	insertNode();
	insertNode();
	displayList();
	deleteElement();
	displayList();
	getch();
}


//int main()
//{
//	int op;
//	char ch;
//	do{
//		system("cls");
//		cout<<"---MENU---"<<endl;
//		cout<<"1. Insert (At the start of list)"<<endl;
//		cout<<"2. Insert (At the end of list)"<<endl;
//		cout<<"3. Insert (At the middle of list)"<<endl;
//		cout<<"4. Display List"<<endl;
//		cout<<"5. Delete Element from list"<<endl;
//		cout<<"6. Display number of elements in the list"<<endl;
//		cout<<"7. Press any other key to EXIT";
//		cout<<"\nEnter your option(1-5): "<<endl;
//		cin>>op;
//		switch(op)
//		{
//			case 1	:	insertNodeStart();
//						break;
//			case 2	: 	insertNodeEnd();
//						break;
//			case 3	: 	insertNodeMiddle();
//						break;
//			case 4	: 	displayList();
//						break;
//			case 5	: 	deleteElement();
//						break;
//			case 6	:	cout<<"\n\nThe number of elements in the list is : "<<COUNT;
//						break;
//			default	: 	exit(0);
//		}
//		cout<<"\n\nDo you want to show menu again?(Y/N)";
//		cin>>ch;
//	}while((ch=='y')||(ch=='Y'));
//	return 0; 
//} 	
