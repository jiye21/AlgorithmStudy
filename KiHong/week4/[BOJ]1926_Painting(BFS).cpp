/*
문제
어떤 큰 도화지에 그림이 그려져 있을 때, 그 그림의 개수와, 그 그림 중 넓이가 가장 넓은 것의 넓이를 출력하여라. 단, 그림이라는 것은 1로 연결된 것을 한 그림이라고 정의하자. 가로나 세로로 연결된 것은 연결이 된 것이고 대각선으로 연결이 된 것은 떨어진 그림이다. 그림의 넓이란 그림에 포함된 1의 개수이다.

입력
첫째 줄에 도화지의 세로 크기 n(1 ≤ n ≤ 500)과 가로 크기 m(1 ≤ m ≤ 500)이 차례로 주어진다. 두 번째 줄부터 n+1 줄 까지 그림의 정보가 주어진다. (단 그림의 정보는 0과 1이 공백을 두고 주어지며, 0은 색칠이 안된 부분, 1은 색칠이 된 부분을 의미한다)

출력
첫째 줄에는 그림의 개수, 둘째 줄에는 그 중 가장 넓은 그림의 넓이를 출력하여라. 단, 그림이 하나도 없는 경우에는 가장 넓은 그림의 넓이는 0이다.

예제 입력 1 
6 5
1 1 0 1 1
0 1 1 0 0
0 0 0 0 0
1 0 1 1 1
0 0 1 1 1
0 0 1 1 1
예제 출력 1 
4
9
*/

#include <iostream>
#include <utility>
#include <vector>
#include <queue>
using namespace std;

void BFS(vector<vector<int>> map, int rows, int column, int *biggest, int *paintings);

int main(void) {
    ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

    int paintings = 0;
    int biggestPaint = 0;

    int rows, column;
    cin >> rows >> column;
    
    vector<vector<int>> museum(rows, vector<int>(column, 0));

    for (int k = 0; k < rows; k++) {
        for (int j = 0; j < column; j++) {
            cin >> museum[k][j];
        }
    }

    BFS(museum, rows, column, &biggestPaint, &paintings);

    cout << paintings << '\n';
    cout << biggestPaint << '\n';

    return 0;
}


// BFS 탐색
void BFS(vector<vector<int>> map, int rows, int column, int *biggest, int *paintings)
{
    int currentSize = 0;
    vector<vector<bool>> visited(rows, vector<bool>(column, 0));
    queue<pair<int,int>> path;

    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < column; col++) {
            // If on a visited node
            // Continue Search
            if (visited[row][col]) {
                continue;
            }

            // If the node is new, check for path
            visited[row][col] = true;

            // Abandoned the node, If it's untraceable
            if (map[row][col] == 0) {
                continue;
            }
            
            // Add current node
            path.push({row, col});
            currentSize = 1;
            (*paintings)++;

            while (!path.empty()) {
                pair<int, int> node = path.front();
                path.pop();

                // Check directions
                // check up
                int direction = node.first - 1;
                if (direction > -1 && !visited[direction][node.second] && map[direction][node.second] != 0) { 
                    visited[direction][node.second] = true;
                    path.push({direction, node.second});
                    currentSize++;
                }
                
                // check down
                direction = node.first + 1;
                if (direction < rows && !visited[direction][node.second] && map[direction][node.second] != 0) { 
                    visited[direction][node.second] = true;
                    path.push({direction, node.second});
                    currentSize++;
                }
                
                // check right
                direction = node.second + 1;
                if (direction < column && !visited[node.first][direction] && map[node.first][direction] != 0) { 
                    visited[node.first][direction] = true;
                    path.push({node.first, direction});
                    currentSize++;
                }
                
                // check left
                direction = node.second - 1;
                if (direction > -1 && !visited[node.first][direction] && map[node.first][direction] != 0) { 
                    visited[node.first][direction] = true;
                    path.push({node.first, direction});
                    currentSize++;
                }
            }

            // Find biggest painting
            if (currentSize > *biggest) {
                *biggest = currentSize;
            }
        }
    }
}