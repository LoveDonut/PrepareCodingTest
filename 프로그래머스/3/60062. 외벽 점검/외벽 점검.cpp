#include <bits/stdc++.h>

using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = 1e9, weakLength = weak.size();
    
    sort(dist.begin(), dist.end());
    
    for(int i=0; i<weakLength; i++)
    {
        weak.push_back(weak[i] + n);
    }
    
    do {
        for(int i=0; i<weakLength; i++)
        {
            int cnt = 0, start = weak[i], distIdx = 0, weakIdx = i;
            while(distIdx < dist.size() && cnt < weakLength) 
            {
                if(start <= weak[weakIdx] && weak[weakIdx] <= start + dist[distIdx])
                {
                    cnt++;
                    weakIdx++;
                }
                else
                {
                    distIdx++;
                    start = weak[weakIdx];
                }
            }
            if(cnt >= weakLength)
            {
                answer = min(answer, distIdx + 1);
            }
        }
    } while(next_permutation(dist.begin(), dist.end()));
    
    return answer == 1e9? -1 : answer;
}