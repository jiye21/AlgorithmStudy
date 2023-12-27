/*

USADO : 두 동영상이 얼마나 가까운지를 측정하는 단위. 1 < USADO < 1,000,000,000
임의의 두 쌍 사이의 동영상의 USADO는 그 경로의 모든 연결들의 USADO 중 최솟값이다(더한 값 아님!)
USADO가 K이상인 동영상이 추천된다. 

무방향 가중치 그래프이다. 정점은 N개.

지나온 경로 중 USADO 최솟값을 구하기 위해 유사도들을 배열에 담아둘 필요없이, 
탐색중에 유사도가 k미만이 되는 정점을 방문한 시점부터 그 이후의 경로는 계산할 필요가 없어진다. 
특정 정점에서 다른 정점까지의 경로의 경우의수를 모두 구할 필요없이 단지 유사도가 k이상인 정점의 갯수만 구하면 된다. 

인접 리스트로 구현해야한다. 인접행렬은 시간 초과가 난다. 
인접 리스트의 각 행의 크기만큼만 탐색한다. 

*/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// 인덱스 번호가 인접리스트의 행, [인덱스].first가 인접리스트의 열, [].second가 유사도(가중치)
vector<vector<pair<int,long long int>>> USADO(5001);
int N, Q;


void BFS(int v, long long int k){
    int cnt = 0;

    queue<pair<int, long long int>> q;
    vector<bool> visited(N+1,false);

    q.push({v,k});
    visited[v] = true;

    while(!q.empty()){
        int cur = q.front().first;
        long long int cur_weight = q.front().second;  // 사실 필요없음 쓰이지 않음.
        q.pop();


        // cur 한 행을 탐색
        for(int j=0; j<USADO[cur].size() ; j++){
            int next = USADO[cur][j].first;
            long long int next_weight = USADO[cur][j].second;

            if(!visited[next] && next_weight>=k){    // k보다 작은 값이 들어오는 순간 최솟값이 k보다 작아져 그 이후의 경로는 계산할 필요가 없어진다. 
                cnt++;
                visited[next]=true;
                q.push({next,next_weight});
            }
        }
    }

    cout << cnt << '\n';
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> Q;


    for(int i=0; i<N-1; i++){
        int x,y;
        long long int weight;
        cin >> x >> y >> weight;

        USADO[x].push_back({y,weight});
        USADO[y].push_back({x,weight});
    }

    for(int i=0; i<Q; i++){
        long long int k;
        int v;
        cin >> k >> v;

        BFS(v, k);
    }



}

