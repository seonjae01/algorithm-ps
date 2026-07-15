#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

bool isPrime(long long n)
{
    if (n == 1)
        return false;
    
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return false;
    }
    
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    string base = "";
    
    while (n > 0)
    {
        base += to_string(n % k);
        n /= k;
    }
    reverse(base.begin(), base.end());
    
    for (int i = 0; i < base.length(); i++)
    {
        if (base[i] == '0')
            continue;
        
        string num = "";
        num += base[i];
        
        for (int j = i + 1; j < base.length(); j++)
        {
            i = j;
            if (base[j] != '0')
            {
                num += base[j];
            }
            else break;
        }
        
        if (isPrime(stoll(num)))
            answer++;
    }
    
    return answer;
}