#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

bool check(int n, int h, int mid, const vector<int>& lv, const vector<int>& hv)
{
	for(int i=1; i<=h; i++)
	{
		int low = n/2 - (int)(lower_bound(lv.begin(), lv.end(), i) - lv.begin());
		int high = n/2 - (int)(lower_bound(hv.begin(), hv.end(), h-i+1) - hv.begin());
		if((low + high) <= mid)
			return true;
	}
	return false;
}

int main()
{
	int n, h, cnt;
	vector<int> lv, hv;
	cin >> n >> h;
	for(int i=1; i<=n; i++)
	{
		int a;
		cin >> a;
		if(i % 2)
			lv.push_back(a);
		else
			hv.push_back(a);
	}
	sort(lv.begin(), lv.end());
	sort(hv.begin(), hv.end());
	int left = 0, right = n;
	while(left <= right)
	{
		int mid = (left + right) / 2;
		if(check(n, h, mid, lv, hv))
		{
			cnt = mid;
			right = mid-1;
		}
		else
		{
			left = mid+1;
		}
	}
	cout << cnt << ' ';
	// 모든 라인에 대해, cnt 만큼 나오는 것만 세기 
	int ret = 0;
	for(int i=1; i<=h; i++)
	{
		int low = n/2 - (int)(lower_bound(lv.begin(), lv.end(), i) - lv.begin());
		int high = n/2 - (int)(lower_bound(hv.begin(), hv.end(), h-i+1) - hv.begin());
		if((low + high) == cnt)
			ret++;
	}
	cout << ret;
	return 0;
}