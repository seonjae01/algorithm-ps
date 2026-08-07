#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
bool visited[101][101];

int dfs(vector<string> maps, int y, int x)
{
    int sum = maps[y][x] - '0';
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        
        if (ny < 0 || ny >= maps.size() || nx < 0 || nx >= maps[0].length())
            continue;
        
        if (visited[ny][nx] || maps[ny][nx] == 'X')
            continue;
        
        visited[ny][nx] = true;
        sum += dfs(maps, ny, nx);
    }
    
    return sum;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    
    for (int i = 0; i < maps.size(); i++)
    {
        for (int j = 0; j < maps[0].length(); j++)
        {
            if (!visited[i][j] && maps[i][j] != 'X')
            {
                visited[i][j] = true;
                answer.push_back(dfs(maps, i, j));
            }
        }
    }
    
    if (!answer.empty())
        sort(answer.begin(), answer.end());
    else
        answer = { -1 };
    return answer;
}