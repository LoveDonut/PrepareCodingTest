#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end());
    for(int i=0; i<=citations.size(); i++)
    {
        int count = 0;
        while(count < citations.size() && citations[count] < i)
        {
            count++;
        }
        if(count <= i && citations.size() - count >= i)
        {
            answer = i;
        }
    }
    return answer;
}
// 0 1 3 5 6