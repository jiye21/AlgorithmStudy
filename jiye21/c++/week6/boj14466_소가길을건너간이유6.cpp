/*

농장 바깥에 높은 울타리
N*N 작은 정사각형 목초지
K마리의 소
R개의 길
일반적으로 인접한 목초지 사이는 자유롭게 이동가능하지만,
길이 존재하는 인접한 목초지는 길을 건너야 한다. 

길을 건너지 않으면 만나지 못하는 소의 쌍 구하기

정점이 n개이면 간선은 유방향 그래프에서 n*(n-1)개이다. (자기자신을 제외한 다른 모든 정점으로 이동가능)
무방향 그래프에서는 왕복을 제외하므로 n*(n-1)/2개이다. 

길의 좌푯값을 덮어쓰는 문제를 해결하자. 한 좌표에서 길이 여러 갈래 나 있을 경우가 존재. 

*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n,k,r;

// [x][y]에 어떤 좌표값이 들어 있으면 그 좌표로는 이동불가
//vector<vector<pair<int,int>>> field(101, vector<pair<int,int>> (101));
int field[101][101][101][101];

int moo[101][101];

int cnt = 0;

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
            

            if(nr>0&& nc>0 && nr<101 && nc<101 &&
             visited[nr][nc]!=1 && 
             field[r][c].first != nr && field[r][c].second != nc){
                q.push({nr,nc});
                visited[nr][nc] = 1;
                
                // 소가 서로 만났으면 체크
                if(nr>x && nc>y && moo[nr][nc]==1){
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

        field[a][b].first = x;
        field[a][b].second = y;
        field[x][y].first = a;
        field[x][y].second = b;
    }

    // 소의 위치 저장
    for(int i=0; i<k; i++){
        int x,y;
        cin >> x >> y;

        moo[x][y] = 1;
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(moo[i][j]==1){
                BFS(i,j);
            }
        }
    }

    // 모든 경우의 수에서 만난 소들을 빼 만나지 못한 소 출력
    cout << n*(n-1)/2 - cnt;

}