#include <string>
#include <vector>
#include <queue>

using namespace std;

int bfs(int start, int n, vector<vector<int>> graph, int v1, int v2)
{
    vector<bool> visited(n + 1, false);
    queue<int> q;
    q.push(start);
    visited[start] = true;
    int count = 1;
    
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        
        for (int next : graph[cur])
        {
            if ((cur == v1 && next == v2)|| (cur == v2 && next == v1))
                continue;
            
            if (visited[next])
                continue;
            
            q.push(next);
            visited[next] = true;
            count++;
        }
    }
    
    return abs(count * 2 - n);
}

int solution(int n, vector<vector<int>> wires) {
    vector<vector<int>> graph(n + 1);
    
    for (auto wire : wires)
    {
        int v1 = wire[0];
        int v2 = wire[1];
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    
    int answer = 101;   
    for (auto wire : wires)
    {
        int v1 = wire[0];
        int v2 = wire[1];
        answer = min(answer, bfs(v1, n, graph, v1, v2));
    }
    return answer;
}