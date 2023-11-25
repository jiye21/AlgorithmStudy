#include <stdio.h>
#include <math.h>

using namespace std;


#define GET_DISTANCE(x1, y1, x2, y2) sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2))

struct Player {
    int x, y;
    int distance;
};


int main()
{
    Player player1;
    Player player2;
    
    int loop, counter = 0;
    int *result;
    scanf("%d", &loop);
    result = (int*)malloc(loop * sizeof(int));
    
    while (loop--) {
        scanf("%d %d %d %d %d %d", &player1.x, &player1.y, &player1.distance, &player2.x, &player2.y, &player2.distance);
        double distanceBetweenTwoPoints = GET_DISTANCE(player1.x, player1.y, player2.x, player2.y);
        double furderDistance = (player1.distance > player2.distance) ? player1.distance - player2.distance : player2.distance - player1.distance;
        int totalDistance = player1.distance + player2.distance;
        
        // 두 점이 같은 위치이며 같은 거리를 유지할 경우
        if (distanceBetweenTwoPoints == 0 && furderDistance == 0) result[counter] = -1;
        // 두 점의 위치가 다르며 목표의 거리가 서로 다를 경우
        else if (distanceBetweenTwoPoints < totalDistance && furderDistance < distanceBetweenTwoPoints) result[counter] = 2;
        // 두 점의 위치가 다르며 목표와의 거리가 같을 경우
        else if (distanceBetweenTwoPoints == totalDistance || furderDistance == distanceBetweenTwoPoints) result[counter] = 1;
        // 이외의 경우
        else result[counter] = 0;
        
        counter++;
    }
    
    for (int k = 0; k < counter; k++) {
        printf("%d\n", result[k]);
    }

    return 0;
}
