/**
* BOJ10825 국영수 https://www.acmicpc.net/problem/10825
* 
* 엄청 느리지만 성공.
* sort() 함수를 사용하는 방법이 있지만
* 머지소트 연습겸 실제로 구현해봤다.
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Student
{
	string name;
	int korean;
	int english;
	int mathematics;
};
/*
도현이네 반 학생 N명의 이름과 국어, 영어, 수학 점수가 주어진다. 이때, 다음과 같은 조건으로 학생의 성적을 정렬하는 프로그램을 작성하시오.

국어 점수가 감소하는 순서로
국어 점수가 같으면 영어 점수가 증가하는 순서로
국어 점수와 영어 점수가 같으면 수학 점수가 감소하는 순서로
모든 점수가 같으면 이름이 사전 순으로 증가하는 순서로 (단, 아스키 코드에서 대문자는 소문자보다 작으므로 사전순으로 앞에 온다.)

*/
int student_compare(Student &s1, Student &s2)
{
	int result = s1.name.compare(s2.name);
	if (s1.korean != s2.korean != 0)
	{
		result = s1.korean < s2.korean;
	}
	else if (s1.english != s2.english)
	{
		result = s1.english > s2.english;
	}
	else if (s1.mathematics != s2.mathematics)
	{
		result = s1.mathematics < s2.mathematics;
	}

	return result;
}

vector<Student> merge(vector<Student> left, vector<Student> right)
{
	int left_index = 0;
	int right_index = 0;

	int left_length = left.size();
	int right_length = right.size();

	vector<Student> result;
	
	while (left_index < left_length && right_index < right_length)
	{
		if (student_compare(left[left_index], right[right_index]) <= 0)
		{
			result.push_back(left[left_index++]);
		}
		else
		{
			result.push_back(right[right_index++]);
		}
	}

	while (left_index < left_length)
	{
		result.push_back(left[left_index++]);
	}

	while (right_index < right_length)
	{
		result.push_back(right[right_index++]);
	}
	
	return result;
}

vector<Student> merge_sort(vector<Student> array)
{
	int length = array.size();
	if (length == 1) {
		return array;
	}
	vector<Student> left;
	vector<Student> right;
	int mid = length / 2;

	for (int i = 0; i < mid; i++)
	{
		left.push_back(array[i]);
	}
	for (int i = mid; i < length; i++)
	{
		right.push_back(array[i]);
	}

	vector<Student> merged = merge(merge_sort(left), merge_sort(right));

	return merged;
}

int main()
{
	int student_count;
	vector<Student> array;

	cin >> student_count;

	for (int i = 0; i < student_count; i++)
	{
		string name;
		int korean, english, mathematics;

		cin >> name >> korean >> english >> mathematics;

		Student s = { name, korean, english, mathematics };
		array.push_back(s);
	}

	array = merge_sort(array);

	//sort(array.begin(), array.end(), student_compare);

	for (int i = 0; i < student_count; i++)
	{
		cout << array[i].name << '\n';
	}

}

/*
12
Junkyu 50 60 100
Sangkeun 80 60 50
Sunyoung 80 70 100
Soong 50 60 90
Haebin 50 60 100
Kangsoo 60 80 100
Donghyuk 80 60 100
Sei 70 70 70
Wonseob 70 70 90
Sanghyun 70 70 80
nsj 80 80 80
Taewhan 50 60 90
*/