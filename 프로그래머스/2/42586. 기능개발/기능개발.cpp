#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> remain;
    
    for (int i = 0; i < progresses.size(); i++)
    {
        remain.push_back((100 - progresses[i] + speeds[i] - 1) / speeds[i]);
    }
    
    int remainstd = remain[0];
    int donecnt = 1;
    
    for (int i = 1; i < progresses.size(); i++)
    {
        if (remain[i] <= remainstd)
        {
            donecnt++;
        }
        else
        {
            answer.push_back(donecnt);
            remainstd = remain[i];
            donecnt = 1;
        }
    }
    
    answer.push_back(donecnt);
    return answer;
}