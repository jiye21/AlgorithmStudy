#include <iostream>

using namespace std;

int main(){
    int yoot[12];

    for(int i=0; i<12; i+=4){
        cin >> yoot[0+i] >> yoot[1+i]>> yoot[2+i] >> yoot[3+i];
    }

    for(int i=0; i<12; i+=4){
        int bae = 0;
        for(int j=0; j<4; j++){
            if(yoot[i+j] == 0) bae++;
        }
        switch(bae){ //배가1개 A, 배가 0개 E
            case 0:
                cout << "E" << endl;
                break;
            case 1:
                cout << "A" << endl;
                break;
            case 2:
                cout << "B" << endl;
                break;
            case 3:
                cout << "C" << endl;
                break;
            case 4:
                cout << "D" << endl;
                break; 
        }
    }

}