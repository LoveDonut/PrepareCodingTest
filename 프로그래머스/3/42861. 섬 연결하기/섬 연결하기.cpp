#include <bits/stdc++.h>

using namespace std;

int parent[101];

int findParent(int a)
{
    if(parent[a] == a) return a;
    return parent[a] = findParent(parent[a]);
}

void makeUnion(int a, int b)
{
    int pa = findParent(a);
    int pb = findParent(b);
    if(pa < pb)
    {
        parent[pa] = pb;
    }
    else
    {
        parent[pb] = pa;
    }
}

bool isUnion(int a, int b)
{
    return findParent(a) == findParent(b);
}

bool cmp(vector<int> a, vector<int> b)
{
    return a[2] < b[2];
}
int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    sort(costs.begin(), costs.end(), cmp);
    for(int i=0; i<n; i++)
    {
        parent[i] = i;
    }
    for(vector<int> v : costs)
    {
        if(!isUnion(v[0], v[1]))
        {
            answer += v[2];
            makeUnion(v[0],v[1]);
        }
    }
    
    return answer;
}