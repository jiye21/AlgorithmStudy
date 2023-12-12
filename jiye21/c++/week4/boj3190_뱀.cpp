#include <iostream>
#include <vector>
#include <deque>
#include <list>

using namespace std;

//보드판 직접 구현 x 벽 위치 검사, 사과 위치만 선언해두기. 
//벽 위치 : 0행, 0열, N+1행, N+1열이 벽. 뱀 머리와 벽의 위치가 같아지면 게임 종료.
//
//뱀 : 덱에 실시간으로 뱀의 위치(pair) 저장. 머리가 몸통 중 어느 부분에 부딪히면 게임 종료.
//뱀 방향 : char형 변수로 저장. 방향 변경시마다 업데이트. 
//뱀 기본 움직임 : 움직이던 방향으로 머리의 위치를 push_front, 꼬리는 pop_back. 사과 먹고 꼬리 생성시 머리만 push_front. 
//뱀 방향 변경 : 그대로 머리의 위치 push_front, 꼬리 pop_back. (머리가 위치를 틀면 꼬리들은 앞 꼬리의 위치로 이동되기 때문)
//
//사과 위치 : 벡터에 pair로 저장.

int main()
{
    int N, K, L;
    cin >> N >> K;


    //사과 위치 선언
    list<pair<int,int>> apple;
    for(int i=0; i<K; i++)
    {
        int a,b;
        cin >> a >> b;
        apple.push_back(make_pair(a,b));
    }

    //방향 변환 횟수 L과 정보 C 선언
    cin >> L;
    deque<pair<int, char>> C;
    for(int i=0; i<L; i++){
        int time;
        char direction;
        cin >> time >> direction;
        C.push_back(make_pair(time,direction));
    }

    
    //뱀. 크기 1, 요소 1로 초기화. 현재 위치(1,1)
    deque<pair<int,int>> snake(1, make_pair(1,1));
    //뱀 방향 선언. 현재 방향 r.
    char snake_dir = 'r';



    //시간 저장하는 변수 선언
    int time = 0;

    //게임 시작. 방향에 따른 위치 이동. 이동시 이동한 칸에 사과 있는지, 이동한 칸이 벽 칸인지, 이동해서 꼬리와 닿았는지 검사
    while(true)
    {
        time++;
        bool apple_flag = false;
        
        // 이동
        switch(snake_dir)
        {
            case 'r':
                snake.push_front(make_pair(snake[0].first, snake[0].second+1));
                break;                    
            case 'l':
                snake.push_front(make_pair(snake[0].first, snake[0].second-1));
                break;
            case 'u':
                snake.push_front(make_pair(snake[0].first-1, snake[0].second));
                break;
            case 'd':
                snake.push_front(make_pair(snake[0].first+1, snake[0].second));
                break;
        }
        

        //몸통 부딪힘 검사
        for(auto iter = snake.begin()+1; iter != snake.end(); iter++)
        {
            if(snake[0] == *iter)
            {
                cout << time;
                exit(0);
            }
        }
        
        
        // 사과 검사
        if(!apple.empty())
        {
            for(auto iter = apple.begin(); iter != apple.end(); iter++)
            {
                if(snake[0] == *iter)
                {
                    apple_flag = true;
                    iter = apple.erase(iter);
                } 
            }
        }
        

        if(!apple_flag) snake.pop_back();

        //벽 부딪힘 검사
        if(snake[0].first < 1 || snake[0].first > N)
        {
            cout << time;
            exit(0);
        }
        if(snake[0].second < 1 || snake[0].second > N)
        {
            cout << time;
            exit(0);
        }
        

        //방향 변환 검사. 주어진 시간이 끝나면 방향만 변경. L : 왼쪽 90, D : 오른쪽 90도 회전
        if(!C.empty())
        {
            if(time == C[0].first)
            {
                if(C[0].second == 'L')   //왼쪽으로 방향 변경
                {
                    switch(snake_dir)
                    {
                        case 'r':                   
                            snake_dir = 'u';                    
                            break;
                        case 'l':
                            snake_dir = 'd';
                            break;
                        case 'u':
                            snake_dir = 'l';
                            break;
                        case 'd':
                            snake_dir = 'r';
                            break;
                    }
                }
                else if(C[0].second == 'D')    //오른쪽으로 방향 변경
                {
                    switch(snake_dir)
                    {
                        case 'r':
                            snake_dir = 'd';
                            break;
                        case 'l':
                            snake_dir = 'u';
                            break;
                        case 'u':
                            snake_dir = 'r';
                            break;
                        case 'd':
                            snake_dir = 'l';
                            break;
                    }
                    
                }
                //방향 변경했으니 방향정보 필요없어서 삭제.
                C.pop_front();
            }
        }

        
    }

}