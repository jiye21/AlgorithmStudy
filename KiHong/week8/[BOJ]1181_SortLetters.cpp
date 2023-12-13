/*
단어 정렬
 
시간 제한	메모리 제한	제출	정답	맞힌 사람	정답 비율
2 초	256 MB	165178	69128	51813	40.337%

문제
알파벳 소문자로 이루어진 N개의 단어가 들어오면 아래와 같은 조건에 따라 정렬하는 프로그램을 작성하시오.

길이가 짧은 것부터
길이가 같으면 사전 순으로
단, 중복된 단어는 하나만 남기고 제거해야 한다.

입력
첫째 줄에 단어의 개수 N이 주어진다. (1 ≤ N ≤ 20,000) 둘째 줄부터 N개의 줄에 걸쳐 알파벳 소문자로 이루어진 단어가 한 줄에 하나씩 주어진다. 주어지는 문자열의 길이는 50을 넘지 않는다.

출력
조건에 따라 정렬하여 단어들을 출력한다.

예제 입력 1 
13
but
i
wont
hesitate
no
more
no
more
it
cannot
wait
im
yours
예제 출력 1 
i
im
it
no
but
more
wait
wont
yours
cannot
hesitate
*/

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>

using namespace std;

typedef vector<string>::iterator striter;


// 	4932KB	24ms
#pragma region SetSolution
struct CustomCompare {
    bool operator() (const string& first, const string& second) const {
        if (first.size() == second.size()) {
            return strcmp(first.c_str(), second.c_str()) < 0 ? true : false;
        }
        return first.size() < second.size();
    }
};

void UsingSet(){
    int loop = 0;
    cin >> loop;

    set<string, CustomCompare> letters;

    while (loop--) {
        string letter;
        cin >> letter;
        letters.insert(letter);
    }

    for (set<string>::iterator iter = letters.begin(); iter != letters.end(); iter++) {
        cout << *iter << '\n';
    }
}
#pragma endregion SetSolution

// 	3980KB	20ms
#pragma region VecterSolution
bool compare(const string& first, const string& second) {
    if (first.size() == second.size()) {
        return strcmp(first.c_str(), second.c_str()) < 0 ? true : false;
    }
    return first.size() < second.size();
}
    
void UsingVector(){
    int loop = 0;
    cin >> loop;

    vector<string> letters(loop);

    for (int k = 0; k < loop; k++) {
        cin >> letters[k];
    }

    sort(letters.begin(), letters.end(), compare);
    striter endPoint = unique(letters.begin(), letters.end());

    for (striter iter = letters.begin(); iter != endPoint; iter++) {
        cout << *iter << '\n';
    }
}
#pragma endregion VectorSolution


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

    UsingVector();

    return 0;
}