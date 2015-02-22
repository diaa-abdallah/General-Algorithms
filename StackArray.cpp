#include<iostream>
using namespace std;
template<class T>
class stack{

	T* stArray;
	int s;
	int capacity;
public:
	stack()
	{
		stArray=new T[1];
		s=0;
		capacity=1;
	}
	void resize(int capacity)
	{
		T* tempArray=new T[capacity];
		for(int i=0;i<s;i++)
		{
			tempArray[i]=stArray[i];
		}
		delete[] stArray;
		stArray=tempArray;
	}
	void push(T d)
	{
		if(s==capacity)
			resize(2*capacity);
		stArray[s++]=d;
	}
	T pop()
	{
		T data=stArray[--s];
		if(s!=0 && s== (capacity/4) )
			resize(capacity/2);
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