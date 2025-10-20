#include <bits/stdc++.h>

using namespace std;

int go (int cnt, long long num, long long limit)
{
	int ret = 1e9;
	if(num == limit)
	{
		return cnt;
	}
	if(num * 2 <= limit)
		ret = min(ret,go(cnt+1, num*2, limit));
	if(num*10 + 1 <= limit)
		ret = min(ret,go(cnt+1, num*10 + 1, limit));	
	
	return ret;
}

int main()
{
	long long num, limit;
	cin >> num >> limit;
	int ret = go(1,num,limit);
	cout << (ret == 1e9 ? -1 : ret);
	return 0;
}