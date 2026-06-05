#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    map<char, int> alphamap;
    
    for (auto km : keymap)
    {
        for (int i = 0; i < km.size(); i++)
        {
            char c = km[i];
            int n = alphamap[c];
            if (n == 0)
                alphamap[c] = i + 1;
            else
            {
                int mn = min(n, i + 1);
                alphamap[c] = mn;
            }
        }
    }
    
    for (auto target : targets)
    {
        int sum = 0;
        for (auto c : target)
        {
            int n = alphamap[c];
            if (n == 0)
            {
                sum = -1;
                break;
            }
            sum += n;
        }
        answer.push_back(sum);
    }
    
    return answer;
}