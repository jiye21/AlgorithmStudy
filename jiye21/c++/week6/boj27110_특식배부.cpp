#include <iostream>

using namespace std;

int main(){
    int N, A, B, C;
    cin >> N;
    cin >> A >> B >> C;

    int ans = 0;

    if(A >= N) ans += N;
    else ans += A;

    if(B >= N) ans += N;
    else ans += B;

    if(C >= N) ans += N;
    else ans += C;

    cout << ans;
}