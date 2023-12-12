#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<pair<pair<int,int>, int>> B;

    for(int i = 0; i<N; i++){
        int a, b;
        cin >> a >> b;
        B.push_back(make_pair(make_pair(a,b),1));
    }


    vector<pair<pair<int,int>, int>>::iterator iter;
    for(int i = 0; i<N; i++){
        for(iter = B.begin(); iter != B.end(); iter++){
            if(B[i].first.first < iter->first.first &&
            B[i].first.second < iter->first.second){
                B[i].second += 1;
            }
        }
        cout << B[i].second << " ";
    }


} 