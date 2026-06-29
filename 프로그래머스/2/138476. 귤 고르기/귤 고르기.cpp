#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    map<int, int> tangmap;
    for (int t : tangerine)
    {
        tangmap[t]++;
    }
    
    vector<pair<int, int>> tangvec(tangmap.begin(), tangmap.end());
    sort(tangvec.begin(), tangvec.end(), [](const auto& a, const auto& b)
    {
        return a.second > b.second;
    });
    
    for (auto tang : tangvec)
    {
        k -= tang.second;
        answer++;
        if (k <= 0)
            break;
    }
    
    return answer;
}