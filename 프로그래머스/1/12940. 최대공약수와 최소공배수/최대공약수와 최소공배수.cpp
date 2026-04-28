#include <string>
#include <vector>
#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    while (b > 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    
    return a;
}

vector<int> solution(int n, int m) {
    vector<int> answer;
    int a = gcd(n, m);
    int b = (n * m) / a;
    answer.push_back(a);
    answer.push_back(b);
    return answer;
}