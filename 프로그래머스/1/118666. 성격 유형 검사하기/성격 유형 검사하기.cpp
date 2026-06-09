#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool compare(const pair<char, int>& a, const pair<char, int>& b)
{
    return a.second > b.second;
}

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    string kakao = "RTCFJMAN";
    map<char, int> mbti;
    
    for (int i = 0; i < survey.size(); i++)
    {
        int cho = choices[i];
        if (cho < 4)
        {
            mbti[survey[i][0]] += (4 - cho);
        }
        else if (cho > 4)
        {
            mbti[survey[i][1]] += (cho - 4);
        }
    }
    
    vector<pair<char, int>> mbtivec(mbti.begin(), mbti.end());
    sort(mbtivec.begin(), mbtivec.end(), compare);
    
    for (int i = 0; i < 4; i++)
    {
        bool isFind = false;
        char tar1 = kakao[i * 2];
        char tar2 = kakao[i * 2 + 1];
        
        for (auto m : mbtivec)
        {
            if (m.first == tar1 || m.first == tar2)
            {
                isFind = true;
                answer += m.first;
                break;
            }
        }
        
        if (!isFind)
        {
            answer += tar1;            
        }
    }
    
    return answer;
}