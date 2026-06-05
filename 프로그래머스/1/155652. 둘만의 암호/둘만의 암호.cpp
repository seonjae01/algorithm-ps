#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    map<char, int> skipmap;
    for (char c : skip)
        skipmap[c] = 1;
    
    for (char c : s)
    {
        for (int i = 0; i < index; i++)
        {
            c++;
            if (c > 'z') c = 'a';
            
            while (skipmap[c] > 0)
            {
                c += skipmap[c];
                if (c > 'z') c = 'a';
            }
        }
        answer += c;
    }
    return answer;
}