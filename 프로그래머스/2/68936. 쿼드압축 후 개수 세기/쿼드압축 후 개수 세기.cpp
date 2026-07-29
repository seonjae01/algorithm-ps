#include <string>
#include <vector>

using namespace std;

int cnt[2];

int quad(vector<vector<int>>& arr, int y, int x, int size)
{
    int k = arr[y][x];
    for (int i = y; i < y + size; i++)
    {
        for (int j = x; j < x + size; j++)
        {
            if (k != arr[i][j])
                return -1;
        }
    }
    
    return k;
}

void solve(vector<vector<int>>& arr, int x, int y, int size)
{
    int k = quad(arr, x, y, size);
    
    if (k != -1)
    {
        cnt[k]++;
        return;
    }
    
    int half = size / 2;
    solve(arr, x, y, half);
    solve(arr, x + half, y, half);
    solve(arr, x, y + half, half);
    solve(arr, x + half, y + half, half);
}

vector<int> solution(vector<vector<int>> arr) {
    solve(arr, 0, 0, arr.size());
    return { cnt[0], cnt[1] };
}