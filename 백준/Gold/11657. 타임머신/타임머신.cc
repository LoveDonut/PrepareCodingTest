#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll dist[501];
vector<pair<pair<int,int>,int>> v;
int n, m;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m;
	
	for(int i=0; i<m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back({{a,b},c});
	}
	
	fill(dist + 2, dist + 501, 1e9);
		
	for(int i=0; i<n-1;i++)
	{
		for(pair<pair<int,int>,int> p : v)
		{
			int from = p.first.first, to = p.first.second, cost = p.second;
			
			if(dist[from] == 1e9) continue;
			
			if(dist[to] > dist[from] + cost)
			{
				dist[to] = dist[from] + cost;
			}
		}
	}
	
	for(pair<pair<int,int>,int> p : v)
	{
		int from = p.first.first, to = p.first.second, cost = p.second;
		
		if(dist[from] == 1e9) continue;
		
		if(dist[to] > dist[from] + cost)
		{
			cout << "-1";
			return 0;
		}
	}
	
	for(int i=2; i<=n; i++)
	{
		if(dist[i] == 1e9)
		{
			cout <<"-1\n";
		}
		else
		{
			cout << dist[i] << '\n';
		}
	}
	
	
	return 0;
}