#include <iostream>
#include <stack>

using namespace std;

char yard[251][251];
int visited[251][251];
int R,C;

// 살아남은 양과 늑대의 수
int sheep, wolf;

// 영역 안에서의 양과 늑대의 수
int s, w;

void DFS(int x, int y);

int main(){
    cin >> R >> C;

    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cin >> yard[i][j];
        }
    }

    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if(visited[i][j]!=1 && yard[i][j]!='#'){    // 방문되지 않았고 울타리가 아닌 곳부터 탐색시작
                // 영역이 바뀌었으므로 양과 늑대 수 초기화
                s=0;
                w=0;
                DFS(i, j);
                if(s > w) {
                    sheep += s;
                }        
                else {
                    wolf += w;
                }
            }
        }
    }

    cout << sheep << " " << wolf;

}

void DFS(int x, int y){
    
    visited[x][y] = 1;

    if(yard[x][y]=='v'){  // 늑대
        w++;
    }
    if(yard[x][y]=='o'){  // 양
        s++;
    }

    int dr[4] = {-1,1,0,0};
    int dc[4] = {0,0,1,-1};

    for(int i=0; i<4; i++){
        int nr = x + dr[i];
        int nc = y + dc[i];
        
        if(nr>-1&&nc>-1 && nr<R&&nc<C && visited[nr][nc]!=1){
            if(yard[nr][nc]!='#'){          // 울타리 안의 영역만 재귀적으로 호출하며 검사하게 됨. 
                DFS(nr, nc);
            }
        }
    }

    
}