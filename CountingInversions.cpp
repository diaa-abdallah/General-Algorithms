//
//Course: Algorithms Design and Analysis
//Problem: Counting inversions
//
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
 pair<vector<int>,long long> merge(vector<int>& left,vector<int>& right)
 {
	 int i=0,j=0;
	 vector<int> merged;
	 long long inversions=0;
	 while(i<left.size()&&j<right.size())
	 {
		 if(left[i]<=right[j])
		 {
			 merged.push_back(left[i++]);
		 }
		 else
		 {
			 inversions+=left.size()-i;
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
	 return pair<vector<int>,long long>(merged,inversions);

 }
 pair<vector<int>,long long> mergeSort(vector<int>& v,int left,int right)
 {
	 if(right-left==0)
	 {
		 int num=v[left];
		 vector<int> m;
		 m.push_back(num);
		 return pair<vector<int>,int>(m,0);
	 }
	 int mid=(left+right)/2;
	 long long inversions=0;
	 auto l=mergeSort(v,left,mid);
	 auto r=mergeSort(v,mid+1,right);

	 return pair<vector<int>,long long>(merge(l.first,r.first).first,merge(l.first,r.first).second+l.second+r.second);
 }
 int main()
 {
	 ifstream input("IntegerArray.txt");
	 int num;
	 vector<int> v;
	 while(input>>num)
	 {
		 v.push_back(num);
	 }
	 pair<vector<int>,long long> sort_and_count=mergeSort(v,0,v.size()-1);
	 return 0;
 }