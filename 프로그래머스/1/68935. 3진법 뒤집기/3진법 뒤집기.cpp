#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n) {
    string rev = "";
    while (n)
    {
        rev += (n % 3 + '0');
        n /= 3;
    }
    reverse(rev.begin(), rev.end());
    
    int answer = 0, mul = 1;
    for (char c : rev)
    {
        answer += ((c - '0') * mul);
        mul *= 3;
    }
    return answer;
}