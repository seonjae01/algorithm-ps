#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    unordered_map<string, int> prods;
    for (int i = 0; i < want.size(); i++)
        prods[want[i]] = number[i];
    
    for (int i = 0; i <= discount.size() - 10; i++)
    {
        unordered_map<string, int> temp;
        for (int j = i; j < i + 10; j++)
            temp[discount[j]]++;
        
        bool join = true;
        for (auto [s, k] : prods)
        {
            if (temp[s] != k)
            {
                join = false;
                break;
            }
        }
        
        if (join)
            answer++;
    }
    
    return answer;
}