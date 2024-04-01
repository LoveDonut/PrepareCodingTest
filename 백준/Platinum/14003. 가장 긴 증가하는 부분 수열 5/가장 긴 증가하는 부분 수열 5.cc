#include <bits/stdc++.h>

using namespace std;


int main()
{
	int N, length;
	vector<int> numbers, progression;
	stack<int> idxs;
	
	
	cin >> N;
	
	for(int i=0; i<N; i++)
	{
		int num, order;
		cin >> num;
		numbers.push_back(num);
		order = lower_bound(progression.begin(), progression.end(), num) - progression.begin();
		if(order == progression.size())
		{
			progression.push_back(num);
		}
		else
		{
			progression[order] = num;
		}
		
		idxs.push(order);
	}
	
	length = progression.size();

	cout << length << '\n';
	
	while(length)
	{
		if(idxs.top() == length - 1)
		{
			progression[length - 1] = numbers[idxs.size()-1]; length--;
		}
		idxs.pop();
	}
	
	for(int i : progression)
	{
		cout << i << ' ';
	}
	
	return 0;
}