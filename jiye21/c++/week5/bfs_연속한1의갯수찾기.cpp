#include <iostream>
#include <queue>
#include <string>

using namespace std;

int map[10][10];
int dist[10][10];

void BFS(int i, int j, int N);

int main(){
    int N;
    cin >> N;

    for(int i=0; i<N; i++){
        string row;
        cin >> row;
        for(int j=0;j<N;j++){
            map[i][j] = row[j] - '0';
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(map[i][j]==1){
                BFS(i,j,N);
            }
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}

void BFS(int i, int j, int N){
    queue<pair<int,int>> q;
    q.push({i,j});
    dist[i][j] = 1;
    map[i][j]=0;

    int r, c;
    int dr[4] = {-1,1,0,0};
    int dc[4] = {0,0,1,-1};


    while(!q.empty()){
        r = q.front().first;
        c = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr>-1&&nr>-1 && nr<N&&nc<N){
                if(dist[nr][nc]==0 && map[nr][nc]==1){
                    dist[nr][nc] = dist[r][c] + 1;
                    map[nr][nc] = 0;
                    q.push({nr,nc});
                }
            }
        }   
    }
}