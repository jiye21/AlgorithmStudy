/*
Queue
문제 설명
배열 arr가 주어집니다. 배열 arr의 각 원소는 숫자 0부터 9까지로 이루어져 있습니다. 이때, 배열 arr에서 연속적으로 나타나는 숫자는 하나만 남기고 전부 제거하려고 합니다. 단, 제거된 후 남은 수들을 반환할 때는 배열 arr의 원소들의 순서를 유지해야 합니다. 예를 들면,

arr = [1, 1, 3, 3, 0, 1, 1] 이면 [1, 3, 0, 1] 을 return 합니다.
arr = [4, 4, 4, 3, 3] 이면 [4, 3] 을 return 합니다.
배열 arr에서 연속적으로 나타나는 숫자는 제거하고 남은 수들을 return 하는 solution 함수를 완성해 주세요.

제한사항
배열 arr의 크기 : 1,000,000 이하의 자연수
배열 arr의 원소의 크기 : 0보다 크거나 같고 9보다 작거나 같은 정수

입출력 예
arr	            answer
[1,1,3,3,0,1,1]	[1,3,0,1]
[4,4,4,3,3]	    [4,3]
*/

#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr);
vector<int> solution2(vector<int> arr);

int main(void) {

    solution(vector<int>({1,1,3,3,0,1,1}));
    solution2(vector<int>({4,4,4,3,3}));

    return 0;
}

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    queue<int> que;
    
    // 첫 원소를 push해줌으로써 반복문 속 조건문에 queue가 비었는지 확인할 필요가 없어진다.
    // 또한, 첫 원소를 2번 입력한다 하여도 동일한 원소이기에 push하지 않는다. 입력값이 클수록 이득이다.
    que.push(arr[0]);
    
    for (auto i : arr) {
        if (que.back() != i) {
            que.push(i);
        }
    }
    
    while (!que.empty())
    {
        answer.push_back(que.front());
        que.pop();
    }
    
    return answer;
}

// Version 2
// 남의 코드 보고 따라한건데, 시간/공간 복잡도 모두 비등하다.
#include <algorithm>

vector<int> solution2(vector<int> arr) 
{
    // Unique 함수는 중복된 값을 하나로 바꾸며, 정렬까지 한다.
    // 또한, 마지막으로 정렬된 자리의 iterator를 반환한다. 이를 바로 erase에 반영하면 마지막 자리 뒤에 존재하는 쓰레기 값들을 모두 제거할 수 있다.
    arr.erase(unique(arr.begin(), arr.end()),arr.end());
    return arr;
}
