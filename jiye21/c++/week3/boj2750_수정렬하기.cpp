#include <iostream>

using namespace std;
int main()
{
    int N;
    cin >> N;
    int *num_arr = new int[N];
    for(int i = 0; i<N; i++){
        cin >> num_arr[i];
    }
    
    
    for(int i = 0; i<N-1 ; i++){
        for(int j = 0; j< N-1-i; j++){
            if(num_arr[j] > num_arr[j+1]){
                int temp = num_arr[j];
                num_arr[j] = num_arr[j+1];
                num_arr[j+1] = temp;
            }
        }
    }
    for(int i = 0; i<N ; i++){
        cout << num_arr[i] << '\n';
    }
    delete[] num_arr;
}