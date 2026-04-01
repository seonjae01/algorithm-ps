#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(long long n) {
    string s = to_string(n);
    sort(s.begin(), s.end(), greater<int>());
    long long answer = 0;
    
    for (char c : s)
    {
        answer *= 10;
        answer += (c - '0');
    }

    return answer;
}