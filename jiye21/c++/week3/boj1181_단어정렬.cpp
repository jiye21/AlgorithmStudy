#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool Compare(string a, string b){   
    if (a.length() == b.length()) return a<b; //단어의 길이가 같다면 문자의 사전적 비교
    return a.length() < b.length();   //문자열 길이가 작으면 true, 앞으로 오게됨
}

int main(){
    int N;
    cin >> N;
    vector<string> word_vec;

    for(int i = 0; i<N; i++){   //N개의 단어를 vector에 입력받음
        string a;
        cin >> a;
        //find 함수는 해당 단어가 존재하지 않을 경우 vector.end를 반환
        //단어가 존재하지 않을 때만 단어 삽입 (중복 제거를 위함)
        if(find(word_vec.begin(), word_vec.end(), a) == word_vec.end()) word_vec.push_back(a);
    }

    sort(word_vec.begin(), word_vec.end(), Compare);  //정렬

    
    for(int i = 0; i<word_vec.size(); i++){
        cout << word_vec[i] << '\n';
    }

}