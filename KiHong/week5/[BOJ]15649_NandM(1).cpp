#include <iostream>
using namespace std;

int n, m;
int arr[9] = {0,};
bool visited[9] = {0,};

void DFS(int count);

int main(void) {
    cin >> n >> m;

    DFS(0);

    return 0;
}


void DFS(int count)
{
    if(count == m)
    {
        for(int i = 0; i < m; i++) 
        {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        
        return;
    }

    for(int i = 1; i <= n; i++)
    {
        if(!visited[i])
        {
            visited[i] = true;
            arr[count] = i;
            DFS(count+1);
            visited[i] = false;
        }
    }
}