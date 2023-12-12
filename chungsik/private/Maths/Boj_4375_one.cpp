/*각 자릿수가 모두 1로만 이루어진 n의 배수 중 가장 작은 수의 자리수를 출력한다.*/


#include <iostream>

using namespace std;

int main()
{
    int n;
    
    while(cin >> n) 
    {
        int remain = 1;
        int count = 1;

        while(remain % n != 0 )
        {
            //현재 생성 10을 곱하고 1을 더한 다음 
            //n으로 나눈 나머지를 다시 할당 하는 역할
            remain = (remain * 10 + 1) % n;
            count++;
        }
        cout << count << endl;
    }
    return 0;
}