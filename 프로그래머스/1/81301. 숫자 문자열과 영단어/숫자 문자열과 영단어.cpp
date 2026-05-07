#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];
        answer *= 10;
        switch (c)
        {
            case 'z':
                i += 3;
                break;
            case 'o':
                answer += 1;
                i += 2;
                break;
            case 't':
                if (s[i + 1] == 'w')
                {
                    answer += 2;
                    i += 2;
                }
                else
                {
                    answer += 3;
                    i += 4;
                }
                break;
            case 'f':
                if (s[i + 1] == 'o')
                    answer += 4;
                else
                    answer += 5;
                i += 3;
                break;
            case 's':
                if (s[i + 1] == 'i')
                {
                    answer += 6;
                    i += 2;
                }
                else
                {
                    answer += 7;
                    i += 4;
                }
                break;
            case 'e':
                answer += 8;
                i += 4;
                break;
            case 'n':
                answer += 9;
                i += 3;
                break;
            default:
                answer += (c - '0');
                break;
        }
    }
    return answer;
}