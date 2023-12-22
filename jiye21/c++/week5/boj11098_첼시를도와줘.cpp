#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// pair로 이루어진 벡터에 sort 함수를 쓰면 first값을 기준으로 오름차순으로 정렬된다. 
// first 값이 같을 때는 second기준으로 오름차순이다. 

bool compare(pair<int, string> &a, pair<int, string> &b){
    return a.first > b.first;       // 내림차순으로 정렬
}


int main(){
    int n, p;
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> p;

        vector<pair<int, string>> player;
        for(int i=0; i<p; i++){
            long long int a;
            string b;
            cin >> a >> b;

            player.push_back({a, b});
        }
        sort(player.begin(), player.end(), compare);
        cout << player[0].second << endl;
    }


}