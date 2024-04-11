#include <bits/stdc++.h>

using namespace std;

long long dp[91];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n;
	cin >> n;
	
	dp[1] = 1;
	
	for(int i=2; i<=n; i++)
	{
		dp[i] = dp[i-1] + dp[i-2];
	}
	
	cout << dp[n];
	
	return 0;
}