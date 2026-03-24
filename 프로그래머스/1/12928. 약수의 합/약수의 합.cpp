#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            if (i == sqrt(n))
                answer += i;
            else
                answer += (n / i + i);
        }
    }

    return answer;
}