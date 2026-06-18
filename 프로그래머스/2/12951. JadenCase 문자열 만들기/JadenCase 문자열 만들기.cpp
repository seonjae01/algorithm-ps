#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    char c = ' ';
    
    for (int i = 0; i < s.length(); i++)
    {
        bool isWord = c == ' ';
        c = s[i];
        if (c == ' ')
        {
            answer += ' ';
        }
        else if (isalpha(c))
        {
            if (isWord) answer += toupper(c);
            else answer += tolower(c);
        }
        else
        {
            answer += c;
        }
    }
    
    return answer;
}