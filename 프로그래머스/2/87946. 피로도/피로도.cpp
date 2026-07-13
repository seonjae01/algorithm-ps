#include <vector>

using namespace std;

int mx;
bool visited[9];

void solve(int cur, int cnt, vector<vector<int>> dungeons)
{
    for (int i = 0; i < dungeons.size(); i++)
    {
        if (!visited[i] && dungeons[i][0] <= cur)
        {
            visited[i] = true;
            solve(cur - dungeons[i][1], cnt + 1, dungeons);
            visited[i] = false;
        }
    }
    mx = max(mx, cnt);
}

int solution(int k, vector<vector<int>> dungeons) {
    solve(k, 0, dungeons);
    return mx;
}