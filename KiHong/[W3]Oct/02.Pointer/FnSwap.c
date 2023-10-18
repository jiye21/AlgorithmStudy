/*
다음 기능을 하는 함수를 만드시오
주소가 매개변수로 들어온 두개의 정수의 값을 바꾸는 기능
프로토타입 void fn_swap(int *a, int *b)
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

void Execute();
char* ReadStdInput(int inputSize);
void fn_swap(int *a, int *b);

int main(void) {
    Execute();
    return 0;
}

// <Summary> Execute process
void Execute() {
    int inputValue[2];
    char outputGuide[64] =  "Swap : ";

    // Input region
    for (int k = 0; k < 2; k++) {
        char inputGuide[32] = "Enter number ";
        char inputAppend[8];

        // Convert k to char
        snprintf(&inputAppend[0], 2, "%d", k+1);
        // Generate inputGuide text
        strcat(inputAppend, " : ");
        strcat(inputGuide, inputAppend);

        // print out input guide
        write(1, inputGuide, 20);

        char* input = ReadStdInput(11);
        inputValue[k] = atoi(input);
    }
    
    // Swap pointer
    fn_swap(&inputValue[0], &inputValue[1]);
    
    // Output region
    for (int k = 0; k < 2; k++) {
        char outputAppend[16];

        // Convert k to char
        snprintf(&outputAppend[0], 16, "%d", inputValue[k]);
        // Generate inputGuide text
        strcat(outputAppend, " ");
        strcat(outputGuide, outputAppend);
    }
    
    strcat(outputGuide, "\n");
    // print out input guide
    write(1, outputGuide, 64);
}

char* ReadStdInput(int inputSize) {
    char *inputChar = (char*)malloc(inputSize);

    // Read from standard input
    if (read(0, inputChar, inputSize) < 1) {
        write(1, "Wrong input detected\n", 22);
        free(inputChar);
        return NULL;
    }

    return inputChar;
}

// <Summary> Swap two integer pointer value
// <Parameter=*a> first integer
// <Parameter=*b> second integer
void fn_swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}