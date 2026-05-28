#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int cnt = 0, zcnt = 0;
    
    for (int i = 0; i < 6; i++)
    {
        int lotto = lottos[i];
        if (lotto == 0) zcnt++;
        else if (find(win_nums.begin(), win_nums.end(), lotto) != win_nums.end()) cnt++;
    }
    
    int rank = 7 - cnt;
    int frank = rank - zcnt;
    answer.push_back(frank > 6 ? 6 : frank);
    answer.push_back(rank > 6 ? 6 : rank);
    return answer;
}