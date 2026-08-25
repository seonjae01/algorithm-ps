#include <string>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int sx, sy, lx, ly, ex, ey;

int bfs(vector<string> maps, int start_y, int start_x, int target_y, int target_x)
{
    int n = maps.size();
    int m = maps[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<tuple<int, int, int>> q;
    
    q.push({start_y, start_x, 0});
    visited[start_y][start_x] = true;
    
    while (!q.empty())
    {
        auto [y, x, cnt] = q.front();
        q.pop();
        
        if (y == target_y && x == target_x)
            return cnt;
        
        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if (ny < 0 || ny >= n || nx < 0 || nx >= m)
                continue;
            
            if (visited[ny][nx] || maps[ny][nx] == 'X')
                continue;
            
            q.push({ny, nx, cnt + 1});
            visited[ny][nx] = true;
        }
    }
    
    return -1;
}

int solution(vector<string> maps) {
    for (int i = 0; i < maps.size(); i++)
    {
        for (int j = 0; j < maps[i].size(); j++)
        {
            if (maps[i][j] == 'S')
            {
                sy = i;
                sx = j;
            }
            else if (maps[i][j] == 'L')
            {
                ly = i;
                lx = j;
            }
            else if (maps[i][j] == 'E')
            {
                ey = i;
                ex = j;
            }
        }
    }
    
    int before = bfs(maps, sy, sx, ly, lx);
    if (before < 0) return -1;
    
    int after = bfs(maps, ly, lx, ey, ex);
    if (after < 0) return -1;
    
    return before + after;
}