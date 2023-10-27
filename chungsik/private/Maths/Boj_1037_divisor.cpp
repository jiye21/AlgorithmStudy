/*약수*/

#include<iostream>
using namespace std;

int main()
{   
    int n; 
    cin >> n;

    int min_t = 100001; //최솟값
    int max_t = 0;      //최댓값

    for(int i = 0; i < n; i++) {
        int N = 0; 
        cin >> N;
        min_t = min(min_t, N); //둘 중에 작은값
        max_t = max(max_t, N); //둘 중에 큰값
    }
    int result = min_t * max_t;

    cout << result << endl;

    return 0;
}