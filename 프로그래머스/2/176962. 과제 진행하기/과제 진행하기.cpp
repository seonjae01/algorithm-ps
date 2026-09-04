#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int getTime(string start)
{
    int startHour = stoi(start.substr(0, 2));
    int startMin = stoi(start.substr(3, 2));
    return startHour * 60 + startMin;
}

bool compare(const vector<string>& a, const vector<string>& b)
{
    return getTime(a[1]) < getTime(b[1]);
}

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    stack<pair<string, int>> st;
    sort(plans.begin(), plans.end(), compare);
    
    for (int i = 0; i < plans.size(); i++)
    {
        string name = plans[i][0];
        int curStart = getTime(plans[i][1]);
        int curPlaytime = stoi(plans[i][2]);
        int curEnd = curStart + curPlaytime;
        int nextStart = i + 1 < plans.size() ? getTime(plans[i + 1][1]) : 10000;
        
        if (curEnd <= nextStart)
        {
            answer.push_back(name);
            int leftTime = nextStart - curEnd;
            
            while (!st.empty() && leftTime > 0)
            {
                auto [prevName, prevLeftTime] = st.top();
                st.pop();
                
                if (prevLeftTime <= leftTime)
                {
                    leftTime -= prevLeftTime;
                    answer.push_back(prevName);
                }
                else
                {
                    st.push({prevName, prevLeftTime - leftTime});
                    leftTime = 0;
                }
            }
        }
        else
        {
            st.push({name, curEnd - nextStart});
        }
    }
    
    while (!st.empty())
    {
        auto [name, time] = st.top();
        st.pop();
        answer.push_back(name);
    }
    
    return answer;
}