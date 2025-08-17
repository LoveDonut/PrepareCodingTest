#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9;

vector<vector<int>> dp(9);

void makeN(int n)
{
    int num = n;
    for(int i=1; i<=8; i++)
    {
        dp[i].push_back(num);
        num = num*10 + n;
    }
}
int go(int number, int count)
{
    if(find(dp[count].begin(), dp[count].end(), number) != dp[count].end()) return count;
    count++;
    if(count > 8) return -1;
    for(int i=1; i<count; i++)
    {
        for(int a : dp[i])
        {
            for(int b : dp[count-i])
            {
                dp[count].push_back(a+b);
                dp[count].push_back(a*b);
                if(a%b == 0 && a/b != 0)
                {
                    dp[count].push_back(a/b);                    
                }
                if(a-b > 0)
                {
                    dp[count].push_back(a-b);                    
                }
            }
        }
    }
    return go(number, count);
}

using namespace std;

int solution(int N, int number) {

    makeN(N);
    
    return go(number, 1);
}