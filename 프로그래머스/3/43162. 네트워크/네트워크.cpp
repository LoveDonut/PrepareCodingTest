#include <string>
#include <vector>

using namespace std;

vector<int> visited;

void dfs(int target, int n, vector<vector<int>>& computers)
{
    for(int i=0; i<n; i++)
    {
        if(!visited[i] && computers[target][i])
        {
            visited[i] = 1;
            dfs(i, n, computers);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    visited.resize(n, 0);
    
    for(int i=0; i<n; i++)
    {
        if(!visited[i])
        {
            dfs(i, n, computers);
            answer++;
        }
    }
    
    return answer;
}