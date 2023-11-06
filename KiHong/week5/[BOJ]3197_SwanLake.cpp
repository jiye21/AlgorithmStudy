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
#define VISITED 2
#define WATER 3

int BFS(vector<vector<char>> map, vector<pair<int,int>> swans, int rows, int columns);

int main(void) {
    ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

    int row, column;
    cin >> row >> column;

    vector<pair<int,int>> swans;
    vector<vector<char>> lake(row, vector<char>(column, '.'));

    for (int k = 0; k < row; k++) {
        for (int j = 0; j < column; j++) {
            cin >> lake[k][j];
            if (lake[k][j] == 'L') {
                swans.push_back({k,j});
            }
        }
    }

    cout << BFS(lake, swans, row, column) << '\n';

    return 0;
}

int BFS(vector<vector<char>> map, vector<pair<int,int>> swans, int rows, int columns) {
    int days = 1;
    queue<pair<int,int>> path;
    vector<vector<int>> visited(rows, vector<int>(columns, WATER));
    for (int k = 0; k < swans.size(); k++) {
        visited[swans[k].first][swans[k].second] = VISITED;
    }

    while (1) {
        queue<pair<int,int>> meltingPath;
        
        cout << "====== Days : " << days << " ======" << endl;

        for (int swan = 0; swan < swans.size(); swan++) {
            pair<int,int> currentSwanPosition = swans[swan];

            if (path.empty()) {
                path.push(currentSwanPosition);
            }

            while (!path.empty()) {
                pair<int, int> node = path.front();
                path.pop();

                // Check up
                int direction = node.first - 1;
                if (direction > -1) {
                    // If node is water category
                    if (visited[direction][node.second] == WATER) {
                        // If node is actual water
                        if (map[direction][node.second] == '.') {
                            // Add new path
                            visited[direction][node.second] = VISITED;
                            path.push({direction, node.second});
                        }
                        // If node is a melting point
                        else if (map[direction][node.second] == 'X') {
                            visited[direction][node.second] = swan;
                            map[direction][node.second] = visited[direction][node.second] + '0';
                            meltingPath.push({direction, node.second});
                        }
                        // If node is another swan
                        else if (currentSwanPosition != swans[swan]) {
                            return days;
                        }
                    }
                    // If node is other swan's melting point
                    // Means the swans will meet tomorrow
                    else if ((visited[direction][node.second] == MELT_FROM_FIRST_SWAN && visited[node.first][node.second] == MELT_FROM_SECOND_SWAN) ||
                            (visited[direction][node.second] == MELT_FROM_SECOND_SWAN && visited[node.first][node.second] == MELT_FROM_FIRST_SWAN)) {
                        return days;
                    }
                }
                
                // Check down
                direction = node.first + 1;
                if (direction < rows) {
                    // If node is water category
                    if (visited[direction][node.second] == WATER) {
                        // If node is actual water
                        if (map[direction][node.second] == '.') {
                            // Add new path
                            visited[direction][node.second] = VISITED;
                            path.push({direction, node.second});
                        }
                        // If node is a melting point
                        else if (map[direction][node.second] == 'X') {
                            visited[direction][node.second] = swan;
                            map[direction][node.second] = visited[direction][node.second] + '0';
                            meltingPath.push({direction, node.second});
                        }
                        // If node is another swan
                        else if (currentSwanPosition != swans[swan]) {
                            return days;
                        }
                    }
                    // If node is other swan's melting point
                    // Means the swans will meet tomorrow
                    else if ((visited[direction][node.second] == MELT_FROM_FIRST_SWAN && visited[node.first][node.second] == MELT_FROM_SECOND_SWAN) ||
                            (visited[direction][node.second] == MELT_FROM_SECOND_SWAN && visited[node.first][node.second] == MELT_FROM_FIRST_SWAN)) {
                        return days;
                    }
                }

                // Check left
                direction = node.second - 1;
                if (direction > -1) {
                    // If node is water category
                    if (visited[node.first][direction] == WATER) {
                        // If node is actual water
                        if (map[node.first][direction] == '.') {
                            // Add new path
                            visited[node.first][direction] = VISITED;
                            path.push({node.first, direction});
                        }
                        // If node is a melting point
                        else if (map[node.first][direction] == 'X') {
                            visited[node.first][direction] = swan;
                            map[node.first][direction] = visited[node.first][direction] + '0';
                            meltingPath.push({node.first, direction});
                        }
                        // If node is another swan
                        else if (currentSwanPosition != swans[swan]) {
                            return days;
                        }
                    }
                    // If node is other swan's melting point
                    // Means the swans will meet tomorrow
                    else if ((visited[node.first][direction] == MELT_FROM_FIRST_SWAN && visited[node.first][node.second] == MELT_FROM_SECOND_SWAN) ||
                            (visited[node.first][direction] == MELT_FROM_SECOND_SWAN && visited[node.first][node.second] == MELT_FROM_FIRST_SWAN)) {
                        return days;
                    }
                }

                // Check right
                direction = node.second + 1;
                if (direction < columns) {
                    // If node is water category
                    if (visited[node.first][direction] == WATER) {
                        // If node is actual water
                        if (map[node.first][direction] == '.') {
                            // Add new path
                            visited[node.first][direction] = VISITED;
                            path.push({node.first, direction});
                        }
                        // If node is a melting point
                        else if (map[node.first][direction] == 'X') {
                            visited[node.first][direction] = swan;
                            map[node.first][direction] = visited[node.first][direction] + '0';
                            meltingPath.push({node.first, direction});
                        }
                        // If node is another swan
                        else if (currentSwanPosition != swans[swan]) {
                            return days;
                        }
                    }
                    // If node is other swan's melting point
                    // Means the swans will meet tomorrow
                    else if ((visited[node.first][direction] == MELT_FROM_FIRST_SWAN && visited[node.first][node.second] == MELT_FROM_SECOND_SWAN) ||
                            (visited[node.first][direction] == MELT_FROM_SECOND_SWAN && visited[node.first][node.second] == MELT_FROM_FIRST_SWAN)) {
                        return days;
                    }
                }
            }
        }

        days++;

        // if there's no ice to melt = the whole lake is melted
        if (meltingPath.empty()) {
            break;
        }

        while (!meltingPath.empty()) {
            path.push(meltingPath.front());
            meltingPath.pop();
        }
    }

    return days;
}