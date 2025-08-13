#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<pair<int,int>> q;
    for(int i=0; i<progresses.size(); i++)
    {
        q.push({progresses[i], speeds[i]});
    }
    while(q.size())
    {
        int sum = 0;
        int size = q.size();
        for(int i=0; i<size; i++)
        {
            pair<int,int> p = q.front();
            q.push({p.first + p.second, p.second});
            q.pop();
        }
        for(int i=0; i<size; i++)
        {
            if(q.front().first >= 100)
            {
                sum++;
                q.pop();
            }
        }
        if(sum > 0)
        {
            answer.push_back(sum);
        }
    }
    return answer;
}