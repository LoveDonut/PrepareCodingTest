#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int t, n;
	int dp[10001];
	
	cin >> t;
	
	while(t--)
	{
		cin >> n;
		
		fill(dp, dp + 10001, 1);
		
		for(int i=2; i<=3; i++)
		{
			for(int j=1; j<=n; j++)
			{
				dp[j] += j-i >= 0 ? dp[j-i] : 0;
			}
		}
		
		cout << dp[n] << '\n';
	}
}