#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll dp[31][31];

ll go(int w, int h)
{
	if(w == 0 && h == 0)
	{
		return 1;
	}
	
	ll& ret = dp[w][h];
	if(ret) return ret;
	if(w > 0)
	{
		ret += go(w - 1, h + 1);	
	}
	if(h > 0)
	{
		ret += go(w, h - 1);	
	}
	
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int t;
	
	while(true)
	{
		memset(dp,0,sizeof(dp)); 
		cin >> t;
		if(!t) break;
		
		cout << go(t, 0) << '\n';
			
	};
	
	return 0;
}