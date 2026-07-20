#include <string>
#include <vector>
#include <iostream>
using namespace std;

string alpha = "AEIOU";
int answer, cnt;

void dfs(string cur, string tar)
{
    if (cur == tar)
    {
        answer += cnt;
        return;
    }
    
    if (cur.length() >= 5)
        return;
    
    for (int i = 0; i < 5; i++)
    {
        cnt++;
        dfs(cur + alpha[i], tar);
    }
}

int solution(string word) {
    dfs("", word);
    return answer;
}