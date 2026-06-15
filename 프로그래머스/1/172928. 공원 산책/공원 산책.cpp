#include <string>
#include <vector>

using namespace std;

bool canMove(vector<string>& park, int y, int x)
{
    return y >= 0 && park.size() > y && x >= 0 && park[0].size() > x && park[y][x] != 'X';
}

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    int y, x;
    
    for (int i = 0; i < park.size(); i++)
    {
        bool found = false;
        for (int j = 0; j < park[0].size(); j++)
        {
            if (park[i][j] == 'S')
            {
                y = i;
                x = j;
                found = true;
                break;
            }
        }
        
        if (found) break;
    }
    
    for (string route : routes)
    {
        char dir = route[0];
        int len = stoi(route.substr(2, route.size() - 2));
        int dy = 0, dx = 0;
        
        switch (dir)
        {
            case 'N':
                dy = -1;
                break;
                
            case 'S':
                dy = 1;
                break;
                
            case 'W':
                dx = -1;
                break;
                
            case 'E':
                dx = 1;
                break;
        }
        
        int ny = y, nx = x;
        bool canmove = true;
        
        for (int i = 0; i < len; i++)
        {
            ny += dy;
            nx += dx;
            
            if (!canMove(park, ny, nx))
            {
                canmove = false;
                break;
            }
        }
        
        if (canmove)
        {
            y = ny;
            x = nx;
        }
    }
    
    answer.push_back(y);
    answer.push_back(x);
    return answer;
}