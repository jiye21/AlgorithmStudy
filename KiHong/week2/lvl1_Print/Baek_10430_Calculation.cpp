/*
(A+B)%C는 ((A%C) + (B%C))%C 와 같을까?
(A×B)%C는 ((A%C) × (B%C))%C 와 같을까?
세 수 A, B, C가 주어졌을 때, 위의 네 가지 값을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 A, B, C가 순서대로 주어진다. (2 ≤ A, B, C ≤ 10000)
출력
첫째 줄에 (A+B)%C, 둘째 줄에 ((A%C) + (B%C))%C, 셋째 줄에 (A×B)%C, 넷째 줄에 ((A%C) × (B%C))%C를 출력한다.

예제 입력 1 
5 8 4
예제 출력 1 
1
1
0
0
*/

#include <stdio.h>

#define LAST_DIGIT(x) x % 10

int main(void) {
    int a, b;
    int result = 0;
    scanf("%d %d", &a, &b);
    
    int digit = 1;
    while (b > 0) {
        int output = a * (LAST_DIGIT(b));
        result += output * digit;
        b /= 10;
        digit *= 10;
        
        printf("%d\n", output);
    }

    printf("%d\n", result);

    return 0;
}