#include <bits/stdc++.h>

using namespace std;

int dy[4] = {0,0,1,-1}, dx[4] = {1,-1,0,0};
class Move
{
	public:
		int y;
		int x;
		int d;
	Move(int y, int x, int d)
	{
		this->y = y;
		this->x = x;
		this->d = d;
	}
};
struct cmp
{
	bool operator()(const Move a, const Move b)
	{
		if(a.y == b.y)
		{
			return a.x > b.x;
		}
		return a.y > b.y;
	}
};

int main()
{
	int table[21][21];
	fill(table[0], table[0] + 21*21, 1e9);

	int n;
	Move shark = {0,0,0};
	cin >> n;
	
	for(int y=0; y<n; y++)
	{
		for(int x=0; x<n; x++)
		{
			int a;
			cin >> a;
			if(a == 9)
			{
				shark = {y,x,0};
			}
			else
			{
				table[y][x] = a;				
			}
		}
	}
	int size = 2;
	int eat = 0;
	while(true)
	{
		priority_queue<Move, vector<Move>, cmp> candids;
		
		queue<Move> pq;
		pq.push(shark);
		bool visited[21][21];
		fill(visited[0], visited[0] + 21*21, false);
		visited[shark.y][shark.x] = true;

		int d = 1e9;
		while(pq.size())
		{
			auto p = pq.front(); pq.pop();
			for(int i=0; i<4; i++)
			{
				int ny = p.y + dy[i], nx = p.x + dx[i];
				if(ny >= 0 && ny < n && nx >= 0 && nx < n && p.d + 1 <= d &&
					!visited[ny][nx] && table[ny][nx] <= size)
				{
					visited[ny][nx] = true;
					if(table[ny][nx] != 0 && table[ny][nx]< size)
					{
						candids.push({ny, nx, p.d+1});
						d = p.d + 1;
					}
					else
					{
						pq.push({ny, nx, p.d + 1});
					}
				}
			}
		}
		if(candids.size())
		{
			eat++;
			if(eat == size)
			{
				eat = 0;
				size++;
			}
			table[shark.y][shark.x] = 0;
			shark = candids.top(); candids.pop();
		}
		else
		{
			break;
		}
	}
	cout << shark.d;
	return 0;
}