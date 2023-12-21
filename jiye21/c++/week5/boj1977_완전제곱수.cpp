#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
// pow 함수의 return 값의 자료형은 double이다. 
// double형 변수를 int형 벡터에 push했더니 값이 잘못 들어간다. 
// 그냥 곱셈을 하자..

int main(){
    int M, N;
    vector<int> ans;

    cin >> M >> N;

    for(int i=1; (i * i)<=N ; i++){
        if((i * i)>=M) {
            ans.push_back(i * i);
        }
    }

    int sum = 0;
    for(auto iter = ans.begin(); iter!= ans.end(); iter++){
        sum += *iter;
    }


    if(sum == 0) {
        cout << -1;
    }
    else{
        cout << sum << endl;
        cout << ans[0];
    }

}