#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n - lost.size();
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    
    for (int i = 0; i < lost.size(); i++)
    {
        for (int j = 0; j < reserve.size(); j++)
        {
            if (lost[i] == reserve[j])
            {
                lost[i] = -1;
                reserve[j] = -1;
                answer++;
                break;
            }
        }
    }
    
    for (int i = 0; i < lost.size(); i++)
    {
        int prev = lost[i] - 1;
        int next = lost[i] + 1;
        for (int j = 0; j < reserve.size(); j++)
        {
            if (reserve[j] == prev || reserve[j] == next)
            {
                lost[i] = -1;
                reserve[j] = -1;
                answer++;
                break;
            }
        }
    }
    
    return answer;
}