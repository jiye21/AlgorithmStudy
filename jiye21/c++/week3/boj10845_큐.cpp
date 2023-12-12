#include <iostream>
#include <vector>
#include <string>

using namespace std;

//함수에 매개변수로 vector를 전달하고 싶으면 call-by-reference를 이용해야 한다. 
void push (vector<int> &vec, int x);
void pop (vector<int> &vec);
void size (vector<int> &vec);
void empty (vector<int> &vec);
void front (vector<int> &vec);
void back (vector<int> &vec);

int main()
{
    int N;
    cin >> N;
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
        else if(cmd == "front"){
            front(my_stack);
        }
        else if(cmd == "back"){
            back(my_stack);
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
        int res = vec.front();
        for(int i = 0; i<vec.size()-1; i++){
            vec[i] = vec[i+1];
        }
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
void front (vector<int> &vec)
{
    if(vec.empty()) cout << -1 << '\n';
    else cout << vec.front() << '\n';
}
void back (vector<int> &vec)
{
    if(vec.empty()) cout << -1 << '\n';
    else cout << vec.back() << '\n';
}