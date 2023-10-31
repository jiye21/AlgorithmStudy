// boj 10811 바구니 뒤집기 https://www.acmicpc.net/problem/10811

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void swap(vector<int> &basket, int from, int to)
{
	int swap_count = ceil(((double)to - from) / 2);
	for (int i = 0; i < swap_count; i++)
	{
		int temp = basket[from + i];
		basket[from + i] = basket[to - i];
		basket[to - i] = temp;
	}
}

int main()
{
	int size, case_count;

	cin >> size >> case_count;

	vector<int> basket(size);
	for (int i = 0; i < size; i++)
	{
		basket[i] = i + 1;
	}


	for (int i = 0; i < case_count; i++)
	{
		int from, to;

		cin >> from >> to;

		swap(basket, from - 1, to - 1);
	}

	for (int i = 0; i < size; i++)
	{
		cout << basket[i] << " ";
	}
	cout << endl;
}

/*

5 4
1 2
3 4
1 4
2 2
12345
21345
21435
34125
34125

*/