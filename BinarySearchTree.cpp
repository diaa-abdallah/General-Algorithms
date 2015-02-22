#include <exception>
#include <iostream>
using namespace std;
template <typename K,typename T>
class BST{
	struct node
	{
		node* left;
		node* right;
		K key;
		T data;
		node(K k,T d,node* l=0,node* r=0)
		{
			key=k;
			data=d;
			left=l;
			right=r;
		}
	};
	node * root;
	int size;

public:
	void put(K key,T data)
	{
		node* current=root;
		node* currentParent=0;
		if (current==0)//New BST
		{
			root=new node(key,data);
			return;
		}
		while(current!=0 && current->key != key)
		{
			if(current->key==key)
			{
				current->data=data;
				return;
			}
			currentParent=current;
			if ( current->key > key )// go left
				current=current->left;
			else if(current->key <key)// go right
				current=current->right;
		}
		if (current==0)
		{
			if(currentParent->key > key)
				currentParent->left=new node(key,data);
			else if(currentParent->key <key)
				currentParent->right=new node(key,data);
		}
	}
	void recursivePut(K key,T data)
	{
		root=rPut(root,key,data);
	}

	node* rPut(node* current,K key, T data)
	{
		if (current == 0)
			return new node(key,data);
		if (current->key > key)
		{
			current->left= rPut(current->left,key,data);
		}
		else if( current->key < key)
		{
			current->right=rPut(current->right,key,data);
		}
		else
		{
			current->data=data;
		}
		return current;
	}
	T get(K key)
	{
		node* current=root;
		while(current!=0)
		{
			if(current->key == key)
				return current->data;
			if(current->key > key)
				current=current->left;
			else if(current->key < key)
				current=current->right;
		}
		throw exception("Not found");
	}
	BST():root(0)
	{
	}
};
int main()
{
	BST<int,int> myTree;
	myTree.recursivePut(3,4);
	myTree.recursivePut(2,5);
	myTree.recursivePut(6,9);
	myTree.recursivePut(4,10);
	myTree.recursivePut(5,4);
	try{
	int a=myTree.get(0);
	} catch(exception& e)
	{
		cout<<"Not Found"<<endl;
	}
	return 0;
}