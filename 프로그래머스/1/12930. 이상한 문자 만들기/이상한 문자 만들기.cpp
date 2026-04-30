#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    answer += toupper(s[0]);
    
    int idx = 1;
    for (int i = 1; i < s.length(); i++)
    {
        if (s[i - 1] == ' ')
            idx = 0;
        answer += (idx++ % 2 != 0) ? tolower(s[i]) : toupper(s[i]);
    }
    
    return answer;
}