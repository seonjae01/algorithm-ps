#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) { 
    string answer = "";
    
    for (char n : number)
    {
        while (!answer.empty() && k > 0 && answer.back() < n)
        {
            k--;
            answer.pop_back();
        }
        answer.push_back(n);
    }
    
    while (k--)
        answer.pop_back();
    
    return answer;
}