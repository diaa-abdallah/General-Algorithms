#include<iostream>
using namespace std;
template<class T>
class node{
public:
	node* next;
	T data;

	node(T d,node* n)
	{
		data=d;
		next=n;
	}
};
template<class T>
class stack{

	node<T>* first;
	int s;
public:
	stack()
	{
		first=0;
		s=0;
	}
	void push(T d)
	{
		if(first==0)
			first=new node<T>(d,0);
		else
		{
			node<T>* newFirst=new node<T>(d,first);
			first=newFirst;
		}
		++s;
	}
	T pop()
	{
		node<T>* previousFirst=first;
		T data=previousFirst->data;
		first=first->next;
		delete previousFirst;
		--s;
		return data;
	}
	
	int size()
	{
		return s;
	}
};
int main()
{
	stack<int> st;
	st.push(1);
	st.push(3);
	cout<<st.size()<<endl;
	cout<<st.pop();
	cout<<st.pop();
	cout<<endl<<st.size()<<endl;
	return 0;
}