#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const pair<int, int>& a, const pair<int, int>& b)
{
    return a.first > b.first;
}

int getW(string mineral)
{
    if (mineral == "diamond") return 25;
    else if (mineral == "iron") return 5;
    else return 1;
}

int getF(int p, string mineral)
{
    if (p == 0) return 1;
    
    if (p == 1)
    {
        if (mineral == "diamond") return 5;
        else return 1;
    }
    
    if (mineral == "diamond") return 25;
    else if (mineral == "iron") return 5;
    else return 1;
}

int solution(vector<int> picks, vector<string> minerals) {
    int totalPick = picks[0] + picks[1] + picks[2];
    int maxMine = min((int)minerals.size(), totalPick * 5);
    vector<pair<int, int>> mine;

    int sum = 0, cnt = 0;
    for (int i = 1; i <= maxMine; i++)
    {
        sum += getW(minerals[i - 1]);
        cnt++;
        
        if (i % 5 == 0 || i == maxMine)
        {
            mine.push_back({sum, i - cnt});
            sum = 0;
            cnt = 0;
        }
    }
    
    sort(mine.begin(), mine.end(), compare);
    int answer = 0, pickIdx = 0;
    
    for (int i = 0; i < mine.size(); i++)
    {
        while (pickIdx < 3 && picks[pickIdx] == 0)
            pickIdx++;
        
        if (pickIdx >= 3) break;
        picks[pickIdx]--;
        
        int start = mine[i].second;
        int end = min((int)minerals.size(), start + 5);
        
        for (int j = start; j < end; j++)
            answer += getF(pickIdx, minerals[j]);
    }
    
    return answer;
}