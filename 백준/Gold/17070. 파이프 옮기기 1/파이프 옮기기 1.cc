#include <bits/stdc++.h>

using namespace std;

int ret, N;
int table[17][17];

void go(int fy, int fx, int sy, int sx)
{
	if(sy == N && sx == N)
	{
		ret++;
		return;
	}
	
	if(sy - fy == 1 && sy+1 <= N && !table[sy+1][sx])
	{
		go(sy, sx, sy+1, sx);
	}
	if(sx - fx == 1 && sx+1 <= N && !table[sy][sx+1])
	{
		go(sy, sx, sy, sx+1);
	}
	if(sy+1 <= N &&  sx+1 <= N && !table[sy+1][sx] && !table[sy][sx+1] && !table[sy+1][sx+1])
	{
		go(sy, sx, sy+1, sx+1);	
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> N;
	
	for(int y=1; y<=N; y++)
	{
		for(int x=1; x<=N; x++)
		{
			cin >> table[y][x];
		}
	}
	
	go(1,1,1,2);
	
	cout << ret;
	
	return 0;
}