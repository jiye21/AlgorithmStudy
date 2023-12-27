#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int field [51][51];

int M,N,K;

void BFS(int i, int j);

int main(){
    int T;
    cin >> T;
    

    for(int i=0; i<T; i++){
        int bug = 0;
        cin >> M >> N >> K;

        for(int i=0; i<K; i++){
            int a, b;
            cin >> a >> b;
            field[b][a] = 1;      // 좌표 x,y 조심!!!
        }
        
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(field[i][j]==1){
                    BFS(i,j);
                    bug++;
                }
            }
        }

        cout << bug << endl;
    }

}

void BFS(int i, int j){
    queue<pair<int,int>> q;
    q.push({i, j});
    field[i][j] = 0;

    int dr[4] = {-1,1,0,0};
    int dc[4] = {0,0,1,-1};

    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr>-1&&nc>-1 && nr<N&&nc<M && field[nr][nc]==1){
                q.push({nr,nc});
                field[nr][nc] = 0;
            }
        }

    }
}