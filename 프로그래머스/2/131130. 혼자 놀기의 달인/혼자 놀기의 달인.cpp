#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> cards) {
    int answer = 0;
    int n = cards.size();
    vector<bool> visited(n, false);
    vector<int> group;
    
    for (int i = 0; i < n; i++)
    {
        if (visited[i])
            continue;
        
        int idx = i;
        int cnt = 0;
        
        while (!visited[idx])
        {
            visited[idx] = true;
            idx = cards[idx] - 1;
            cnt++;
        }
        
        group.push_back(cnt);
    }
    
    if (group.size() == 1)
        return 0;
    
    sort(group.begin(), group.end(), greater<int>());
    return group[0] * group[1];
}