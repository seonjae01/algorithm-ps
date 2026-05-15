#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;
    while (n >= a)
    {
        int c = n / a;
        n = b * c + n % a;
        answer += b * c;
    }
    return answer;
}