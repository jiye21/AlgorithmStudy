#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    vector<int> basket;
    for(int i = 1; i<N+1; i++){
        basket.push_back(i);
    }
    
    vector<pair<int, int>> b_exchange;

    //M개의 줄에 걸쳐 공을 교환할 방법 정의, 방법은 정수 i, j로 구성
    //i번 바구니와 j번 바구니의 공을 서로 교환
    for (int k = 0; k<M; k++){
        int i, j;
        cin >> i >> j;
        b_exchange.push_back(make_pair(i, j));
    }
    
    //b_exchange 벡터를 순회하며 공 교환
    vector<pair<int,int>>::iterator iter;
    for(iter = b_exchange.begin(); iter != b_exchange.end(); iter++ ){
        int temp = basket.at(iter->first-1);
        basket.at((iter->first)-1) = basket.at((iter->second)-1);
        basket.at((iter->second)-1) = temp;
    }

    //결과 출력
    vector<int>::iterator i;
    for(i = basket.begin(); i != basket.end(); i++ ){
        cout << *i << " ";
    }

}