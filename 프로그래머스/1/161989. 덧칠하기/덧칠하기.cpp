#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    int painted = 0;
    
    for (int s : section)
    {
        if (painted > s)
            continue;
        
        painted = s + m;
        answer++;
    }
    return answer;
}