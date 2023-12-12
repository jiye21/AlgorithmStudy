#include <iostream>

using namespace std;

int main()
{
    int a[5];
    cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4];

    int avg = (a[0]+a[1]+a[2]+a[3]+a[4])/5;
    int med;

    for(int i = 0; i<4; i++){
        for(int j = 0; j<4-i; j++){
            if(a[j] > a[j+1]){
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }

    med = a[2];

    cout << avg << '\n';
    cout << med;
}