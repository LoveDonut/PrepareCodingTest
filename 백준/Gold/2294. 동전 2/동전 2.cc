#include <bits/stdc++.h>

using namespace std;

int n, k;
int dp[10001];
vector<int> v(101);

int go(int sum)
{
	if(sum <=0) return sum == 0 ? 0 : 1e9;
	
	int& ret = dp[sum];
	if(ret) return ret;
	
	ret = 1e9;
	for(int i=0; i<n; i++)
	{
		ret = min(ret, go(sum - v[i]) + 1);
	}

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int ret;
	cin >> n >> k;
	
	for(int i=0; i<n; i++)
	{
		cin >> v[i];
	}
	
	sort(v.begin(), v.begin() + n, greater<int>());
	
	ret = go(k);
	
	if(ret >= 1e9) ret = -1;
	
	cout << ret;
	
	return 0;
}