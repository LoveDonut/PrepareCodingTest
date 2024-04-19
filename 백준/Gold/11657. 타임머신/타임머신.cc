#include<bits/stdc++.h>

#define ll long long

using namespace std;    

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
 	
 	ll dist[501];
 	vector<tuple<int,int,int>> bus;
 	
 	fill(dist, dist + 501, 1e9);

 	dist[1] = 0;
 	int n, m;
 	
 	cin >> n >> m;
 	
 	for(int i=0; i<m; i++)
 	{
 		int a, b, c;
		cin >> a >> b >> c;
		bus.push_back(make_tuple(a,b,c));
	}
	
	for(int i=0; i<n-1; i++)
	{
		for(tuple<int,int,int> t : bus)
		{
			int a, b, c;
			tie(a,b,c) = t;
			if(dist[a] != 1e9)
			{
				dist[b] = min(dist[b], dist[a] + c);
			}
		}
	}
	
	for(tuple<int,int,int> t : bus)
	{
		int a, b, c;
		tie(a,b,c) = t;
		if(dist[a] != 1e9 && dist[b] > dist[a] + c)
		{
			if(dist[b] > dist[a] + c)
			cout << "-1";
			return 0;
		}
	}
	
 	for(int i=2; i<=n; i++)
 	{
 		if(dist[i] == 1e9)
 		{
 			cout << "-1\n";
		}
 		else
 		{
 			cout << dist[i] << '\n';	
		}
	}
}