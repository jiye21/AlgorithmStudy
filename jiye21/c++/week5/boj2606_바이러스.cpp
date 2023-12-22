#include <iostream>
#include <stack>

using namespace std;

int arr[101][101];
int visited[101];

int main(){
    int N, c_pair;
    cin >> N >> c_pair;

    for(int i=0; i<c_pair; i++){
        int a, b;
        cin >> a >> b;
        arr[a][b]=1;
        arr[b][a]=1;        // 무방향 그래프이므로!!
    }

    stack<int> s;
    s.push(1);
    visited[1] = 1;

    int cnt = 0;

    while(!s.empty()){
        int r = s.top();
        s.pop();

        for(int i=1; i<=N; i++){
            if(visited[i]!=1 && arr[r][i]==1){
                visited[i]=1;
                s.push(i);
                cnt++;
            }
        }
    }

    cout << cnt;

}