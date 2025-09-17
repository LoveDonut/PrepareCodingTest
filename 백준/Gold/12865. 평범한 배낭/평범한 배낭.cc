#include <bits/stdc++.h>

using namespace std;

int dp[101][100001];

vector<pair<int, int>> v;

int main()
{
	int n,k;
	
	cin >> n >> k;
	
	for(int i=0; i<n; i++)
	{
		int a, b;
		cin >> a >> b;
		v.push_back({a,b});
	}
	
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=k; j++)
		{
			if(j < v[i-1].first)
			{
				dp[i][j] = dp[i-1][j];
			}
			else
			{
				dp[i][j] = max(v[i-1].second + dp[i-1][j-v[i-1].first], dp[i-1][j]);
			}
		}
	}

	cout << dp[n][k];
	return 0;
}