#include <iostream>
using namespace std;

int main(){
    int a,b,c,d,e,f;
    int king = 1, queen = 1, rook = 2, bishop = 2, knight = 2, pawn = 8;

    cin >> a;
    cin >> b;
    cin >> c;
    cin >> d;
    cin >> e;
    cin >> f;
    
    cout << king-a << " " << queen-b << " " ;
    cout << rook-c << " " << bishop-d << " " ;
    cout << knight-e << " " << pawn-f;

}