#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
bool visited[10];
stack<int> st;
void dfs(vector<vector<int>> graph,int node)
{
	visited[node]=true;
	for(int i=0;i<graph[node].size();i++)
	{
		if(!visited[graph[node][i]])
		{
			dfs(graph,graph[node][i]);
		}
	}
	st.push(node);
}
int main(int argc,char* argv[])
{
	ifstream f(argv[1]);
	int N;
	f>>N;
	int a,b;
	vector<vector<int>> adjList(N);
	while(f>>a>>b)
	{
		adjList[a].push_back(b);
	}
	for(int i=1;i<adjList.size();i++)
	{
		if(!visited[i])
			dfs(adjList,i);
	}
	while(!st.empty())
	{
		cout<<st.top()<<endl;
		st.pop();
	}
	return 0;
}