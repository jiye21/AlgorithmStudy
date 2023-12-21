#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N, student, apple;
    cin >> N;

    vector<pair<int,int>> vec;

    for(int i=0; i<N; i++){
        cin >> student >> apple;
        vec.push_back({student, apple});
    }

    vector<int> ans;

    for(auto iter=vec.begin(); iter!=vec.end(); iter++){
        ans.push_back(iter->second % iter->first);
    }

    int sum=0;
    for(auto iter=ans.begin(); iter!=ans.end(); iter++){
        sum += *iter;
    }

    cout << sum;

}