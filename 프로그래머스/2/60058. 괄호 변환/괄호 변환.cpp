#include <bits/stdc++.h>

using namespace std;

string answer = "";

bool IsRight(string s)
{
    stack<char> st;
    for(char c : s)
    {
        if(!st.size() || st.top() == ')' || st.top() == c)
        {
            st.push(c);
        }
        else
        {
            st.pop();
        }
    }
    if(st.size())
    {
        return false;
    }
    return true;
}

string MakeRight(string s)
{
    string ret = "";
    if(!s.size())
    {
        return ret;
    }
    
    int cntR = 0, cntL = 0, idx = 0;
    
    do
    {
        if(s[idx++] == '(')
        {
            cntR++;
        }
        else
        {
            cntL++;
        }
    } while(idx < s.size() && cntR != cntL);
    
    string u = s.substr(0, idx), v = s.substr(idx);
    
    cout << u << ", " << v << '\n';
    
    if(IsRight(u))
    {
        cout << u << "is Right\n";
        answer += u;
        ret = MakeRight(v);
    }
    else
    {
        answer += '(';
        answer += MakeRight(v);
        answer += ')';
        
        for(int i=1; i<u.size()-1; i++)
        {
            if(u[i] == '(')
            {
                answer += ')';
            }
            else
            {
                answer += '(';
            }
        }
    }
    
    return ret;
}

string solution(string p) {
    MakeRight(p);
    return answer;
}