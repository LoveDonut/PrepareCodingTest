#include <string>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

ll check(ll mid, vector<int> times)
{
    ll ret = 0;
    for(int i : times)
    {
        ret += mid/(ll)i;
    }
    return ret;
}

long long solution(int n, vector<int> times) {
    long long answer = 0;
    sort(times.begin(), times.end());
    ll left = times[0], right = (ll)times[times.size()-1]*(ll)n;
    while(left <= right)
    {
        ll mid = (left + right) / 2;
        if(check(mid, times) >= n)
        {
            right = mid-1;
        }
        else
        {
            left = mid+1;
            answer = left;
        }
    }
    return answer;
}