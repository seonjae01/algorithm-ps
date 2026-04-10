#include <iostream>
#include <stack>
#include <sstream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line;
    getline(cin, line);

    while (line != ".")
    {
        stack<char> stk;
        for (char c : line)
        {
            if (c == '(' || c == '[')
            {
                stk.push(c);
            }
            else if (c == ')' && !stk.empty() && stk.top() == '(')
            {
                stk.pop();
            }
            else if (c == ']' && !stk.empty() && stk.top() == '[')
            {
                stk.pop();
            }
            else if (c == ')' && (stk.empty() || (!stk.empty() && stk.top() == '[')))
            {
                stk.push(c);
                break;
            }
            else if (c == ']' && (stk.empty() || !stk.empty() && stk.top() == '('))
            {
                stk.push(c);
                break;
            }
        }

        cout << (stk.empty() ? "yes" : "no") << '\n';
        getline(cin, line);
    }

    return 0;
}
