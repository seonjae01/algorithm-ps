#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int r = 3;
    int c = (brown + yellow) / r;
    
    while (r <= c)
    {
        if ((r - 2) * (c - 2) == yellow)
        {
            answer.push_back(c);
            answer.push_back(r);
            break;
        }
        
        r++;
        c = (brown + yellow) / r;
    }
    
    return answer;
}