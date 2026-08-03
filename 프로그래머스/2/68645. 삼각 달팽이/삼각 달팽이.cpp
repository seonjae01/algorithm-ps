#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    vector<vector<int>> snail(n, vector<int>(n));
    
    int dy[3] = { 1, 0, -1 };
    int dx[3] = { 0, 1, -1 };
    int dir = 0, cnt = 0, len = n;
    int y = 0, x = 0, k = 1;
    
    while (len > 0)
    {
        snail[y][x] = k++;
        cnt++;
        
        if (cnt == len)
        {
            dir = (dir + 1) % 3;
            len--;
            cnt = 0;
        }
        
        y += dy[dir];
        x += dx[dir];
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (snail[i][j] != 0)
                answer.push_back(snail[i][j]);
        }
    }
    
    return answer;
}