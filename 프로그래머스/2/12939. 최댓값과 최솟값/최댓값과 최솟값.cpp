#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

void addNum(string& ans, long long num)
{
    string str = to_string(num);
    for (char c : str)
    {
        ans.push_back(c);
    }
}

string solution(string s) {
    string answer = "";
    string word;
    istringstream ss(s);
    vector<long long> nums;
    
    while (ss >> word)
    {
        nums.push_back(stol(word));
    }
    
    sort(nums.begin(), nums.end());
    addNum(answer, nums[0]);
    answer.push_back(' ');
    addNum(answer, nums[nums.size() - 1]);
    return answer;
}