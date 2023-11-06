/*
문제
두 마리의 백조가 호수에서 살고 있었다. 그렇지만 두 마리는 호수를 덮고 있는 빙판으로 만나지 못한다.

호수는 행이 R개, 열이 C개인 직사각형 모양이다. 어떤 칸은 얼음으로 덮여있다.

호수는 차례로 녹는데, 매일 물 공간과 접촉한 모든 빙판 공간은 녹는다. 두 개의 공간이 접촉하려면 가로나 세로로 닿아 있는 것만 (대각선은 고려하지 않는다) 생각한다.

아래에는 세 가지 예가 있다.

...XXXXXX..XX.XXX ....XXXX.......XX .....XX.......... 
....XXXXXXXXX.XXX .....XXXX..X..... ......X.......... 
...XXXXXXXXXXXX.. ....XXX..XXXX.... .....X.....X..... 
..XXXXX..XXXXXX.. ...XXX....XXXX... ....X......XX.... 
.XXXXXX..XXXXXX.. ..XXXX....XXXX... ...XX......XX.... 
XXXXXXX...XXXX... ..XXXX.....XX.... ....X............ 
..XXXXX...XXX.... ....XX.....X..... ................. 
....XXXXX.XXX.... .....XX....X..... ................. 
      처음               첫째 날             둘째 날
백조는 오직 물 공간에서 세로나 가로로만(대각선은 제외한다) 움직일 수 있다.

며칠이 지나야 백조들이 만날 수 있는 지 계산하는 프로그램을 작성하시오.

입력
입력의 첫째 줄에는 R과 C가 주어진다. 단, 1 ≤ R, C ≤ 1500.

다음 R개의 줄에는 각각 길이 C의 문자열이 하나씩 주어진다. '.'은 물 공간, 'X'는 빙판 공간, 'L'은 백조가 있는 공간으로 나타낸다.

출력
첫째 줄에 문제에서 주어진 걸리는 날을 출력한다.

예제 입력 1 
10 2
.L
..
XX
XX
XX
XX
XX
XX
..
.L
예제 출력 1 
3

예제 입력 2 
4 11
..XXX...X..
.X.XXX...L.
....XXX..X.
X.L..XXX...
예제 출력 2 
2

예제 입력 3 
8 17
...XXXXXX..XX.XXX
....XXXXXXXXX.XXX
...XXXXXXXXXXXX..
..XXXXX.LXXXXXX..
.XXXXXX..XXXXXX..
XXXXXXX...XXXX...
..XXXXX...XXX....
....XXXXX.XXXL...
예제 출력 3 
2
*/

#include <iostream>
#include <utility>
#include <vector>
#include <queue>
using namespace std;

#define MELT_FROM_FIRST_SWAN 0
#define MELT_FROM_SECOND_SWAN 1
#define MELT_FROM_WATER 2
#define VISITED 3
#define WATER 4


int totalIce = 0;

queue<pair<int,int>> waters;
vector<pair<int,int>> swans;

vector<queue<pair<int,int>>> path(2, queue<pair<int,int>>());
queue<pair<int,int>> waterPath;

int BFS(vector<vector<char>> map, int rows, int columns);

int main(void) {
    ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

    int row, column;
    cin >> row >> column;

    vector<vector<char>> lake(row, vector<char>(column, '.'));

    for (int k = 0; k < row; k++) {
        for (int j = 0; j < column; j++) {
            cin >> lake[k][j];
            if (lake[k][j] == 'L') {
                swans.push_back({k,j});
            }
            else if (lake[k][j] == '.') {
                waters.push({k,j});
            }
            else {
                totalIce++;
            }
        }
    }

    cout << BFS(lake, row, column) << '\n';

    return 0;
}

int BFS(vector<vector<char>> map, int rows, int columns) {
    int days = 1;
    int waterCount = waters.size();
    int directions[4][2] = { {-1,0}, {1,0}, {0,-1}, {0,1} };
    bool waterTouchSwan1 = false;
    bool waterTouchSwan2 = false;
    
    vector<vector<int>> visited(rows, vector<int>(columns, WATER));
    for (int k = 0; k < swans.size(); k++) {
        visited[swans[k].first][swans[k].second] = VISITED;
    }

    while (1) {
        vector<queue<pair<int,int>>> meltingPath(swans.size() + 1, queue<pair<int,int>>());

        for (int swan = 0; swan < swans.size(); swan++) {
            if (path[swan].empty()) {
                path[swan].push(swans[swan]);
            }
            
            while (!path[swan].empty()) {
                pair<int, int> node = path[swan].front();
                path[swan].pop();

                for (int k = 0; k < 4; k++) {
                    // Check directions
                    pair<int, int> direction(node.first + directions[k][0], node.second + directions[k][1]);

                    if (direction.first < rows && direction.first > -1 &&
                        direction.second < columns && direction.second > -1 &&
                        visited[direction.first][direction.second] != VISITED) {
                        // If node is water category
                        if (visited[direction.first][direction.second] == WATER) {
                            // If node is actual water
                            if (map[direction.first][direction.second] == '.') {
                                // Add new path
                                visited[direction.first][direction.second] = VISITED;
                                path[swan].push({direction.first, direction.second});
                            }
                            // If node is a melting point
                            else if (map[direction.first][direction.second] == 'X') {
                                visited[direction.first][direction.second] = swan;
                                meltingPath[swan].push({direction.first, direction.second});
                            }
                        }
                        // If swan touch water melting point
                        else if ((visited[direction.first][direction.second] == MELT_FROM_WATER)) {
                            if (swan == 0) waterTouchSwan1 = true;
                            else if (swan == 1) waterTouchSwan2 = true;
                            if (waterTouchSwan1 && waterTouchSwan2) {
                                return days;
                            }
                        }
                        // If node is other swan's melting point
                        // Means the swans will meet tomorrow
                        else if ((swan == MELT_FROM_FIRST_SWAN && visited[direction.first][direction.second] == MELT_FROM_SECOND_SWAN) ||
                                 (swan == MELT_FROM_SECOND_SWAN && visited[direction.first][direction.second] == MELT_FROM_FIRST_SWAN)) {
                            return days;
                        }
                    }
                }
            }
        }

        while (!waters.empty()) {
            if (visited[waters.front().first][waters.front().second] != VISITED) {
                waterPath.push(waters.front());
            }
            waters.pop();
        }

        while (!waterPath.empty()) {
            pair<int, int> node = waterPath.front();
            waterPath.pop();
            
            for (int k = 0; k < 4; k++) {
                // Check directions
                pair<int, int> direction(node.first + directions[k][0], node.second + directions[k][1]);

                if (direction.first < rows && direction.first > -1 &&
                    direction.second < columns && direction.second > -1 &&
                    visited[direction.first][direction.second] != VISITED) {
                    // If node is water category
                    if (visited[direction.first][direction.second] == WATER) {
                        // If node is actual water
                        if (map[direction.first][direction.second] == '.') {
                            // Add new path
                            visited[direction.first][direction.second] = VISITED;
                            waterPath.push({direction.first, direction.second});
                        }
                        // If node is a melting point
                        else if (map[direction.first][direction.second] == 'X') {
                            visited[direction.first][direction.second] = MELT_FROM_WATER;
                            meltingPath[MELT_FROM_WATER].push({direction.first, direction.second});
                        }
                    }
                    // If water touch swan's melting point
                    else if ((visited[direction.first][direction.second] != MELT_FROM_WATER)) {
                        // Escape if two touch point is connected
                        if (visited[direction.first][direction.second] == MELT_FROM_FIRST_SWAN) waterTouchSwan1 = true;
                        else if (visited[direction.first][direction.second] == MELT_FROM_SECOND_SWAN) waterTouchSwan2 = true;
                        if (waterTouchSwan1 && waterTouchSwan2) {
                            return days;
                        }
                    }
                }
            }
        }

        for (int k = 0; k < swans.size(); k++) {
            // if there's no ice to melt = the whole lake is melted
            totalIce -= meltingPath[k].size();

            while (!meltingPath[k].empty()) {
                path[k].push(meltingPath[k].front());
                meltingPath[k].pop();
            }
        }
        
        while (!meltingPath[MELT_FROM_WATER].empty()) {
            waterPath.push(meltingPath[MELT_FROM_WATER].front());
            meltingPath[MELT_FROM_WATER].pop();
            totalIce--;
        }

        if (totalIce < 1) {
            return days;
        }

        days++;
    }

    return days;
}