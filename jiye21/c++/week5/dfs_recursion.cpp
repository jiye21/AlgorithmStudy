#include <iostream>
#include <string>

using namespace std;

int map[10][10];
int cnt = 0;

void DFS(int x, int y, int N);

int main(){
    int N;
    cin >> N;
    for(int i=0; i<N; i++){
        string row;
        cin >> row;
        for(int j=0; j<N; j++){
            map[i][j] = row[j]-'0';
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(map[i][j]==1){
                cnt = 0;
                DFS(i,j,N);
                cout << cnt << endl;
            }
        }
    }


}

void DFS(int x, int y, int N){
    int dr[4] = {-1,1,0,0};
    int dc[4] = {0,0,1,-1};

    int r = x;
    int c = y;

    map[r][c]=0;
    cnt++;

    for(int i=0; i<N; i++){
        int nr = r + dr[i];
        int nc = c + dc[i];

        if(nr<0||nc<0 || nr>=N||nc>=N) continue;

        if(map[nr][nc]==0) continue;

        DFS(nr,nc,N);
    }

}