#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    int l = 0, r = 0;
    int sum = sequence[0];
    
    while (l <= r && r < sequence.size())
    {
        if (sum == k)
        {
            if (answer.empty() || answer[1] - answer[0] > r - l)
                answer = { l , r };
            sum -= sequence[l];
            l++;
        }
        else if (sum > k)
        {
            sum -= sequence[l];
            l++;
        }
        else
        {
            r++;
            sum += sequence[r];
        }
    }
    
    return answer;
}