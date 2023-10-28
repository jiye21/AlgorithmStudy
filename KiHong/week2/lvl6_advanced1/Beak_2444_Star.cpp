/*
문제
예제를 보고 규칙을 유추한 뒤에 별을 찍어 보세요.

입력
첫째 줄에 N(1 ≤ N ≤ 100)이 주어진다.

출력
첫째 줄부터 2×N-1번째 줄까지 차례대로 별을 출력한다.

예제 입력 1 
5
예제 출력 1 
    *
   ***
  *****
 *******
*********
 *******
  *****
   ***
    *
*/

#include <stdio.h>

int main(void) {
    int number;
    scanf("%d", &number);
    
    for (int k = 1; k < number + 1; k++) {
        for (int j = 0; j < number - k; j++) {
            printf(" ");
        }
        for (int j = 0; j < k + (k - 1); j++) {
            printf("*");
        }
        printf("\n");
    }
    for (int k = number - 1; k > 0; k--) {
        for (int j = 0; j < number - k; j++) {
            printf(" ");
        }
        for (int j = 0; j < k + (k - 1); j++) {
            printf("*");
        }
        printf("\n");
    }
    
    return 0;
}