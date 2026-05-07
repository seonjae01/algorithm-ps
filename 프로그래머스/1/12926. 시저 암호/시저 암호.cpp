#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    for (char c : s)
    {
        if (c == ' ')
        {
            answer += ' ';
            continue;
        }
        
        char st = isupper(c) ? 'A' : 'a';
        int i = (c - st + n) % 26 + st;
        answer += (char)i;
        
    }
    return answer;
}