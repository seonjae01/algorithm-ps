#include <string>
#include <vector>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    vector<int> s;
    
    for (int i : ingredient)
    {
        s.push_back(i);
        int size = s.size();
        
        if (size >= 4)
        {
            if (s[size - 1] == 1 && s[size - 2] == 3 && s[size - 3] == 2 && s[size - 4] == 1)
            {
                s.pop_back();
                s.pop_back();
                s.pop_back();
                s.pop_back();
                answer++;
            }
        }
    }
    
    return answer;
}