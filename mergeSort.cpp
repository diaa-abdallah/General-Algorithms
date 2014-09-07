#include <iostream>
#include <vector>

using namespace std;
 vector<int> merge(vector<int> &left,vector<int>& right)
 {
	 int i=0,j=0;
	 vector<int> merged;
	 while(i<left.size()&&j<right.size())
	 {
		 if(left[i]<=right[j])
		 {
			 merged.push_back(left[i++]);
		 }
		 else
		 {
			 merged.push_back(right[j++]);
		 }
	 }
	 while(i<left.size())
	 {
		 merged.push_back(left[i++]);
	 }
	 while(j<right.size())
	 {
		 merged.push_back(right[j++]);
	 }
	 return merged;

 }
 vector<int> mergeSort(vector<int>& v,int left,int right)
 {
	 if(right-left==0)
	 {
		 int num=v[left];
		 vector<int> m;
		 m.push_back(num);
		 return m;
	 }
	 int mid=(left+right)/2;
	 vector<int> l=mergeSort(v,left,mid);
	 vector<int> r=mergeSort(v,mid+1,right);
	 return merge(l,r);
 }
 int main()
 {
	 int a1[3]={6,3,4};
	 int a2[2]={5,1};

	 vector<int> v1(a1,a1+3);
	 vector<int> v2(a2,a2+2);
	 vector<int> v3=merge(v1,v2);
	 vector<int> v4=mergeSort(v3,0,v3.size()-1);
	 return 0;
 }