#include <iostream>
using namespace std;

//char 자료형을 전역 변수로 선언하면 NULL로 초기화된다. 
char num_arr[5][16];

int main()
{
    for(int i = 0; i<5; i++){
        cin >> num_arr[i];
    }

    for(int i = 0; i<15; i++){
        for(int j = 0; j<5; j++){
            if(num_arr[j][i]!='\0'){
                cout << num_arr[j][i];
            }
        }
    }

}