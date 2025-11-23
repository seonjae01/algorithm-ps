#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w, x, y;
    cin >> h >> w >> x >> y;
    vector<vector<int>> grid(h + x, vector<int>(w + y));

    for (int i = 0; i < h + x; i++)
        for (int j = 0; j < w + y; j++)
            cin >> grid[i][j];

    for (int i = x; i < h + x; i++)
        for (int j = y; j < w + y; j++)
            grid[i][j] -= grid[i - x][j - y];
    
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
            cout << grid[i][j] << ' ';
        cout << endl;
    }
}
