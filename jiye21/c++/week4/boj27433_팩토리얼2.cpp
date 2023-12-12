#include <iostream>

using namespace std;

long long int factorial(int n);

int main()
{
    int N;
    cin >> N;
    cout << factorial(N);
}


long long int factorial(int n)
{
    if(n == 1 || n == 0) return 1;

    return n * factorial(n-1);
}