#include <iostream>
#include <stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        stack<char> st;
        string result = "YES";
        string ps;
        cin >> ps;

        for (char c : ps)
        {
            if (c == '(')
                st.push(c);
            else if (!st.empty() && c == ')' && st.top() == '(')
                st.pop();
            else
            {
                result = "NO";
                break;
            }
        }

        if (!st.empty())
            result = "NO";
        cout << result << '\n';
    }

    return 0;
}
