/*
문제
세준시에는 고층 빌딩이 많다. 세준시의 서민 김지민은 가장 많은 고층 빌딩이 보이는 고층 빌딩을 찾으려고 한다. 빌딩은 총 N개가 있는데, 빌딩은 선분으로 나타낸다. i번째 빌딩 (1부터 시작)은 (i,0)부터 (i,높이)의 선분으로 나타낼 수 있다. 고층 빌딩 A에서 다른 고층 빌딩 B가 볼 수 있는 빌딩이 되려면, 두 지붕을 잇는 선분이 A와 B를 제외한 다른 고층 빌딩을 지나거나 접하지 않아야 한다. 가장 많은 고층 빌딩이 보이는 빌딩을 구하고, 거기서 보이는 빌딩의 수를 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 빌딩의 수 N이 주어진다. N은 50보다 작거나 같은 자연수이다. 둘째 줄에 1번 빌딩부터 그 높이가 주어진다. 높이는 1,000,000,000보다 작거나 같은 자연수이다.

출력
첫째 줄에 문제의 정답을 출력한다.

예제 입력 1 
15
1 5 3 2 6 3 2 6 4 2 5 7 3 1 5
예제 출력 1 
7
예제 입력 2 
1
10
예제 출력 2 
0
예제 입력 3 
4
5 5 5 5
예제 출력 3 
2
예제 입력 4 
5
1 2 7 3 2
예제 출력 4 
4
예제 입력 5 
10
1000000000 999999999 999999998 999999997 999999996 1 2 3 4 5
예제 출력 5 
6
*/

#include <iostream>
#include <algorithm>
using namespace std;

int HighestBuilding(int buildings[], int number);

int main(void) {
    ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

    int number = 0;
    cin >> number;
    int buildings[number];

    for (int k = 0; k < number; k++) {
        cin >> buildings[k];
    }

    cout << HighestBuilding(buildings, number) << '\n';

    return 0;
}

int HighestBuilding(int buildings[], int number) {
    int maxView = 0;
    int buildingCount = number;
    int buildingView[number] = { 0, };

    for (int k = 0; k < buildingCount; k++) {
        double maxSlop = -1000000000;
        for (int j = k + 1; j < buildingCount; j++) {
            double slop = (double)(buildings[j] - buildings[k]) / (j - k);
            cout << "From " << k << "(Height=" << buildings[k] << ") to " << j << "(Height=" << buildings[j] << ") : " << maxSlop << ", " << slop << endl;
            // 현재 빌딩과 목표 빌딩이 서로 보이는 관계면 서로 보이는 빌딩 개수 증가
            if (slop > maxSlop) {
                buildingView[k]++;
                buildingView[j]++;
                maxSlop = slop;
                cout << "Current Building " << k << " View : " << buildingView[k] << ", Building on right " << j << " : " << buildingView[j] << endl;
            }
        }
    }

    for (int k = 0; k < buildingCount; k++) {
        cout << buildingView[k] << " ";
        maxView = max(maxView, buildingView[k]);
    }
    cout << endl;

    return maxView;
}