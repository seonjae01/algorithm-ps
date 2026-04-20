#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solve(int n)
{
    int cnt = 0;
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            if (i == sqrt(n))
                cnt++;
            else
                cnt += 2;
        }
    }
    
    return cnt;
}

int solution(int left, int right) {
    int answer = 0;
    for (int i = left; i <= right; i++)
    {
        if (solve(i) % 2 == 0)
            answer += i;
        else
            answer -= i;
    }
    return answer;
}