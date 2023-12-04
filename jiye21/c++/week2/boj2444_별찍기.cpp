#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    int num = 1;

    for (int i=0; i < n-1; i++){
        for(int j=n-1; j>i; j--){
            cout<< " ";
        }
        for(int k=0; k<num; k++){
            cout<<"*";
        }
        cout << '\n';
        num += 2;
    }

    for(int i=0; i<(2*n-1); i++){
        cout << "*";
    }
    cout<<'\n';

    num=2*n-3;
    for (int i=0; i < n-1; i++){
        for(int j=0; j<i+1; j++){
            cout<< " ";
        }
        for(int k=0; k<num; k++){
            cout<<"*";
        }
        cout<<'\n';
        num-=2;
    }

}