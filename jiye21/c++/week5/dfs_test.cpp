/* 
# Vertex = 7개, Edge = 8개인 그래프가 있을 때,
# 다음 8개의 줄에 연결 정보를 제공
7 8  
1 2  
1 3
2 4
2 5
4 6
5 6
6 7
3 7

정답 : 1 3 7 6 5 4 2
*/

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int inputArr[9][9]; // 그래프 표기용 이차원 배열
int visited[9];     // 방문 표기용 일차원 배열

int main(){
    int N, E;
    cin >> N >> E;

    // 연결 정보는 8번 들어옴
    for(int i=0; i<E; i++){
        int a,b;
        cin>> a >> b;
        // 이때 0번 라인은 전부 버리고 받음. 안그러면 a-1이런식으로 받아야 함.
        inputArr[a][b] = 1;
        inputArr[b][a] = 1;
    }

    stack<int> my_stack;
    my_stack.push(1);       // 1번 노드부터 방문

    int cur;            // 현재 위치
    vector<int> visited_order;  // 방문순서 담기 위한 vector
    visited[1] = 1;         // 첫번째 방문 표시

    while(!my_stack.empty()){
        cur = my_stack.top();

        visited_order.push_back(cur);

        my_stack.pop();

        for(int i=1; i<=N; i++){
            if(inputArr[cur][i] && visited[i] != 1){
                my_stack.push(i);
                // 스택에 중복되어 들어가지 않게 하기 위해 방문했다는 표시
                visited[i] = 1;

                //cout << "cur : " << cur << " i : " << i<< "\n";
            }
        }
    }


    cout << endl << "--방문 순서--" <<endl ;
    for(auto iter=visited_order.begin(); iter!=visited_order.end(); iter++){
        cout << *iter << " ";
    }

}