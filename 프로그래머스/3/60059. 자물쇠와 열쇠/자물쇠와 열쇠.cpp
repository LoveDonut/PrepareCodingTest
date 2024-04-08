#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> RotateKey(vector<vector<int>> key)
{
    vector<vector<int>> rotatedKey(key[0].size(), vector<int>(key[0].size()));
    
    int m = key[0].size();
    
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<m; j++)
        {
            rotatedKey[i][j] = key[m-1-j][i];
        }
    }
    
    return rotatedKey;
}

bool IsOpen(vector<vector<int>> key, vector<vector<int>> lock, int holeNum)
{
    int m = key[0].size(), n = lock[0].size();
    
    // 열쇠를 자물쇠 왼쪽위부터, 오른쪽아래순으로 이동시킨다.
    for(int ly= 1-m; ly<n; ly++)
    {
        for(int lx= 1-m; lx<n; lx++)
        {
            int cnt = holeNum;
            bool isEnter = true;
            
            // 열쇠를 꽂아본다.
            for(int ky=0; ky<m; ky++)
            {
                for(int kx=0; kx<m; kx++)
                {
                    // 자물쇠의 범위를 벗어나는 영역이면 확인하지 않는다.
                    if(ly + ky < 0 || lx + kx < 0 || ly + ky >= n || lx + kx >= n) continue;
                    if((lock[ly+ky][lx+kx] + key[ky][kx]) != 1)
                    {
                        isEnter = false;
                        break;
                    }
                    if(lock[ly+ky][lx+kx] == 0 && key[ky][kx] == 1) 
                    {
                        cnt--;
                    }
                }
                if(!isEnter)
                {
                    break;
                }
            }
            
            // 열쇠가 꽂히면 문이 열린다.
            if(!cnt && isEnter)
            {
                return true;
            }
        }
    }
    return false;
}

// 홈의 개수를 세서 반환하는 함수
int CountHole(vector<vector<int>> lock)
{
    int cnt = 0;
    for(vector<int> v : lock)
    {
        for(int i : v)
        {
            if(!i)
            {
                cnt++;
            }
        }
    }
    return cnt;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    int holeNum = CountHole(lock);
    for(int i=0; i<4; i++)
    {
        if(IsOpen(key, lock, holeNum))
        {
            answer = true;
            break;
        }
        key = RotateKey(key);
    }
    
    return answer;
}