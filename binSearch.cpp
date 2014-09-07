#include <iostream>
#include <string>
#include <regex>
using namespace std;

int binarySearchAux(int a[],int value,int start,int end)
{
	if(start>end)
		return -1;
	int middle=(start+end)/2;
	if(a[middle]>value)//left half
		binarySearchAux(a,value,start,middle-1);
	else if(a[middle]<value)
		binarySearchAux(a,value,middle+1,end);
	else
		return middle;
}
int binarySearch(int a[],int value,int size)
{
	return binarySearchAux(a,value,0,size-1);
}

int main()
{
	
	int a[4]={0,1,2,4};
	cout<<binarySearch(a,4,4);
	int b;
	cin>>b;
	return 0;
}