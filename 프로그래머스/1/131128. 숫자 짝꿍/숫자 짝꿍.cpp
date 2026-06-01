#include <string>
#include <vector>

using namespace std;

string solution(string X, string Y) {
    string answer = "";
    int xmap[10] = { 0 };
    int ymap[10] = { 0 };
    
    for (char xc : X)
        xmap[xc - '0']++;
    for (char yc : Y)
        ymap[yc - '0']++;
    
    for (int i = 9; i >= 0; i--)
    {
        if (i == 0 && answer == "")
        {
            answer = xmap[0] == 0 || ymap[0] == 0 ? "-1" : "0";
            break;
        }
        
        while (xmap[i]-- > 0 && ymap[i]-- > 0)
            answer += (i + '0');
    }
    
    return answer;
}