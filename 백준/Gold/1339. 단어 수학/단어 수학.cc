#include <bits/stdc++.h>

using namespace std;


int main()
{
	int n, ret = 0;
	cin >> n;
	vector<string> sv;
	set<char> cset;
	for(int i=0; i<n; i++)
	{
		string s;
		cin >> s;
		sv.push_back(s);
		for(char c : s)
			cset.insert(c);
	}
	for(int i=9; i>=0; i--)
	{
		char value = '\0';
		int sum = 0;
		for(char c : cset)
		{
			int num = 0;
			for(string s : sv)
			{
				for(int j=0; j<s.size(); j++)
				{
					if(s[j] == c)
						num += i * pow(10, s.size()-1-j);
				}
			}
			if(sum < num)
			{
				value = c;
				sum = num;
			}
		}
		if(value != '\0')
		{
			cset.erase(value);
			ret += sum;
			if(!cset.size()) break;
		}
	}
	cout << ret;
	return 0;
}