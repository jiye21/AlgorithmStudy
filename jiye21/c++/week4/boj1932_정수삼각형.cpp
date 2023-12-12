#include <iostream>
#include <algorithm>

using namespace std;

// 이차원 배열에 정수 삼각형을 저장한다. 풀기 쉽게 하기 위해 삼각형을 계단식으로 저장한다. 
// 배열의 범위 오류를 막기 위해(각 줄의 맨 왼쪽칸은 왼쪽 대각선 값이 존재하지 않아 접근하면 안됨)
// 각 줄의 맨 앞에 0 하나를 추가해 저장한다. 
//
// 삼각형을 줄 단위로 나누어 생각한다. 그러면 윗 줄에서 밑 줄로 내려올 때 밑 줄에서의 j번 칸까지의 최대 경로는
// 왼쪽 대각선인 dp[i-1][j-1], 바로 윗 칸(배열이 아닌 실제 삼각형에서는 오른쪽 대각선)인 dp[i-1][j]
// 둘 중 큰 것을 선택해 자신의 값을 더해주면 자신에 칸까지 오는 최대 경로이다. 


int tri[501][501];  // 배열을 0으로 초기화하기 위해 전역으로 선언

int main(){
    int n;
    cin >> n;

    for(int i = 0; i<n; i++){
        for(int j = 1; j<i+2; j++){
            cin >> tri[i][j];
        }
    }


    for(int i = 0; i<n; i++){
        for(int j = 1; j<i+2; j++){
            // 삼항 연산자 -> ?앞의 조건식이 참이면 콜론 앞의 값 반환, 거짓이면 뒤의 값 반환
            int greater = (tri[i-1][j-1] > tri[i-1][j]) ? tri[i-1][j-1] : tri[i-1][j] ;
            tri[i][j] += greater;
        }
    }

    // 마지막줄에 저장된 값 중 최대값이 최대 경로
    int res = tri[n-1][1];
    for(int i=2; i<n+2; i++){
        res = max(res, tri[n-1][i]);    // 배열을 순회하며 큰 값을 res에 저장
    }

    cout << res;

}
