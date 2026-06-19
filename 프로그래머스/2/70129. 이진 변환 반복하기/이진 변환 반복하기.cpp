#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer(2);
    
    while (s.length() != 1)
    {
        int rmvcnt = 0;
        for (char c : s)
        {
            if (c == '0')
                rmvcnt++;
        }
    
        int n = s.length() - rmvcnt;
        s = "";
        
        while (n > 0)
        {
            s = (n % 2 == 0 ? '0' : '1') + s;
            n /= 2;
        }
        
        answer[0]++;
        answer[1] += rmvcnt;
    }
    
    return answer;
}