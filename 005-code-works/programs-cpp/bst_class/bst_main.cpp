#include "bst.h"
using namespace std;
BST::BST()
{
	root=NULL;	
}
int BST::k=0;
BST::node* BST::CreateLeaf(int key)
{
	node *leaf=new node;
	leaf->key=key;
	leaf->right=NULL;
	leaf->left=NULL;
	arr[k]=key;
	k++;
	return leaf;
}
void BST::AddLeaf(node *ptr, int key)
{
	if(root==NULL)
	{
		root=CreateLeaf(key);
	}
	else if(key<ptr->key)
	{
		if(ptr->left!=NULL)
			AddLeaf(ptr->left,key);
		else
			ptr->left=CreateLeaf(key);
	}
	else if(key>ptr->key)
	{
		if(ptr->right!=NULL)
			AddLeaf(ptr->right,key);
		else
			ptr->right=CreateLeaf(key);
	}
	else
	{
		cout<<"ERROR 0x3C9: "<<key<<" already in the tree. Cannot be added twice!\n";
	}
}
void BST::InOrder(node *ptr)
{
	if(root!=NULL)
	{
		if(ptr->left!=NULL)
		{
			InOrder(ptr->left);
		}
		cout<<ptr->key<<" ";
		if(ptr->right!=NULL)
		{
			InOrder(ptr->right);
		}
	}
	else
	{
		cout<<"\nThe tree is empty!\n";
	}
}
void BST::PreOrder(node *ptr)
{
	if(root!=NULL)
	{
		cout<<ptr->key<<" ";
		if(ptr->left!=NULL)
		{
			PreOrder(ptr->left);
		}
		if(ptr->right!=NULL)
		{
			PreOrder(ptr->right);
		}
	}
	else
	{
		cout<<"\nThe tree is empty!\n";
	}
}
void BST::PostOrder(node *ptr)
{
	if(root!=NULL)
	{
		if(ptr->left!=NULL)
		{
			PostOrder(ptr->left);
		}
		if(ptr->right!=NULL)
		{
			PostOrder(ptr->right);
		}
		cout<<ptr->key<<" ";
	}
	else
	{
		cout<<"\nThe tree is empty!\n";
	}
}
int BST::SearchTree(node *ptr, int SearchItem)
{
	int flag=0;
	for(int i=0;i<k;i++)
	{
		if(arr[i]==SearchItem)
		{
			return 1;
		}
	}
}
int BST::SearchNew(node *ptr, int key)
{
	if(ptr==NULL)
		return -1;
	else if(ptr->key==key)
		return 1;
	else if((key<ptr->key)&&ptr->left!=NULL)
		return SearchNew(ptr->left,key);
	else if((key>ptr->key)&&ptr->right!=NULL)
		return SearchNew(ptr->right,key);
}
void BST::DisplayTree(node *ptr, int level)
{
	int i;
	if(ptr!=NULL)
	{
		DisplayTree(ptr->right, level+1);
		cout<<endl;
		if(ptr==root)
			cout<<"";
		else
		{
			for(i=0;i<level;i++)
				cout<<"     ";
		}
		cout<<ptr->key;
		DisplayTree(ptr->left,level+1);
	}
}
int main()
{
	int TreeKeys[7]={50,61,40,45,50,55,100};
	BST tree;
	cout<<"\nPrinting tree before adding number: ";
	tree.InOrder(tree.root);
	cout<<"\n\nAdding Elements to tree...\n";
	for(int i=0;i<7;i++)
	{
		cout<<TreeKeys[i]<<" being added to tree...\n";
		tree.AddLeaf(tree.root,TreeKeys[i]);
	}
	cout<<"\nPrinting tree after adding number(InOrder): ";
	tree.InOrder(tree.root);
	cout<<"\nPrinting tree after adding number(PreOrder): ";
	tree.PreOrder(tree.root);
	cout<<"\nPrinting tree after adding number(PostOrder): ";
	tree.PostOrder(tree.root);
	int x, status=0;
	cout<<endl;
	tree.DisplayTree(tree.root,1);
	cout<<"\nEnter x to be searched: ";
	cin>>x;
	status=tree.SearchNew(tree.root,x);
	if(status==1)
		cout<<"Item found in tree!";
	else if(status==-1)
		cout<<"Tree Empty!";
	else
		cout<<"Item not found!";
	return 0;
}


