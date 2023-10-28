#include <stdio.h>

int main(void) {
    double a, b;
    scanf("%lf %lf", &a, &b);
    printf("%.31lf", (a / b));
    return 0;
}