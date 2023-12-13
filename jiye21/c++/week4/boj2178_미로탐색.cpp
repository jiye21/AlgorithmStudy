#include <iostream>
#include <queue>
#include <string>

using namespace std;

int maze[101][101];     // 미로
int dist[101][101];     // 시작 위치로부터 이동해온 칸수 기록

int main(){
    int N, M;
    cin >> N >> M;
    
    // maze 인덱스 : (0,0) ~ (N-1, M-1)
    for(int i=0; i<N; i++){
        string row;     // 행 입력
        cin >> row;

        for(int j=0; j<M; j++){
            maze[i][j] = row[j]-'0';  // 문자 형태를 숫자로 변환
        }
    }


    int r=0;
    int c=0;
    int dr[4] = {-1,1,0,0};
    int dc[4] = {0,0,1,-1};

    queue<pair<int,int>> q;     // 탐색 예정 좌표들이 담길 큐

    q.push({r,c});
    dist[r][c] = 1;           // 시작 좌표로부터 몇칸 이동해왔는지 기록, 현재는 시작위치라 1

    while(!q.empty()){
        r = q.front().first;    // 탐색할 기준좌표 (r,c)에 저장
        c = q.front().second;
        q.pop();
        maze[r][c] = 0;         // 현재 위치는 다시 돌아오지 않을 것이므로 벽으로 처리

        // 4방탐색
        for(int i=0; i<4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];

            if((nr > -1 && nr < N) && (nc > -1 && nc < M)){     // 미로 범위 안벗어나게 체크
                if(maze[nr][nc] != 0){      // 탐색한 곳이 벽이 아닐때                   
                    q.push({nr,nc});        // 탐색 예정
                    maze[nr][nc] = 0;       // 탐색한 곳을 재탐색하지 않도록 벽으로 처리
                    dist[nr][nc] = dist[r][c] + 1; // 이동한 칸수 기록                    
                }
            }
        }
        
    }

    cout << dist[N-1][M-1];

}