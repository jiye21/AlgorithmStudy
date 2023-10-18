#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
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
    char inputChar[1024];

    write(1, output, strlen(output));
    
    // Read from standard input
    if (read(0, inputChar, 20) > 0) {
        // cast char to int
        input = atoi(inputChar);
    } else {
        write(1, "Wrong input detected\n", 22);
    }

    return input;
}

void is_negative(int n) {
    char output[2];

    if (n > 0) {
        output[0] = 'P';
    }
    else if (n < 0) {
        output[0] = 'N';
    }
    else {
        output[0] = '0';
    }

    output[1] = '\n';

    write(1, &output, strlen(output));
}