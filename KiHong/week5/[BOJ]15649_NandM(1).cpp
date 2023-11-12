#include <iostream>
#include <vector>
using namespace std;

int n, m;
bool visited[9] = {0,};
vector<int> progress;

void DFS(int start);

int main(void) {
    cin >> n >> m;

    DFS(1);

    return 0;
}


void DFS(int start)
{
    // 출력해야하는 만큼 배열이 쌓이면 모든 수를 출력한다.
    if(progress.size() == m)
    {
        for(int i = 0; i < m; i++)
        {
            cout << progress.at(i) << '\x20';
        }
        cout << '\n';
        return;
    }

    for(int k = start; k <= n; k++)
    {
        if(!visited[k])
        {
            visited[k] = true;
            progress.push_back(k);

            DFS(k);

            visited[k] = false;
            progress.pop_back();
        }
    }
}