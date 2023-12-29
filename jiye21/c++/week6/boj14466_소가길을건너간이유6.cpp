/*

농장 바깥에 높은 울타리
N*N 작은 정사각형 목초지
K마리의 소
R개의 길
일반적으로 인접한 목초지 사이는 자유롭게 이동가능하지만,
길이 존재하는 인접한 목초지는 길을 건너야 한다. 

길을 건너지 않으면 만나지 못하는 소의 쌍 구하기

소가 n마리이면 소는 nC2쌍, n!/2!(n-2)!이다. n*(n-1)/2

길의 좌푯값을 덮어쓰는 문제를 해결하자. 한 좌표에서 길이 여러 갈래 나 있을 경우가 존재. 

*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n,k,r;

// r, c, nr, nc
int field[101][101][101][101];

int moo[101][101];

int cnt = 0;

int moo_all = 0;

// 매개변수 좌표 기준 뒷 좌표들만 탐색하면 된다. 
void BFS(int x, int y){
    int r,c;
    int dr[4] = {-1,1,0,0};
    int dc[4] = {0,0,1,-1};
    int visited[101][101] = {0,};

    queue<pair<int,int>> q;
    q.push({x,y});
    visited[x][y] = 1;

    while(!q.empty()){
        r=q.front().first;
        c=q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            

            if(nr>=1&& nc>=1 && nr<=n && nc<=n &&
             visited[nr][nc]!=1 && 
             field[r][c][nr][nc] != 1 && field[nr][nc][r][c] != 1){
                q.push({nr,nc});
                visited[nr][nc] = 1;
                
                // 이동한 곳에 소가 있으면 체크
                if(moo[nr][nc] == 1){
                    cnt++;
                }
            }
        }


    }

}

int main(){
    cin >> n >> k >> r;

    // 길(이동 불가한 위치) 저장
    for(int i=0; i<r; i++){
        int a,b,x,y;
        cin >> a >> b >> x >> y;

        field[a][b][x][y] = 1;
        field[x][y][a][b] = 1;
    }

    // 소의 위치 저장
    for(int i=0; i<k; i++){
        int x,y;
        cin >> x >> y;

        moo[x][y] = 1;
        moo_all++;      // 입력 받으면서 소의 마릿수 세어줌
    }

    for(int i=0; i<101; i++){
        for(int j=0; j<101; j++){
            if(moo[i][j]==1){
                BFS(i,j);
                moo[i][j] = 0;      // 탐색한 소는 더이상 만날 필요 없음            
            }
        }
    }

    

    // 모든 소에서 만난 소들을 빼 만나지 못한 소 출력
    cout << moo_all*(moo_all-1)/2 - cnt;

}