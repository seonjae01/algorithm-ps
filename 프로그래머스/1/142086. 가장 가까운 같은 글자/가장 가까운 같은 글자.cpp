#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string s) {
    map<char, int> alphamap;
    vector<int> answer;
    
    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];
        if (alphamap.find(c) != alphamap.end())
            answer.push_back(i - alphamap[c]);
        else
            answer.push_back(-1);
        alphamap[c] = i;
    }
    
    return answer;
}