#include <string>
#include <vector>
#include <queue>

using namespace std;

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int solution(vector<string> board) {
    int n = board.size();
    int m = board[0].size();
    int start_x, start_y, end_x, end_y;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 'R')
            {
                start_y = i;
                start_x = j;
            }
            else if (board[i][j] == 'G')
            {
                end_y = i;
                end_x = j;
            }
        }
    }
    
    queue<tuple<int, int, int>> q;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    q.push({start_y, start_x, 0});
    visited[start_y][start_x] = true;
    
    while (!q.empty())
    {
        auto [y, x, cnt] = q.front();
        q.pop();
        
        if (y == end_y && x == end_x)
            return cnt;
        
        for (int i = 0; i < 4; i++)
        {
            int ny = y;
            int nx = x;

            while (true)
            {
                int next_y = ny + dy[i];
                int next_x = nx + dx[i];

                if (next_y < 0 || next_y >= n || next_x < 0 || next_x >= m || board[next_y][next_x] == 'D')
                    break;
                
                ny = next_y;
                nx = next_x;
            }
            
            if ((ny == y && nx == x) || visited[ny][nx])
                continue;
            
            q.push({ny, nx, cnt + 1});
            visited[ny][nx] = true;
        }
    }
    
    return -1;
}