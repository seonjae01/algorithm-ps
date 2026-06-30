#include <string>
#include <vector>
#include <stack>

using namespace std;

int ispellindrome(string s)
{
    stack<char> stk;
    stk.push(s[0]);
    
    for (int i = 1; i < s.length(); i++)
    {
        char c = s[i];
        if (c == '[' || c == '(' || c == '{')
        {
            stk.push(c);
        }
        else
        {
            if (stk.empty())
                return 0;
            
            char top = stk.top();
            if ((top == '[' && c != ']') || 
                (top == '(' && c != ')') ||
                (top == '{' && c != '}'))
                return 0;
            
            stk.pop();
        }
    }
    
    return stk.empty() ? 1 : 0;
}

int solution(string s) {
    int answer = 0;
    int len = s.length();
    
    if (len % 2 != 0)
        return 0;
    
    for (int i = 0; i < len; i++)
    {
        char c = s[len - 1];
        s.pop_back();
        s = c + s;
        answer += ispellindrome(s);
    }
    
    return answer;
}