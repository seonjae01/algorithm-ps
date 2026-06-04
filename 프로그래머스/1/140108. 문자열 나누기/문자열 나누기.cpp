#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    int cntx = 0, cnto = 0;
    char x;
    
    for (char c : s)
    {
        if (cntx == 0)
            x = c;
        
        if (c == x)
            cntx++;
        else
            cnto++;
        
        if (cntx == cnto)
        {
            answer++;
            cntx = 0;
            cnto = 0;
        }
    }
    
    if (cntx != cnto)
        answer++;
    return answer;
}