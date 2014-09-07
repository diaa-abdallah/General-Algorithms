#include <iostream>
#include <stack>
#include <queue>
#include <hash_map>
#include <unordered_map>
using namespace std;

class Queue1
{

	stack<int> s1,s2;
public:
	void push(int num)
	{
		while(!s2.empty())
		{
			s1.push(s2.top());
			s2.pop();
		}
		s1.push(num);
	}

	int pop()
	{
		while(!s1.empty())
		{
			s2.push(s1.top());
			s1.pop();
		}
		if(s2.empty())
			return -1;
		int num=s2.top();
		s2.pop();
		return num;

	}
};
class Stack1
{

	queue<int> q1,q2;
public:
	void push(int num)
	{
		while(!q2.empty())
		{
			q1.push(q2.front());
			q2.pop();
		}
		q1.push(num);
	}
	int pop()
	{
		int last=-1;
		while(q1.size()>1)//moving to q2
		{
			q2.push(q1.front());
			q1.pop();
		}
		int num= q1.front();
		q1.pop();
		while(!q2.empty())//returning back to q1
		{
			q1.push(q2.front());
			q2.pop();
		}
		return num;
		
	}
};
int main()
{
	Stack1 q;
	q.push(int(1));
	q.push(int(2));
	q.push(int(3));
	cout<<q.pop()<<endl;
	cout<<q.pop()<<endl;
	q.push(int(4));
	cout<<q.pop()<<endl;
	cout<<q.pop()<<endl;
	system("PAUSE");
	return 0;
}