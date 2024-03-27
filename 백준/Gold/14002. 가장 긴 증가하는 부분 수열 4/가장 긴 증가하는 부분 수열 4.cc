#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    
    int N, num, maxLength = 0, maxIdx = 0;
    cin >> N;
    vector<vector<int>> numlists(N);
    vector<int> numbers(N);
    for(int i=0; i<N; i++)
    {
    	cin >> numbers[i];
    	numlists[i] = {numbers[i]};
    	
    	for(int j=0; j<i; j++)
    	{
    		if(numbers[j] < numbers[i] && numlists[j].size() + 1 > numlists[i].size())
    		{
    			vector<int> v = numlists[j];
    			v.push_back(numbers[i]);
    			numlists[i] = v;
			}
			if(maxLength < numlists[i].size())
			{
				maxLength = numlists[i].size();
				maxIdx = i;
			}
		}
	}

	cout << numlists[maxIdx].size() << '\n';
	
	for(int i : numlists[maxIdx])
	{
		cout << i << ' ';
	}
    
	return 0;
}