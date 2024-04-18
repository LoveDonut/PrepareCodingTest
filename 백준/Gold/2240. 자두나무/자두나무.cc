#include <bits/stdc++.h>

using namespace std;

int t, w;
int fall[1001];
int dp[1001][2][31];

int go(int times, int idx, int cnt)
{
	if(times < 0)
	{
		return cnt >= 0 ? 0 : -1e9;
	}
	if(cnt < 0)
	{
		return -1e9;
	}
	
	int& ret = dp[times][idx][cnt];
	if(ret) return ret + (fall[times] == idx);
	
	ret = max(ret, go(times - 1, idx, cnt));
	ret = max(ret, go(times - 1, idx^1, cnt - 1));
	
	return ret + (fall[times] == idx);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> t >> w;
	
	fill(fall, fall + 1001, -1);
	
	for(int i=0; i<t; i++)
	{
		int tmp;
		cin >> tmp;
		fall[i] = tmp - 1;
	}
	
	cout << go(t, 0, w);
	
	return 0;
}