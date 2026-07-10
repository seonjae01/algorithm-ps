#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    int idx = 0;
    queue<pair<int, int>> q;
    
    for (int i = 0; i < priorities.size(); i++)
    {
        q.push({priorities[i], i});
    }
    
    sort(priorities.begin(), priorities.end(), greater<int>());
    
    while (!q.empty())
    {
        auto [p, i] = q.front();
        q.pop();
        
        if (p == priorities[idx])
        {
            idx++;
            if (i == location)
                break;
        }
        else
        {
            q.push({p, i});
        }
    }
    
    return idx;
}