#include<bits/stdc++.h>

using namespace std;    

int v, e, start;
int dist[20001];

//pair<거리(음수), 도착node> 
vector<vector<pair<int,int>>> edges(300001);


void dijkstra()
{
	priority_queue<pair<int,int>> pq;
	pq.push({0,start});
	while(pq.size())
	{
		int weight = -pq.top().first, to = pq.top().second; pq.pop();
		
		for(pair<int,int> p : edges[to])
		{
			if(weight + p.first < dist[p.second])
			{
				dist[p.second] = weight + p.first;
				pq.push({-dist[p.second], p.second});
			}
		}
	}
}

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
 	
 	fill(dist, dist + 20001, 1e9);
 	
 	cin >> v >> e >> start;
 	dist[start] = 0;
 	
 	for(int i=0; i<e; i++)
 	{
 		int a, b, c;
 		cin >> a >> b >> c;
 		
 		edges[a].push_back({c,b});
	}
	
	dijkstra();
	
	for(int i=1; i<=v; i++)
	{
		if(dist[i] == 1e9)
		{
			cout << "INF\n";			
		}
		else
		{
			cout << dist[i] << '\n';
		}
	}
 	
}