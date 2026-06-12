#include <string>
#include <vector>
#include <map>

using namespace std;

int getDay(string date)
{
    string year = date.substr(0, 4);
    string month = date.substr(5, 2);
    string day = date.substr(8, 2);
    return stoi(year) * 12 * 28 + stoi(month) * 28 + stoi(day);
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    map<char, int> termmap;
    int currentDay = getDay(today);
    
    for (string term : terms)
    {
        termmap[term[0]] = stoi(term.substr(2, term.length() - 2));
    }
    
    for (int i = 0; i < privacies.size(); i++)
    {
        auto pri = privacies[i];
        int term = termmap[pri[11]];
        
        if (currentDay >= getDay(pri.substr(0, 10)) + term * 28)
        {
            answer.push_back(i + 1);            
        }
    }
    
    return answer;
}