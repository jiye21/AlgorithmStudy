/*
문제
정수 X에 사용할 수 있는 연산은 다음과 같이 세 가지 이다.

X가 3으로 나누어 떨어지면, 3으로 나눈다.
X가 2로 나누어 떨어지면, 2로 나눈다.
1을 뺀다.
정수 N이 주어졌을 때, 위와 같은 연산 세 개를 적절히 사용해서 1을 만들려고 한다. 연산을 사용하는 횟수의 최솟값을 출력하시오.

입력
첫째 줄에 1보다 크거나 같고, 106보다 작거나 같은 정수 N이 주어진다.

출력
첫째 줄에 연산을 하는 횟수의 최솟값을 출력한다.

예제 입력 1 
2
예제 출력 1 
1
예제 입력 2 
10
예제 출력 2 
3
힌트
10의 경우에 10 → 9 → 3 → 1 로 3번 만에 만들 수 있다.
*/


#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

	int n;
	cin >> n;

	vector<int> storage(n + 1, 0);

	for (int k = 2; k <= n; k++) {
		storage[k] = storage[k - 1] + 1;                                    // +1연산) 이전 위치와 현재 위치의 관계
		if (k % 3 == 0) storage[k] = min(storage[k], storage[k / 3] + 1);   // *3연산) (현재 위치/3) 자리 숫자와 현재 숫자의 관계
		if (k % 2 == 0) storage[k] = min(storage[k], storage[k / 2] + 1);   // *2연산) (현재 위치/2) 자리 숫자와 현재 숫자의 관계
	}

	cout << storage[n] << endl;

	return 0;
}