#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int getMinute(string time)
{
    string hour = time.substr(0, 2);
    string min = time.substr(3, 2);
    return stoi(hour) * 60 + stoi(min);
}

int solution(vector<vector<string>> book_time) {
    vector<int> room(book_time.size(), 0);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (auto book : book_time)
    {
        pq.push({getMinute(book[0]), getMinute(book[1]) + 10});
    }
    
    int answer = 0;
    while (!pq.empty())
    {
        auto [start, end] = pq.top();
        pq.pop();
        
        for (int i = 0; i < room.size(); i++)
        {
            if (room[i] <= start)
            {
                room[i] = end;
                answer = max(answer, i + 1);
                break;
            }
        }
    }
    
    return answer;
}