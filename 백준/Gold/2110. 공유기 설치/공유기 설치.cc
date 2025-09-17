#include <bits/stdc++.h>

using namespace std;

vector<int> v;

bool check(int mid, int c)
{
	int count = 1;
	int idx = 0;
	for(int i=1; i<v.size(); i++)
	{
		if(v[i] - v[idx] >= mid)
		{
			count++;
			idx = i;
		}
	}
	
	return count >= c;
}

int main()
{
	int n, c, answer = 0;
	cin >> n >> c;
	
	for(int i=0; i<n; i++)
	{
		int a;
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());	
	int left = 1, right = v[v.size()-1];

	while(left <= right)
	{
		int mid = (left + right) / 2;
		if(check(mid, c))
		{
			answer = mid;
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	cout << answer;
	return 0;
}
