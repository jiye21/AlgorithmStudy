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
void fn_swap(int *a, int *b);
char* ReadStdInput(int inputSize);
char* CharAppend(char* _originalText, char* _append);

int main(void) {
    Execute();
    return 0;
}

// <Summary> Execute process
void Execute() {
    int base = 1;
    int * test = (int*)malloc(1 * sizeof(int));
    memset(test, 4, sizeof(test));
    int * test2 = test;
    printf("Test 1 value : %d\n", *test);  // test 주소의 쓰레기 값 출력
    printf("Test 2 value : %d\n", *test2); // test 주소의 쓰레기 값 출력
    printf("Test 1 pointer : %p\n", test);  // test 주소의 쓰레기 값 출력
    printf("Test 2 pointer : %p\n", test2); // test 주소의 쓰레기 값 출력`
    test2 = &base;          // test2에 base 주소 입력
    printf("base value : %d\n", *test2); // base 주소에 있는 값 출력
    
    free(test); // test 메모리 할당 제거
    // free(test2); // 오류 발생 : test2는 메모리에 할당된 적이 없다.
    
    printf("Test 1 value : %d\n", *test);  // test 주소의 쓰레기 값 출력
    printf("Test 2 value : %d\n", *test2); // test 주소의 쓰레기 값 출력
    printf("Test 1 pointer : %p\n", test);  // test 주소의 쓰레기 값 출력
    printf("Test 2 pointer : %p\n", test2); // test 주소의 쓰레기 값 출력`
    // test2 = 0;
    // printf("%d\n", *test2); // 오류 발생 : test2의 메모리 부재

    int inputValue[2];
    char* outputGuide = "Swap : ";

    // Input region
    for (int k = 0; k < 2; k++) {
        char* inputGuide;
        char inputAppend[2];

        // Convert k to char
        snprintf(inputAppend, 2, "%d", k+1);

        // Generate inputGuide text
        inputGuide = CharAppend("Enter number ", CharAppend(inputAppend, " : "));

        // print out input guide
        write(1, inputGuide, strlen(inputGuide));

        // Initialize input integer
        inputValue[k] = atoi(ReadStdInput(11));
    }
    
    // Swap pointer
    fn_swap(&inputValue[0], &inputValue[1]);
    
    // Output region
    for (int k = 0; k < 2; k++) {
        char outputAppend[16];

        // Convert k to char
        snprintf(&outputAppend[0], 16, "%d", inputValue[k]);
        
        // Change output text
        outputGuide = CharAppend(outputGuide, CharAppend(outputAppend, " "));
    }
    
    strcat(outputGuide, "\n");
    // print out input guide
    write(1, outputGuide, strlen(outputGuide));
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

// <Summary> Append two char array
char* CharAppend(char* _originalText, char* _append) {
    char* input = (char*)malloc(strlen(_originalText) + strlen(_append));

    strcpy(input, _originalText);
    strcat(input, _append);

    return input;
}
