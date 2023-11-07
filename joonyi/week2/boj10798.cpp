// boj10798 https://www.acmicpc.net/problem/10798 세로읽기

#include <iostream>

using namespace std;

int main()
{
	char board[5][15];

	for (int i = 0; i < 5; i++)
	{
		string line;
		cin >> line;
		int length = line.length();
		for (int j = 0; j < 15; j++)
		{
			if (j < length)
			{
				board[i][j] = line[j];
			}
			else
			{
				board[i][j] = '\0';
			}

		}
	}

	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (board[j][i] != '\0')
			{
				cout << board[j][i];
			}
		}
	}
}


/*

[input]
AABCDD
afzz
09121
a8EWg6
P5h3kx

result : Aa0aPAf985Bz1EhCz2W3D1gkD6x

*/