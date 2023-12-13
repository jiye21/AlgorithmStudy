#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

// 해시 알고리즘을 사용하여 완주하지 못한 선수 찾기
string solution(vector<string> participant, vector<string> completion) {
    string answer = "";

    // 해시 맵을 사용하여 참가자 목록에 있는 각 이름의 출현 빈도를 기록
    unordered_map<string, int> hash_map;

    // 참가자 목록에 있는 각 이름의 출현 빈도를 기록
    for (const auto& name : participant) {
        hash_map[name]++;
    }

    // 완주자 목록에 있는 각 이름의 출현 빈도를 감소
    for (const auto& name : completion) {
        hash_map[name]--;
    }

    // 출현 빈도가 1인 이름이 정답
    for (const auto& pair : hash_map) {
        if (pair.second== 1) {
            answer = pair.first;
            break;
        }
    }

    return answer;
}

int main() {
    // 테스트를 위해 입력 받기
    int n, m;
    cout << "참가자 수: ";
    cin >> n;

    vector<string> participant(n);
    cout << "참가자 이름 입력: ";
    for (int i = 0; i < n; ++i) {
        cin >> participant[i]; // ["leo", "kiki", "eden"]
    }

    cout << "완주자 수: ";
    cin >> m;

    vector<string> completion(m);
    cout << "완주자 이름 입력: ";
    for (int i = 0; i < m; ++i) {
        cin >> completion[i];
    }

    // 함수 호출 및 결과 출력
    string result = solution(participant, completion);
    cout << "완주하지 못한 선수: " << result << endl;

    return 0;
}