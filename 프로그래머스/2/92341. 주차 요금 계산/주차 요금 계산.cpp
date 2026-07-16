#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <map>
#include <cmath>

using namespace std;

int getMin(string time)
{
    return stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3, 2));
}

vector<int> solution(vector<int> fees, vector<string> records) {
    unordered_map<string, int> timeRecords;
    unordered_map<string, bool> outRecords;
    map<string, int> totalRecords;
    vector<int> answer;
    
    for (string record : records)
    {
        istringstream iss(record);
        string carnum, time, park;
        iss >> time >> carnum >> park;
        
        if (park == "IN")
        {
            timeRecords[carnum] = getMin(time);
            outRecords[carnum] = false;
        }
        else
        {
            int total = getMin(time) - timeRecords[carnum];
            totalRecords[carnum] += total;
            outRecords[carnum] = true;
        }
    }
    
    for (auto [carnum, park] : outRecords)
    {
        if (!park)
        {
            totalRecords[carnum] += (getMin("23:59") - timeRecords[carnum]);
        }
    }
    
    for (auto [carnum, total] : totalRecords)
    {
        int cost = fees[1];
        if (total > fees[0])
        {
            cost += ceil((double)(total - fees[0]) / fees[2]) * fees[3];
        }
        answer.push_back(cost);
    }
    
    return answer;
}