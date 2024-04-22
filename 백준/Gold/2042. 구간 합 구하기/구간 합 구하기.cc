#include<bits/stdc++.h>

#define ll long long

using namespace std;

ll n, m, k;
vector<ll> numbers(1,0);
ll tree[1000001];

void Update(int idx, ll diff)
{
	while(idx <= n)
	{
		tree[idx] += diff;
		idx += (idx & -idx);
	}
}

ll Sum(int idx)
{
	ll ret = 0;
	while(idx > 0)
	{
		ret += tree[idx];
		idx -= (idx & -idx);
	}
	
	return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m >> k;
	for(int i=0; i<n; i++)
	{
		ll tmp;
		cin >> tmp;
		numbers.push_back(tmp);
	}
	
	for(int i=1; i<=n; i++)
	{
		Update(i, numbers[i]);
	}
	
	for(int i=0; i<m+k; i++)
	{
		ll a, b, c;
		cin >> a >> b >> c;
		if(a==1)
		{
			Update(b, c- numbers[b]);
			numbers[b] = c;
		}
		else
		{
			cout << Sum(c) - Sum(b-1) << '\n';
		}
	}
}