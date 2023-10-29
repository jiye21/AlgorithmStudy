// boj10810 공 넣기 https://www.acmicpc.net/problem/10810 2023-10-23
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int size, case_count;

	cin >> size >> case_count;
	vector<int> balls(size, 0);

	for (int i = 0; i < case_count; i++)
	{
		int from, to, number;
		cin >> from >> to >> number;

		for (int j = from - 1; j < to; j++)
		{
			balls[j] = number;
		}
	}

	for (int ball : balls)
	{
		cout << ball << " ";
	}

}