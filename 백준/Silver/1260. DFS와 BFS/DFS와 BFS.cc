#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> vv(1001);
void dfs(int node,vector<bool>& visited)
{
	for(int i : vv[node])
	{
		if(!visited[i])
		{
			visited[i] = true;
			cout << i << ' ';
			dfs(i,visited);
		}
	}
}
void bfs(int start)
{
	vector<bool> visited(1001, false);
	queue<int> q;
	q.push(start);
	cout << start << ' ';
	visited[start] = true;
	while(q.size())
	{
		int node = q.front(); q.pop();
		for(int i : vv[node])
		{
			if(!visited[i])
			{
				visited[i] = true;
				cout << i << ' ';
				q.push(i);
			}
		}
	}
}
int main()
{
	int n, m, start;
	cin >> n >> m >> start;
	for(int i=0; i<m; i++)
	{
		int a, b;
		cin >> a >> b;
		vv[a].push_back(b);
		vv[b].push_back(a);		
	}
	for(int i=0; i<n+1; i++)
	{
		sort(vv[i].begin(), vv[i].end());
	}
	vector<bool> visited(n+1, false);
	visited[start] = true;
	cout << start << ' ';
	dfs(start, visited);
	cout << '\n';
	bfs(start);	
	return 0;
}