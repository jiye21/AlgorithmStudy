#include <iostream>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    stack<int> my_stack;
    int N;
    cin >> N;

    for(int i = 0; i<N; i++)
    {
        int cmd;
        cin >> cmd;

        switch(cmd)
        {
            case 1:
                int x;
                cin >> x;
                my_stack.push(x);
                break;
            case 2:
                if(my_stack.empty()) cout << -1 << '\n';
                else{
                    cout << my_stack.top() << '\n';
                    my_stack.pop();
                }
                break;
            case 3:
                cout << my_stack.size() << '\n';
                break;
            case 4:
                if(my_stack.empty()) cout << 1 << '\n';
                else cout << 0 << '\n';
                break;
            case 5:
                if(my_stack.empty()) cout << -1 << '\n';
                else cout << my_stack.top() << '\n';
                break;
        }
    }

}