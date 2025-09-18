#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    
    int N;
    vector<int> numlist;
    cin >> N;

    int maxLength = 0, maxValue = 0, prevValue = 0, num, curLength = 0;
    for(int i=0; i<N; i++)
    {
        cin >> num;
        int idx = lower_bound(numlist.begin(), numlist.end(), num) - numlist.begin();
        if(idx < numlist.size())
        {
            numlist[idx] = num;
        }
        else
        {
            numlist.push_back(num);
        }
    }

    cout << numlist.size() << '\n';
	return 0;
}