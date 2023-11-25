/*
문제
수빈이는 동생과 숨바꼭질을 하고 있다.
수빈이는 현재 점 N(0 ≤ N ≤ 100,000)에 있고, 동생은 점 K(0 ≤ K ≤ 100,000)에 있다.
수빈이는 걷거나 순간이동을 할 수 있다. 만약, 수빈이의 위치가 X일 때 걷는다면 1초 후에 X-1 또는 X+1로 이동하게 된다.
순간이동을 하는 경우에는 1초 후에 2*X의 위치로 이동하게 된다.

수빈이와 동생의 위치가 주어졌을 때, 수빈이가 동생을 찾을 수 있는 가장 빠른 시간이 몇 초 후인지 구하는 프로그램을 작성하시오.

입력
첫 번째 줄에 수빈이가 있는 위치 N과 동생이 있는 위치 K가 주어진다. N과 K는 정수이다.

출력
수빈이가 동생을 찾는 가장 빠른 시간을 출력한다.

예제 입력 1 
5 17
예제 출력 1 
4
힌트
수빈이가 5-10-9-18-17 순으로 가면 4초만에 동생을 찾을 수 있다.
*/

#include <iostream>
#include <queue>
using namespace std;

int BFS(int from, int destination);

int main(void){
    ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

    int from, to;
    cin >> from >> to;

    cout << BFS(from, to) << '\n';

    return 0;
}

int BFS(int from, int destination) {
    int result = 0;
    int distance = (destination - from);
    bool visited[distance * 2] = {false,};
    queue<int> path;
    
    visited[0] = true;

    cout << distance << endl;

    if (from != destination) {
        path.push(from);
    }

    while (!path.empty()) {
        int spot = path.front();
        int right = (spot + 1);
        int left = (spot - 1);
        int teleport = (spot * 2);
        path.pop();

        result++;

        if (right == destination || left == destination || teleport == destination) {
            break;
        }

        if (!visited[teleport - from]) {
            if (destination - teleport < destination - right) {
                path.push(teleport);
                visited[teleport - from] = true;
            } else if (destination - teleport > destination - left) {

            }
        }

        // walk left
        if (right < destination && !visited[right - from]) {
            path.push(right);
            visited[right - from] = true;
        }

        // walk right
        if (left > from && !visited[left - from]) {
            path.push(left);
            visited[left - from] = true;
        }

        cout << "L : " << left << " R : " << right << " T : " << teleport << endl;
        cout << result << " : " ;
        for (int k = 0; k < distance * 2; k++) {
            if (k == distance) {
                cout << "D";
            } else if (k == spot) {
                cout << "S";
            } else {
                cout << visited[k];
            }
        }
        cout << endl;

        if (result > 20) break;
    }

    return result;
}