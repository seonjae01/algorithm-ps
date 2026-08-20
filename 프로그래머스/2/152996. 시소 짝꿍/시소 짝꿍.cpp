#include <vector>
#include <map>

using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    map<double, long long> wmap;
    
    for (int w : weights)
        wmap[w]++;
    
    for (auto [w, i] : wmap)
    {
        answer += i * (i - 1) / 2;
        
        if (wmap.count(w * 4 / 3))
            answer += i * wmap[w * 4 / 3];
        
        if (wmap.count(w * 4 / 2))
            answer += i * wmap[w * 4 / 2];
        
        if (wmap.count(w * 3 / 2))
            answer += i * wmap[w * 3 / 2];
    }
    
    return answer;
}