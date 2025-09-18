#include <bits/stdc++.h>

using namespace std;

vector<int> psum;

void update(int idx, int num)
{
	while(idx < psum.size())
	{
		psum[idx] += num;
		idx += idx & -idx;	
	}	
}

int sum(int idx)
{
	int ret = 0;
	while(idx > 0)
	{
		ret += psum[idx];
		idx -= idx & -idx; 
	}
	return ret;
}

int subQuery(int left, int right)
{
	return sum(right) - sum(left-1);
}

int main()
{
	int n, s, ret = 1e9;
	cin >> n >> s;
	psum.resize(n+1, 0);
	vector<int> v(1,0);
	int left = 1, right = 1;
	for(int i=0; i<n; i++)
	{
		int a;
		cin >> a;
		v.push_back(a);
		update(i+1, a);
	}
	if(subQuery(1, n) < s)
	{
		cout << 0;
		return 0;
	}
	
	while(left <= right && right <= n)
	{
		if(subQuery(left, right) >= s)
		{
			ret = min(ret, right - left + 1);
			left++;
		}
		else
		{
			right++;
		}
	}
	if(ret == 1e9)
	{
		cout << 0;
	}
	else
	{
		cout << ret;
	}
	return 0;
}