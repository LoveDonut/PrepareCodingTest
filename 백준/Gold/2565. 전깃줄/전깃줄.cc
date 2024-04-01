#include <bits/stdc++.h>

using namespace std;


int main()
{
	int N;
	vector<int> progression;
	vector<pair<int,int>> lines;
	
	cin >> N;
	
	for(int i=0; i<N; i++)
	{
		int a, b;
		cin >> a >> b;
		lines.push_back({a,b});
	}
	
	sort(lines.begin(), lines.end());
	
	for(pair<int,int> p : lines)
	{
		int order = lower_bound(progression.begin(), progression.end(), p.second) - progression.begin();
		
		if(order == progression.size())
		{
			progression.push_back(p.second);
		}
		else
		{
			progression[order] = p.second;
		}
	}
	
	cout << N - progression.size() << '\n';
		
	return 0;
}