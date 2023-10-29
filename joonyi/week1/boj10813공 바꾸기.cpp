// boj 10813 공 바꾸기 https://www.acmicpc.net/problem/10813 2023-10-24
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int size, swap_count;

	cin >> size >> swap_count;

	vector<int> baskets(size);

	for (int i = 0; i < size; i++)
	{
		baskets[i] = i + 1;
	}

	for (int i = 0; i < swap_count; i++)
	{
		int from, to;
		cin >> from >> to;

		from--;
		to--;

		int temp = baskets[from];
		baskets[from] = baskets[to];
		baskets[to] = temp;
	}

	for (int ball : baskets)
	{
		cout << ball << " ";
	}
	cout << endl;

}