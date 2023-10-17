#include <stdio.h>
#include <string.h>
#include <unistd.h>

// 함수 원형 선언
int InputInteger(char *output);
void is_negative(int n);

int main(void){
    is_negative(InputInteger("Enter Integer : "));
    return 0;
}

// Input Manager
int InputInteger(char *output){
    int input = 0;

    printf("%s", output);
    scanf("%d", &input);
    
    return input;
}

void is_negative(int n) {
    char output[2];

    if (n > 0) {
        strcpy(output, "P");
    }
    else if (n < 0) {
        strcpy(output, "N");
    }
    else {
        strcpy(output, "0");
    }

    strcat(output, "\n");

    write(1, &output, sizeof(output));
}