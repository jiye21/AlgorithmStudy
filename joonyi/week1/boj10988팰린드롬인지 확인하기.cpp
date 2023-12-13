// boj 10988 https://www.acmicpc.net/problem/10988 팰린드롬인지 확인하기

#include <iostream>
#include <vector>

using namespace std;

int is_palindrome(string str)
{
	int length = str.length();
	int count = length / 2;

	int result = 1;
	for (int i = 0; i < count; i++)
	{
		int front_index = 0 + i;
		int back_index = length - 1 - i;

		if (str[front_index] != str[back_index])
		{
			result = 0;
		}
	}

	return result;
}

int main()
{
	string str;
	cin >> str;

	cout << is_palindrome(str);
}