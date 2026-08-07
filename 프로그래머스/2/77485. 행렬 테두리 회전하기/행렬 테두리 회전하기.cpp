#include <string>
#include <vector>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<vector<int>> grid(rows, vector<int>(columns));
    vector<int> answer;
    int cnt = 1;
    
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
            grid[i][j] = cnt++;
    }
    
    for (auto query : queries)
    {
        auto temp = grid;
        int mn = 10001;
        int y1 = query[0] - 1;
        int x1 = query[1] - 1;
        int y2 = query[2] - 1;
        int x2 = query[3] - 1;
        
        for (int i = x2; i > x1; i--)
        {
            grid[y1][i] = grid[y1][i - 1];
            mn = min(mn, grid[y1][i]);
        }
        
        for (int i = y2; i > y1; i--)
        {
            grid[i][x2] = grid[i - 1][x2];
            mn = min(mn, grid[i][x2]);
        }
        
        grid[y1 + 1][x2] = temp[y1][x2];
        mn = min(mn, grid[y1 + 1][x2]);
        
        for (int i = x1; i < x2; i++)
        {            
            grid[y2][i] = grid[y2][i + 1];
            mn = min(mn, grid[y2][i]);
        }
        
        grid[y2][x2 - 1] = temp[y2][x2];
        mn = min(mn, grid[y2][x2 - 1]);
        
        for (int i = y1; i < y2; i++)
        {
            grid[i][x1] = grid[i + 1][x1];
            mn = min(mn, grid[i][x1]);
        }
        
        grid[y2 - 1][x1] = temp[y2][x1];
        mn = min(mn, grid[y2 - 1][x1]);
        
        answer.push_back(mn);
    }
    
    return answer;
}