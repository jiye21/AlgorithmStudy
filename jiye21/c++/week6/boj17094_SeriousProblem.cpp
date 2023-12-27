#include <iostream>
#include <string>
using namespace std;


int main() {
    int len;
    cin >> len;
    string s;
    cin >> s;
    
    int c_cnt = 0;
    int e_cnt = 0;
    
    for(int i=0; i<len; i++){
        if(s[i]=='2') c_cnt++;
        if(s[i]=='e') e_cnt++;
    }
    
    if(c_cnt > e_cnt) cout << '2';
    else if(c_cnt < e_cnt) cout << 'e';
    else cout << "yee";
    
}