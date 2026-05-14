#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> food) {
    string answer = "";
    for (int i = 1; i < food.size(); i++)
    {
        int count = food[i];
        if (count == 1)
            continue;
        
        if (count % 2 != 0)
            count--;
        count /= 2;
        
        while (count--)
            answer += to_string(i);
    }
    
    string temp = answer;
    reverse(temp.begin(), temp.end());
    answer += "0";
    answer += temp;
    return answer;
}