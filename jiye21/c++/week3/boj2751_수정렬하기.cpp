#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int main()
{
    int N;
    cin >> N;
    vector<int> num_vec;
    for(int i = 0; i<N; i++){
        int a;
        cin >> a;
        num_vec.push_back(a);
    }
    
    sort(num_vec.begin(), num_vec.end());
    for(int i = 0; i<num_vec.size() ; i++){
        cout << num_vec[i] << '\n';
    }
    
}