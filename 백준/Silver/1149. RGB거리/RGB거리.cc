#include <bits/stdc++.h>

using namespace std;

int dp[1000][3];

int main()
{
	int n;
	cin >> n;
	for(int i=0; i<n; i++)
	{
		int a,b,c;
		cin >> a >> b >> c;
		dp[i][0] = a;
		dp[i][1] = b;
		dp[i][2] = c;		
	}
	for(int i=1; i<n; i++)
	{
		for(int j=0; j<3; j++)
		{
			int num = 1e9;
			if(0 != j)
			{
				num = min(num, dp[i-1][0]);
			}
			if(1 != j)
			{
				num = min(num, dp[i-1][1]);				
			}
			if(2 != j)
			{
				num = min(num, dp[i-1][2]);				
			}
			dp[i][j] += num;
		}
	}
	cout << min(dp[n-1][0], min(dp[n-1][1], dp[n-1][2]));
	return 0;
}