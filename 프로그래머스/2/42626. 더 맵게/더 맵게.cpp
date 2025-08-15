#include <string>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;



int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(int i : scoville)
    {
        pq.push(i);
    }
    
    while(pq.size() > 1)
    {
        if(pq.top() >= K)
        {
            break;
        }
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        pq.push(a + 2*b);
        answer++;
    }
    return pq.top() >= K ? answer : -1;
}