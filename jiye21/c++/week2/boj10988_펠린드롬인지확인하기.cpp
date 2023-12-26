#include <iostream>
#include <string>
using namespace std;

int main(){
    string str;
    cin >> str;
    int len = str.length();

    int n = len/2;
    for(int i=0; i<n; i++){
        if(str.at(i) != str.at(len-1-i)){
            cout << "0";
            exit(0);
        }
    }

    cout << "1";

}