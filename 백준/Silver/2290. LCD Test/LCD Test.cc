#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int s;
    string n;

    cin >> s >> n;
    vector<string> lcd;
    int height = 2 * s + 3;

    for (int i = 0; i < height; i++)
    {
        string line = "";
        for (char c : n)
        {
            string part;

            if (i == 0)
            {
                if (string("23567890").find(c) != string::npos)
                    part = " " + string(s, '-') + " ";
                else
                    part = " " + string(s, ' ') + " ";
            }
            else if (i > 0 && i < height / 2)
            {
                char left = (string("456890").find(c) != string::npos) ? '|' : ' ';
                char right = (string("12347890").find(c) != string::npos) ? '|' : ' ';
                part = string(1, left) + string(s, ' ') + string(1, right);
            }
            else if (i == height / 2)
            {
                if (string("2345689").find(c) != string::npos)
                    part = " " + string(s, '-') + " ";
                else
                    part = " " + string(s, ' ') + " ";
            }
            else if (i > height / 2 && i < height - 1)
            {
                char left = (string("2680").find(c) != string::npos) ? '|' : ' ';
                char right = (string("134567890").find(c) != string::npos) ? '|' : ' ';
                part = string(1, left) + string(s, ' ') + string(1, right);
            }
            else
            {
                if (string("2356890").find(c) != string::npos)
                    part = " " + string(s, '-') + " ";
                else
                    part = " " + string(s, ' ') + " ";
            }

            line += part;
            if (i < height)
                line += " ";
        }

        cout << line << '\n';
    }
}
