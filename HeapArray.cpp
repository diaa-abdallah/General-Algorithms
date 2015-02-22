#include<iostream>

using namespace std;

class maxHeap{
	int* a;
	int lastPosition;
public:
	maxHeap(int maxcapacity)
	{
		a=new int[maxcapacity];
		memset(a,0,sizeof(int)*(maxcapacity));
		lastPosition=-1;
	}
	void swim(int currentNode)
	{
		int currentParent=(lastPosition-1)/2;
		while(currentNode!=0)
		{
			if(a[currentParent]<a[currentNode])
				swap(a[currentParent],a[currentNode]);
			currentNode=currentParent;
			currentParent=(currentParent-1)/2;
		}
	}
	void insert(int value)
	{
		a[++lastPosition]=value;
		//swim
		swim(lastPosition);
	}
	int getMax()
	{
		return a[lastPosition];
	}
	void delMax()
	{
		a[0]=0;
		swap(a[0],a[lastPosition]);
		sink(0);
	}
	void sink(int currentNode)
	{
		int leftChild=currentNode*2+1;
		int rightChild=currentNode*2+2;

		while(leftChild<=lastPosition)
		{

			if(a[leftChild]>a[currentNode]&&(a[leftChild]>a[rightChild]||rightChild>lastPosition))
			{
				swap(a[currentNode],a[leftChild]);
				currentNode=leftChild;
			}
			else if(rightChild<=lastPosition && a[rightChild]>a[currentNode])
			{
				swap(a[currentNode],a[rightChild]);
				currentNode=rightChild;
			}
			else
				currentNode=leftChild;
			leftChild=currentNode*2+1;
			rightChild=currentNode*2+2;
		}
	}
	void heapSort(int* unsortedArray,int count)
	{
		lastPosition=count-1;
		delete[] this->a;
		this->a=unsortedArray;
		for(int i=(lastPosition+1)/2;i>=0;i--)
		{
			sink(i);
		}
		for(int i=0;i<count;i++)
		{
			swap(a[0],a[lastPosition]);
			lastPosition--;
			sink(0);
		}
	}
};
int main()
{
	maxHeap m(1);
	int a[5]={4,2,5,9,1};
	m.heapSort(a,5);
	return 0;
}