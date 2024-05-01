#include <bits/stdc++.h>

using namespace std;

int n;
int dp[1000001];

int go(int num)
{
	if(num == 1)
	{
		return 0;
	}
	if(num < 1)
	{
		return 1e9;
	}
	
	int& ret = dp[num];
	if(ret) return ret;
	ret = 1e9;
	
	if(num % 3 == 0)
	{
		ret = min(ret, go(num / 3) + 1);
	}
	if(num % 2 == 0)
	{
		ret = min(ret, go(num / 2) + 1);
	}
	ret = min(ret, go(num - 1) + 1);
	
	return ret;
}

void trace(int n)
{
	if(n == 1)
	{
		cout << n;
		return;
	}
	if(n % 3 == 0 && dp[n] - 1 == dp[n/3])
	{
		cout << n << ' ';
		trace(n/3);
	}
	else if(n % 2 == 0 && dp[n] - 1 == dp[n/2])
	{
		cout << n << ' ';
		trace(n/2);
	}
	else
	{
		cout << n << ' ';
		trace(n-1);
	}
	
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;

	cout << go(n) << '\n';

	trace(n);
	
	return 0;
}