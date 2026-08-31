#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    priority_queue<int> pq;
    int answer = 0;
    
    for (int e : enemy)
    {
        n -= e;
        pq.push(e);
        
        if (n < 0)
        {
            if (k > 0)
            {
                int t = pq.top();
                pq.pop();
                n += t;
                k--;
            }
            else
            {
                break;
            }
        }
        
        answer++;
    }
    
    return answer;
}