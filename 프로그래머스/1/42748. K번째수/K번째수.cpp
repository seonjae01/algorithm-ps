#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for (auto com : commands)
    {
        vector<int> temp;
        
        for (int i = com[0] - 1; i < com[1]; i++)
            temp.push_back(array[i]);
        sort(temp.begin(), temp.end());
        answer.push_back(temp[com[2] - 1]);
    }
    return answer;
}