#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <unordered_set>

using namespace std;

bool isPrime(int n)
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

int solution(string numbers) {
    vector<char> nums;
    for (int i = 0; i < numbers.length(); i++)
        nums.push_back(numbers[i]);
    sort(nums.begin(), nums.end());
    
    int answer = 0;
    unordered_set<string> checked;
    
    do
    {
        string tmp;
        for (auto it = nums.begin(); it != nums.end(); it++)
        {
            if (tmp.length() == 0 && *it == '0')
                continue;
            
            tmp += *it;
            
            if (find(checked.begin(), checked.end(), tmp) != checked.end())
                continue;

            checked.insert(tmp);
            if (isPrime(stoi(tmp)))
                answer++;
        }
    }
    while (next_permutation(nums.begin(), nums.end()));

    return answer;
}