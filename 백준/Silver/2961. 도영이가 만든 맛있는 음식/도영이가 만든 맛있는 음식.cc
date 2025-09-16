#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n;
	vector<pair<int,int>> v;
	vector<int> ret;
	cin >> n;
	for(int i=0; i<n; i++)
	{
		int a,b;
		cin >> a >> b;
		v.push_back({a,b});
	}
	
	for(int i=0; i<(1<<n); i++)
	{
		int a = 1;
		int b = 0;
		int count = 0;
		for(int j=0; j<n; j++)
		{
			if(i & (1<<j))
			{
				count++;
				a *= v[j].first;
				b += v[j].second;
			}
		}
		if(count)
		{
			ret.push_back(abs(a-b));			
		}
	}
	
	sort(ret.begin(), ret.end());
	cout << ret[0];
	return 0;
}