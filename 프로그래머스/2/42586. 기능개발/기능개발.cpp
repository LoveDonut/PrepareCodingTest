#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int before = 0;
    for(int i=0; i<progresses.size(); i++)
    {
        int time = (100 - progresses[i]) / speeds[i];
        if((100 - progresses[i]) % speeds[i] != 0)
        {
            time++;
        }
        if(time <= before)
        {
            answer[answer.size() - 1]++;
        }
        else
        {
            answer.push_back(1);            
            before = time;
        }
    }
    return answer;
}