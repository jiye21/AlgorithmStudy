#include <iostream>
#include <vector>
#include <string>

using namespace std;

//함수에 매개변수로 vector를 전달하고 싶으면 call-by-reference를 이용해야 한다. 
void push (vector<int> &vec, int x);
void pop (vector<int> &vec);
void size (vector<int> &vec);
void empty (vector<int> &vec);
void top (vector<int> &vec);

int main()
{
    int N;
    cin >> N;      //cin은 개행 문자 전까지만 입력받고 개행 문자는 버퍼에 남긴다. 
                   //cin은 전 버퍼에 있던 공백 및 개행문자를 무시해서 상관없지만, 
                   //getline은 전 버퍼에 있던 공백 및 개행문자를 포함해서 입력받기 때문에 버퍼를 지워줘야 한다. 
                   //getline은 개행문자를 버퍼에 남기지 않기 때문에 버퍼를 비워줄 필요가 없다. 
    cin.ignore();
    vector<int> my_stack;

    for(int i = 0; i<N ; i++){
        string cmd;
        getline(cin, cmd);

        if(cmd.substr(0,4) == "push"){
            int push_num = stoi(cmd.substr(5,cmd.length()-5));
            push(my_stack, push_num);
        }
        else if(cmd == "pop"){
            pop(my_stack);
        }
        else if(cmd == "size"){
            size(my_stack);
        }
        else if(cmd == "empty"){
            empty(my_stack);
        }
        else if(cmd == "top"){
            top(my_stack);
        }

    }

}


void push (vector<int> &vec, int x)
{
    vec.push_back(x);
}
void pop (vector<int> &vec)
{
    if(vec.empty()) cout << -1 << '\n';
    else{
        int res = vec.back();
        vec.pop_back();
        cout << res << '\n';
    }
}
void size (vector<int> &vec)
{
    cout << vec.size() << '\n';
}
void empty (vector<int> &vec)
{
    if(vec.empty()) cout << 1 << '\n';
    else cout << 0 << '\n';
}
void top (vector<int> &vec)
{
    if(vec.empty()) cout << -1 << '\n';
    else cout << vec.back() << '\n';
}