#include<iostream>
using namespace std;
struct node{
	int info;
	node *left;
	node *right;
};
node *root=NULL;
void insertIntoTree(node *root, int val){
	if(root==NULL){
		node *temp=new node;
		temp->info=val;
		temp->left=temp->right=NULL;
		root=temp;
	}	
	else if(root->info==val)
		cout<<"\n\nElement already exists in the tree!";
	else if(root->info<val)
		insertIntoTree(root->right,val);
	else
		insertIntoTree(root->left,val);
}
void traversal(node *root, int val){
	if(root!=NULL)
	{
		if(val==0)
			cout<<root->info;
		traversal(root->left,val);
		if(val==1)
			cout<<root->info;
		traversal(root->right,val);
		if(val==2)
			cout<<root->info;
	}
}

 int main(){
//	for(int i=0;i<5;i++){
//		int key;
//		cout<<"Enter value to be entered: ";
//		cin>>key;
//		insertIntoTree(root,key);
//	}
	int key=10;	
	insertIntoTree(root,key);
	traversal(root, 2);
	return 0;
}
