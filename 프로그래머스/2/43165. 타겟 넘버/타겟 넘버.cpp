#include <vector>

using namespace std;

int answer;

void targetNumber(vector<int> numbers, int idx, int sign, int current, int target)
{
    current += (numbers[idx] * sign);
    if (idx == numbers.size() - 1)
    {
        if (current == target)
            answer++;
        return;
    }

    targetNumber(numbers, idx + 1, sign, current, target);
    targetNumber(numbers, idx + 1, sign * -1, current, target);
}

int solution(vector<int> numbers, int target) {
    targetNumber(numbers, 0, 1, 0, target);
    targetNumber(numbers, 0, -1, 0, target);
    return answer;
}