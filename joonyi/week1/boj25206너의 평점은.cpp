// boj 25206 너의 평점은 https://www.acmicpc.net/problem/25206
#include <iostream>
using namespace std;

int main() {

    string subject;
    double credit;
    string grade;

    double sum_point = 0;
    double sum_credit = 0;
    for (int i = 0; i < 20; i++)
    {
        cin >> subject >> credit >> grade;

        if (cin.eof() == true)
            break;

        double point = 0;

        if (grade == "P")
            continue;

        switch (grade[0])
        {
            case 'A':
                point = 4;
                break;
            case 'B':
                point = 3;
                break;
            case 'C':
                point = 2;
                break;
            case 'D':
                point = 1;
                break;
        }

        if (grade[1] == '+')
            point += 0.5;

        sum_credit += credit;
        point *= credit;
        sum_point += point;
    }

    cout.precision(7);
    if (sum_point != 0)
    {
        cout << sum_point / sum_credit << endl;
    }
    else
    {
        cout << sum_point << endl;
    }


    return 0;
}