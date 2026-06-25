#include <vector>

using namespace std;

int gcd(int a, int b)
{
    int tmp;
    while (b > 0)
    {
        tmp = a;
        a = b;
        b = tmp % b;
    }
    
    return a;
}

int lcm(int a, int b)
{
    return (a * b) / gcd(a, b);
}

int solution(vector<int> arr) {
    int answer = lcm(arr[0], arr[1]);
    for (int i = 2; i < arr.size(); i++)
    {
        answer = lcm(answer, arr[i]);
    }
    return answer;
}