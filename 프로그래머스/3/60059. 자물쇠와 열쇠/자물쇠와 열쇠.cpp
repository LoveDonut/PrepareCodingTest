#include <bits/stdc++.h>

using namespace std;

void RotateKey(vector<vector<int>>& key)
{
    int m = key[0].size();
    vector<vector<int>> tmp = key;
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<m; j++)
        {
            key[i][j] = tmp[m-1-j][i];
        }
    }
}

bool IsOpen(vector<vector<int>> key, vector<vector<int>> lock, int holeCnt)
{
    int m = key[0].size(), n = lock[0].size();
    for(int ly=1-m;ly<n;ly++)
    {
        for(int lx=1-m;lx<n;lx++)
        {
            bool isOpen = true;
            int cnt = 0;
            for(int ky = 0; ky < m; ky++)
            {
                for(int kx = 0; kx < m; kx++)
                {
                    if(ly+ky < 0 || lx + kx < 0 || ly + ky >= n || lx + kx >= n) continue;
                    if(key[ky][kx] == lock[ly+ky][lx+kx])
                    {
                        isOpen = false;
                        break;
                    }
                    else if(!lock[ly+ky][lx+kx])
                    {
                        cnt++;
                    }
                }
                if(!isOpen)
                {
                    break;
                }
            }
            if(isOpen && cnt == holeCnt)
            {
                return true;
            }
        }
    }
    
    return false;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    int holeCnt = 0, n = lock[0].size();
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(!lock[i][j])
            {
                holeCnt++;
            }
        }
    }
    
    for(int i=0; i<4; i++)
    {        
        if(IsOpen(key,lock, holeCnt))
        {
            answer = true;
            break;
        }

        RotateKey(key);
    }
    return answer;
}