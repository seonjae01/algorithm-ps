#include <string>
#include <vector>

using namespace std;

vector<vector<bool>> visited;
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

bool dfs(vector<string> place, int y, int x, int d)
{
    if (d > 2)
        return true;
    
    if (d > 0 && place[y][x] == 'P')
        return false;
    
    if (d > 0 && place[y][x] == 'X')
        return true;
    
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        
        if (ny < 0 || ny >= 5 || nx < 0 || nx >= 5 || visited[ny][nx])
            continue;
        
        visited[ny][nx] = true;
        if (!dfs(place, ny, nx, d + 1)) return false;
        visited[ny][nx] = false;
    }
    
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for (auto place : places)
    {
        bool canPlace = true;
        for (int i = 0; i < 5 && canPlace; i++)
        {
            for (int j = 0; j < 5 && canPlace; j++)
            {
                if (place[i][j] != 'P')
                    continue;
                
                visited.assign(5, vector<bool>(5, false));
                visited[i][j] = true;
                canPlace = dfs(place, i, j, 0);
            }
        }
        
        answer.push_back(canPlace ? 1 : 0);
    }
    
    return answer;
}