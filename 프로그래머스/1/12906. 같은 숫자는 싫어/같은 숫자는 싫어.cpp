#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    stack<int> st;
    st.push(arr[0]);
    for(int i=1; i<arr.size(); i++)
    {
        if(st.top() != arr[i])
        {
            st.push(arr[i]);
        }
    }
    while(st.size())
    {
        answer.push_back(st.top());
        st.pop();
    }
    reverse(answer.begin(), answer.end());
    
    return answer;
}