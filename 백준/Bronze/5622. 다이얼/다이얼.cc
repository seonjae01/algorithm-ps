#include <iostream>

using namespace std;

int dial[26] =
{
    2, 2, 2,
    3, 3, 3,
    4, 4, 4,
    5, 5, 5,
    6, 6, 6,
    7, 7, 7, 7,
    8, 8, 8,
    9, 9, 9, 9
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line;
    cin >> line;

    int time = line.size();
    for (char c : line)
        time += dial[c - 'A'];

    cout << time << '\n';
    return 0;
}
