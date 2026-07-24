#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int w = 0;
    int idx = 0;
    int time = 0;
    queue<int> q;
    
    while (true)
    {
        if (idx == truck_weights.size())
        {
            time += bridge_length;
            break;
        }
        
        if (q.size() == bridge_length)
        {
            w -= q.front();
            q.pop();
        }
        
        if (truck_weights[idx] + w <= weight)
        {
            q.push(truck_weights[idx]);
            w += truck_weights[idx];
            idx++;
        }
        else
        {
            q.push(0);
        }
        
        time++;
    }
    
    return time;
}