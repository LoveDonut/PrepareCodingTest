#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int S, C;
vector<ll> pas;

// mid의 크기로 파닭에 파를 다 넣을 수 있는지 확인하는 함수 
bool CanMakePadak(ll mid)
{
	ll cnt = 0;
	for (ll pa : pas)
	{
		cnt += pa / mid;
	}

	return cnt >= C;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	ll sum = 0;

	cin >> S >> C;

	for (int i = 0; i < S; i++)
	{
		ll tmp;
		cin >> tmp;
		sum += tmp;
		pas.push_back(tmp);
	}

	ll left = 1, right = 1e9, mid;

	// 이분탐색을 진행한다. 
	while (left <= right)
	{
		mid = (left + right) / 2;

		if (CanMakePadak(mid)) // 파닭제조가 가능하면, 제조가능한 파의 최대크기를 구한다. 
		{
			left = mid + 1;
		}
		else // 파닭제조가 불가능하면, 제조가능하도록 파의 크기를 조절한다. 
		{
			right = mid - 1;
			mid = right;
		}
	}

	cout << sum - C * mid;

	return 0;
}