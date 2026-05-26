#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> pt2 = { 1, 3, 4, 5 };
    vector<int> pt3 = { 3, 1, 2, 4, 5 };
    int ans1 = 0, ans2 = 0, ans3 = 0;
    
    for (int i = 0; i < answers.size(); i++)
    {
        int ans = answers[i];
        
        // case 1
        if (i % 5 + 1 == ans)
            ans1++;
        
        // case 2
        if (i % 2 == 0 && ans == 2)
            ans2++;
        if (i % 2 != 0 && pt2[(i / 2) % 4] == ans)
            ans2++;
        
        // case 3
        if (pt3[(i / 2) % 5] == ans)
            ans3++;
    }
    
    int mx = max(ans1, max(ans2, ans3));
    if (ans1 == mx) answer.push_back(1);
    if (ans2 == mx) answer.push_back(2);
    if (ans3 == mx) answer.push_back(3);
    return answer;
}