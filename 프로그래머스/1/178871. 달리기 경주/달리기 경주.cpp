#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer = players;
    unordered_map<string, int> playermap;
    
    for (int i = 0; i < players.size(); i++)
    {
        playermap[players[i]] = i;
    }
    
    for (string calling : callings)
    {
        int called = playermap[calling];
        int front = called - 1;
        
        playermap[calling] = front;
        playermap[answer[front]] = called;
        swap(answer[called], answer[front]);
    }
    
    return answer;
}