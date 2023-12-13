/*
1 성공다국어
 
시간 제한	메모리 제한	제출	정답	맞힌 사람	정답 비율
1 초	128 MB	24672	8145	6066	32.225%
문제
2와 5로 나누어 떨어지지 않는 정수 n(1 ≤ n ≤ 10000)가 주어졌을 때, 각 자릿수가 모두 1로만 이루어진 n의 배수를 찾는 프로그램을 작성하시오.

입력
입력은 여러 개의 테스트 케이스로 이루어져 있다. 각 테스트 케이스는 한 줄로 이루어져 있고, n이 주어진다.

출력
각 자릿수가 모두 1로만 이루어진 n의 배수 중 가장 작은 수의 자리수를 출력한다.

예제 입력 1 
3
7
9901

예제 출력 1 
3
6
12
*/

#include <iostream>

using namespace std;


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int num;
    while (cin >> num) {
        if (cin.eof()) break;

        int count = 1;
        int multiple = 1;

        while (multiple % num != 0) {
            multiple = multiple * 10 + 1;
            multiple %= num;
            count++;
        }
        
        cout << count << endl;
    }
    
    return 0;
}