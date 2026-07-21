#include <vector>
#include <iostream>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    unordered_set<int> left;
    unordered_map<int, int> right;
    
    for (int top : topping)
        right[top]++;
    
    for (int i = 0; i < topping.size(); i++)
    {
        int top = topping[i];
        left.insert(top);
        
        right[top]--;
        if (right[top] == 0)
            right.erase(top);
        
        if (left.size() == right.size())
            answer++;
    }
    
    return answer;
}