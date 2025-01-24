#include <bits/stdc++.h>
#define INF 1e9

using namespace std;

queue<pair<int,int>> virus;
int maps[8][8];
int visited[8][8];
int safe, ret, N, M;
int dy[4] = {0,0,1,-1};
int dx[4] = {1,-1,0,0};

void Spread(int safe){
	fill(visited[0],visited[0] + 64,0);
	queue<pair<int,int>> q = virus;
	int y,x, ny, nx;
	
	while(q.size()){
		y = q.front().first;
		x = q.front().second; q.pop();
		
		for(int i=0; i<4; i++){
			ny = y + dy[i];
			nx = x + dx[i];
			
			if(ny >= 0 && nx >= 0 && ny < N && nx < M && !visited[ny][nx] && !maps[ny][nx]){
				visited[ny][nx] = 1;
				q.push({ny,nx});
				safe--;
			}
		}
	}
	ret = max(ret, safe);
}

void MakeWalls(int y, int x, int num, int safe){

	if(num == 3){
		Spread(safe);
		return;		
	}
	
	for(int ny=y; ny<N; ny++){
		for(int nx=0; nx<M; nx++){
			if(!maps[ny][nx]){
				maps[ny][nx] = 1;
				MakeWalls(ny,nx,num+1, safe);
				maps[ny][nx] = 0;
			}
		}
	}
}



int main(){
	cin >> N >> M;
	int tmp, safe = N*M - 3; //벽 3개 추가할 예정
	
	for(int y=0;y<N;y++){
		for(int x=0; x<M; x++){
			cin >> tmp;
			maps[y][x] = tmp;
			if(tmp){
				safe--;
				if(tmp == 2)
					virus.push({y,x});
			}
		}
	}
	
	for(int y=0; y<N; y++){
		for(int x=0; x<M; x++){
			if(!maps[y][x]){
				maps[y][x] = 1;
				MakeWalls(y,x,1, safe);
				maps[y][x] = 0;
			}
		}
	}
	
	cout << ret;
	
    return 0;
}
