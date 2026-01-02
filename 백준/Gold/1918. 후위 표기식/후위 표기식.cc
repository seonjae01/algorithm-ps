#include <bits/stdc++.h>
using namespace std;

int priority(char c)
{
    if (c == '*' || c == '/')
        return 2;
    if (c == '+' || c == '-')
        return 1;
    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string infix;
    cin >> infix;

    stack<char> st;
    for (char c : infix)
    {
        if (isalpha(c))
            cout << c;
        else if (c == '(')
            st.push(c);
        else if (c == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                cout << st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while (!st.empty() && priority(st.top()) >= priority(c))
            {
                cout << st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty())
    {
        cout << st.top();
        st.pop();
    }

    return 0;
}
