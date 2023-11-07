//boj 2563 색종이 https://www.acmicpc.net/problem/2563

#include <iostream>

using namespace std;

int main()
{
	bool board[101][101] = { 0 };

	int case_count;

	cin >> case_count;

	for (int i = 0; i < case_count; i++)
	{
		int from_x, from_y;
		cin >> from_x >> from_y;

		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				board[from_y + i][from_x + j] = 1;
			}
		}
	}

	int result = 0;
	for (int i = 1; i <= 100; i++)
	{
		for (int j = 1; j <= 100; j++)
		{
			if (board[i][j] != 0)
				result += board[i][j];
		}
	}

	cout << result;
}