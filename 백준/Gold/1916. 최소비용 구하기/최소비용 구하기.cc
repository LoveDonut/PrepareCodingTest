#include <bits/stdc++.h>

using namespace std;

int dists[1001];
vector<vector<pair<int,int>>> vv(1001);

void dijkstra(int start)
{
	//{거리, 도시} 
	priority_queue<pair<int,int>, vector<pair<int,int>>> pq;
	
	pq.push({0, start});
	dists[start] = 0;
	while(pq.size())
	{
		int dist = pq.top().first;
		int node = pq.top().second; pq.pop();
		
		if(dists[node] < dist) continue;
		
		for(int i=0; i<vv[node].size(); i++)
		{
			if(dists[vv[node][i].second] > vv[node][i].first + dist)
			{
				dists[vv[node][i].second] = vv[node][i].first + dist;
				pq.push({dists[vv[node][i].second], vv[node][i].second});
			}
		}
	}
}

int main()
{
	int n,m;
	
	cin >> n >> m;
	
	fill(dists, dists + n+1, 1e9);	
	
	for(int i=0; i<m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		vv[a].push_back({c, b});
	}
	int a, b;
	cin >> a >> b;
	dijkstra(a);
	cout << dists[b];
	return 0;
}