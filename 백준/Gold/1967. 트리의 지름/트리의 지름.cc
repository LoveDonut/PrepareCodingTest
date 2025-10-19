#include <bits/stdc++.h>

using namespace std;

// <node, cost>
vector<vector<pair<int,int>>> vv;

int leaf;
int cost;
void dfs(int cnt, int node, vector<bool> visited)
{
	
	for(auto p : vv[node])
	{
		if(!visited[p.first])
		{
			visited[p.first] = true;
			dfs(cnt + p.second, p.first, visited);
			visited[p.first] = false;			
		}
	}
	if(cost < cnt)
	{
		cost = cnt;
		leaf = node;
	}
} 

int main()
{
	int n;
	cin >> n;
	vv.resize(n+1);
	for(int i=0; i<n-1; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		vv[a].push_back({b,c});
		vv[b].push_back({a,c});
	}
	vector<bool> visited(n+1, false);
	visited[1] = true;
	dfs(0, 1,visited);
	visited[1] = false;
	visited[leaf] = true;
	dfs(0,leaf,visited);
	cout << cost;
	return 0;
}