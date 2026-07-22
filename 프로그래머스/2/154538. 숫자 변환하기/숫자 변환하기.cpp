#include <vector>
#include <queue>

using namespace std;

int bfs(int x, int y, int n)
{
    if (x == y)
        return 0;
    
    vector<bool> visited(1000001, false);
    queue<pair<int, int>> q;
    q.push({x, 0});
    
    while (!q.empty())
    {
        auto [p, cnt] = q.front();
        q.pop();
        
        if (p == y)
            return cnt;
        
        int next[3] = { p + n, p * 2, p * 3 };
        for (int i = 0; i < 3; i++)
        {
            int nxt = next[i];
            if (nxt <= y && !visited[nxt])
            {
                visited[nxt] = true;
                q.push({nxt, cnt + 1});
            }
        }
    }
    
    return -1;
}

int solution(int x, int y, int n) {
    return bfs(x, y, n);
}