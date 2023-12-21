#include <iostream>
#include <cmath>

using namespace std;

// 나눗셈 연산 주의하기. int끼리 연산은 소수점 무시됨
// vector를 N만큼 크기 지정하며 초기화한 후 push_back 연산을 하면 N번째 뒤부터 값이 붙는다. 
// 뺄셈 시 음수일 경우 처리하기
// 자료형 범위 생각하기
// 최악의 경우 생각하기
// 반올림 함수는 시간을 잡아먹는 듯 하다. if문 쓰기

int A[10000001];

int main(){
    int N, B, C;
    cin >> N;

    for(int i=0; i<N; i++){
        cin >> A[i]; 
    }

    cin >> B >> C;

    //총감독관이 시험장마다 1명씩 존재하므로 N으로 초기화
    //만약 총,부감독관 모두 1명씩 감시가능하다면 50만*100만명의 감독관 필요
    long long int supervisor = N;

    for(int i=0; i<N; i++){
        if(A[i]-B > 0){
            supervisor += (A[i] - B) / C;
            if((A[i] - B)%C != 0) supervisor++;
        }
    }

    cout << supervisor;
    
}