#include <string>
#include <vector>
#include <queue>

using namespace std;

int dy[4] = {0, 1, 0, -1}, dx[4] = {1, 0, -1, 0};

vector<vector<pair<int,int>>> bfs(const vector<vector<int>>& vv)
{
    vector<vector<bool>> visited(vv.size(), vector<bool>(vv.size(), false));
    vector<vector<pair<int,int>>> vvp;
    for(int i=0; i<vv.size(); i++)
    {
        for(int j=0; j<vv.size(); j++)
        {
            if(visited[i][j] || vv[i][j]) continue;
            queue<pair<int,int>> q;
            vector<pair<int,int>> vp;
            visited[i][j] = true;
            vp.push_back({i, j});
            q.push({i, j});
            while(q.size())
            {
                auto p = q.front() ; q.pop();
                for(int n=0; n<4; n++)
                {
                    int ny = p.first + dy[n], nx = p.second + dx[n];
                    if(ny >= 0 && ny < vv.size() && nx >= 0 && nx < vv.size() && !vv[ny][nx] && !visited[ny][nx])
                    {
                        visited[ny][nx] = true;
                        vp.push_back({ny, nx});
                        q.push({ny, nx});
                    }
                }
            }
            vvp.push_back(vp);
        }
    }
    return vvp;
}

vector<vector<int>> rotateTable(const vector<vector<int>>& table)
{
    vector<vector<int>> result(table.size(), vector<int>(table.size(), 0));
    
    for(int i=0; i<table.size(); i++)
    {
        for(int j=0; j<table.size(); j++)
        {
            result[j][table.size() - 1 - i] = table[i][j];
        }
    }
    return result;
}

int check(vector<vector<int>>& table, vector<bool>& visited, const vector<vector<pair<int,int>>>& blanks, const vector<vector<pair<int,int>>>& pieces)
{
    vector<bool> pvisited(pieces.size(), false); // 같은 이터레이션에서 사용한 퍼즐 중복 사용 방지
    int ret = 0;
    for(int i=0; i<visited.size(); i++)
    {
        if(!visited[i])
        {
            for(int j=0; j<pieces.size(); j++)
            {
                if(pvisited[j]) continue;
                if(blanks[i].size() != pieces[j].size()) continue;
                bool same = true;
                int y = blanks[i][0].first - pieces[j][0].first;
                int x = blanks[i][0].second - pieces[j][0].second;
                for(int k=1; k<pieces[j].size(); k++)
                {
                    if(y != blanks[i][k].first - pieces[j][k].first
                      || x != blanks[i][k].second - pieces[j][k].second)
                    {
                        same = false;
                        break;
                    }
                }
                if(same)
                {
                    visited[i] = true;
                    pvisited[j] = true;
                    ret += blanks[i].size();
                    for(auto p : pieces[j])
                    {
                        table[p.first][p.second] = 1; // 사용한 퍼즐은 소멸처리
                    }
                    break;
                }
            }
        }
    }
    
    
    return ret;
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int answer = 0;
    for(int i=0; i<table.size(); i++)
    {
        for(int j=0; j<table.size(); j++)
        {
            table[i][j] = table[i][j] == 1 ? 0 : 1;
        }
    }
    vector<vector<pair<int,int>>> pieces = bfs(table);
    vector<vector<pair<int,int>>> blanks = bfs(game_board);
    vector<bool> visited(blanks.size(), false); // 이미 채운 빈칸 중복 채우기 방지
    answer += check(table, visited, blanks, pieces);
    for(int i=0; i<3; i++)
    {
        table = rotateTable(table); // 회전한 테이블 저장
        pieces = bfs(table); // 사용한 퍼즐 제외 다시 조각을 구성한다
        answer += check(table, visited, blanks, pieces);
    }
    return answer;
}

/*
알고리즘
1. 퍼즐 조각을 떼넨 목록을 만든다.
 - bfs를 이용한다. 
 - 1을 0으로, 0을 1로 만들어서 custom bfs 함수에 넣어야 한다(2번과 같은 함수를 쓰기 위해)
2. 빈 칸 목록을 만든다.
 - bfs를 이용한다.
3. 퍼즐 조각 하나하나 빈 칸과 비교한다.
3-1. 맞으면 해당 빈칸과 퍼즐을 사용했다는 표시를 한다. 
  - 맞추는 기준 : 탐색 순서가 같은 배열이 존재하는가? == 각 칸의 차가 같은가?
3-2. 퍼즐 조각을 돌리며 위 과정을 반복한다
  - 돌리는 방법 : 테이블 자체를 돌려버린다.
*/