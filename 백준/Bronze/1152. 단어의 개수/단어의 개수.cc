#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line;
    getline(cin, line);

    stringstream ss(line);
    vector<string> lines;

    while (getline(ss, line, ' '))
    {
        if (line != "")
            lines.push_back(line);
    }
    cout << lines.size() << '\n';

    return 0;
}
