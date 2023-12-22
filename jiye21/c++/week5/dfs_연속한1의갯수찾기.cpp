/*
 N*N크기의 배열이 주어졌을때 1의 개수는 몇개인지 세어보기 dfs를 이용해서
 하나의 시작 1로 부터 붙어져 있는 연속된 1의 개수 세어보기 => 2, 13이 답이 됨.

7
0000011
0000000
0011100
0010111
0110010
0011100
0000000
*/

#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int map[10][10];

int DFS(int i, int j, int N);

int main(){
    int N;
    cin >> N;
    cin.ignore();

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
                cout << DFS(i ,j, N);
                cout << endl;
            }
        }
    }

}

int DFS(int i, int j, int N){
    stack<pair<int,int>> stack;
    stack.push({i,j});
    map[i][j] = 0;
    
    int cnt = 1;

    while(!stack.empty()){
        int r = stack.top().first;
        int c = stack.top().second;
        stack.pop();

        int dr[4] = {-1,1,0,0};
        int dc[4] = {0,0,1,-1};

        for(int i=0;i<4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr > -1 && nc > -1 && nr < N && nc < N){
                if(map[nr][nc]==1){
                    map[nr][nc] = 0;
                    stack.push({nr,nc});
                    cnt++;
                }
            }
        }

    }

    return cnt;
}