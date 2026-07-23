#include <vector>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    
    for (long long number : numbers)
    {
        if (number % 2 == 0)
        {
            answer.push_back(number + 1);            
        }
        else
        {
            long long bit = ~number & (number + 1);
            long long num = number + bit - (bit >> 1);
            answer.push_back(num);
        }
    }
    
    return answer;
}