#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> nums) {
    vector<bool> primes(3001, true);
    int cnt = 0;
    int len = nums.size();

    primes[0] = primes[1] = false;
    for (int i = 2; i * i <= 3000; i++)
    {
        if (primes[i])
        {
            for (int j = i * i; j <= 3000; j += i)
                primes[j] = false;
        }
    }

    for (int i = 0; i < len; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            for (int k = j + 1; k < len; k++)
            {
                int num = nums[i] + nums[j] + nums[k];
                if (primes[num])
                    cnt++;
            }
        }
    }

    return cnt;
}