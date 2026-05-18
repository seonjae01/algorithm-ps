#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    multiset<int, greater<int>> temp;
    multiset<int>::iterator it;
    
    for (int n : score)
    {
        temp.insert(n);
        
        if (temp.size() < k)
            it = next(temp.begin(), temp.size() - 1);
        else
            it = next(temp.begin(), k - 1);
        answer.push_back(*it);
    }
    return answer;
}