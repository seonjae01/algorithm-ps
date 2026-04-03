#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
    int tmp;
    if (a > b)
    {
        tmp = b;
        b = a;
        a = tmp;
    }
    
    long long answer = 0;
    for (int i = a; i <= b; ++i)
        answer += i;
    return answer;
}