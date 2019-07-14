#include<iostream>
using namespace std;
class BST
{
	private:
		struct node{
			int key;
			node *left;
			node *right;
		};
		node* CreateLeaf(int key);
	public:
		node *root;
		BST();		
		int arr[200];
		static int k;
		void AddLeaf(node *ptr, int key);
		void InOrder(node *ptr);
		void PreOrder(node *ptr);
		void PostOrder(node *ptr);
		int SearchTree(node *ptr, int SearchItem);
		int SearchNew(node *ptr, int key);
		void DisplayTree(node *ptr, int level);
};
