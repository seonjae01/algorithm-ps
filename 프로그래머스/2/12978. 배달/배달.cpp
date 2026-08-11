#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solution(int N, vector<vector<int> > road, int K) {
    vector<vector<pair<int, int>>> graph(N + 1);
    
    for (auto r : road)
    {
        graph[r[0]].push_back({r[1], r[2]});
        graph[r[1]].push_back({r[0], r[2]});
    }
    
    const int INF = 1e9;
    vector<int> dist(N + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});
    dist[1] = 0;
    
    while (!pq.empty())
    {
        auto [curW, cur] = pq.top();
        pq.pop();
        
        if (dist[cur] < curW)
            continue;
            
        for (auto [next, nextW] : graph[cur])
        {
            int cost = curW + nextW;
            if (cost >= dist[next])
                continue;
            
            pq.push({cost, next});
            dist[next] = cost;
        }
    }
    
    int answer = 0;
    for (int i = 1; i <= N; i++)
    {
        if (dist[i] <= K) answer++;
    }

    return answer;
}