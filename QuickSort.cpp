#include<iostream>
#include<vector>
using namespace std;
//Returns new pivot location
int partition(vector<int>& v,int left,int right,int pivot)
{
	if(left!=pivot)
		swap(v[left],v[pivot]);
	int currentLessThanPivot=left+1;
	for(int i=left+1;i<right;i++)
	{
		if(v[i]<v[pivot])
		{
			swap(v[currentLessThanPivot++],v[i]);
		}
	}
	swap(v[left],v[currentLessThanPivot-1]);
	return currentLessThanPivot;
}
void quickSort(vector<int>& v,int left,int right)
{
	int pivot=left;
	if((right-left)<=1)
		return;
	int pivotLocation=partition(v,left,right,pivot);
	quickSort(v,left,pivotLocation);
	quickSort(v,pivotLocation+1,right);
}
int main()
{
	int a[5]={3,5,4,2,6};
	vector<int> v(a,a+5);
	quickSort(v,0,4);
	return 0;
}