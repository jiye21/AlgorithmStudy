/*
문제
알파벳 대소문자로 된 단어가 주어지면, 이 단어에서 가장 많이 사용된 알파벳이 무엇인지 알아내는 프로그램을 작성하시오. 단, 대문자와 소문자를 구분하지 않는다.

입력
첫째 줄에 알파벳 대소문자로 이루어진 단어가 주어진다. 주어지는 단어의 길이는 1,000,000을 넘지 않는다.

출력
첫째 줄에 이 단어에서 가장 많이 사용된 알파벳을 대문자로 출력한다. 단, 가장 많이 사용된 알파벳이 여러 개 존재하는 경우에는 ?를 출력한다.

예제 입력 1 
Mississipi
예제 출력 1 
?
예제 입력 2 
zZa
예제 출력 2 
Z
예제 입력 3 
z
예제 출력 3 
Z
예제 입력 4 
baaa
예제 출력 4 
A
*/

#include <stdio.h>

#define LOWER_A 65
#define ASKII_ALPHABET_GAP 32

int main(void) {
    char result;
    int counter = 0;
    int alphabet[26];
    char input[1000001];
    scanf("%s", input);
    
    for (int k = 0; input[k] != '\0'; k++) {
        int number = input[k] - LOWER_A;
        if (number > 25) number -= ASKII_ALPHABET_GAP;
        alphabet[number]++;
    }
    
    for (int k = 0; k < 26; k++) {
        if (counter < alphabet[k]) {
            result = (char)(k + LOWER_A);
            counter = alphabet[k];
        }
        else if (counter == alphabet[k]) {
            result = '?';
        }
    }
    
    printf("%c", result);
    
    return 0;
}