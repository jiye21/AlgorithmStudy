#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int nums[6][6];
int visited[6][6];

vector<int> vec;


void DFS(int x, int y, int num, int depth);

int main(){

    for(int i=0;i<5;i++){
        for(int j=0; j<5; j++){
            cin >> nums[i][j];
        }
    }

    
    for(int i=0;i<5;i++){
        for(int j=0; j<5; j++){
            DFS(i, j, nums[i][j], 0);
        }
    }

    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());

    cout << vec.size();
}

void DFS(int x, int y, int num, int depth){
    if(depth==5) {
        vec.push_back(num);
        return;
    }

    int dr[4] = {-1,1,0,0};
    int dc[4] = {0,0,1,-1};

    int r = x;
    int c = y;

    for(int i=0; i<4; i++){
        int nr = r + dr[i];
        int nc = c + dc[i];

        if(nr>-1&&nc>-1 && nr<5&&nc<5){
            // 이동할 수 있는 칸이라면 한 뎁스 더 들어감
            DFS(nr, nc, num*10 + nums[nr][nc], depth+1);
        }
    }
}
