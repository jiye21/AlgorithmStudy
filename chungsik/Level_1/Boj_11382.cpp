/*꼬마 정민 : 꼬마 정민이는 이제 A + B 정도는 쉽게 계산할 수 있다. 
이제 A + B + C를 계산할 차례이다!
*/

/*첫 번째 줄에 A, B, C (1 ≤ A, B, C ≤ 1012)이 
공백을 사이에 두고 주어진다.*/

#include <iostream>

using namespace std;

int main()
{
    long long A = 0, B = 0, C = 0;
    cin >> A >> B >> C;

    long long sum = A + B + C;
    cout << sum << endl;

    return 0;
}