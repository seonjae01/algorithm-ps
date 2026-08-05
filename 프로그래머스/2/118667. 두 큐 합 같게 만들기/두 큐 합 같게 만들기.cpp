#include <vector>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    long long total = 0;
    long long q1sum = 0;
    
    for (int q : queue1)
    {
        total += q;
        q1sum += q;
    }
    for (int q : queue2)
    {
        total += q;
    }
    
    if (total % 2 != 0) return -1;
    long long half = total / 2;
    
    vector<int> v = queue1;
    v.insert(v.end(), queue2.begin(), queue2.end());
    
    int size = queue1.size();
    int l = 0, r = size;
    int maxcnt = size * 3;
    int answer = 0;
    
    while (answer <= maxcnt)
    {
        if (q1sum == half)
        {
            return answer;
        }
        else if (q1sum > half)
        {
            q1sum -= v[l];
            l = (l + 1) % v.size();
        }
        else
        {
            q1sum += v[r];
            r = (r + 1) % v.size();
        }
        
        answer++;
    }
    
    return -1;
}