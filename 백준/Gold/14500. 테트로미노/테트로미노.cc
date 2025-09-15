#include <bits/stdc++.h>
using namespace std;

struct Quad {
    pair<int, int> a, b, c, d;
};

vector<Quad> Quads = {
    { {0, 0}, {0, 1}, {0, 2}, {0, 3} },
    { {0, 0}, {1, 0}, {2, 0}, {3, 0} },
    { {0, 0}, {0, 1}, {1, 0}, {1, 1} },
    { {0, 0}, {1, 0}, {2, 0}, {2, 1} },
    { {2, 0}, {0, 1}, {1, 1}, {2, 1} },
    { {0, 0}, {0, 1}, {1, 0}, {2, 0} },
    { {0, 0}, {0, 1}, {1, 1}, {2, 1} },
    { {0, 0}, {1, 0}, {1, 1}, {1, 2} },
    { {1, 0}, {1, 1}, {1, 2}, {0, 2} },
    { {0, 0}, {1, 0}, {0, 1}, {0, 2} },
    { {0, 0}, {0, 1}, {0, 2}, {1, 2} },
    { {0, 0}, {1, 0}, {1, 1}, {2, 1} },
    { {0, 1}, {1, 0}, {1, 1}, {2, 0} },
    { {1, 0}, {0, 1}, {1, 1}, {0, 2} },
    { {0, 0}, {0, 1}, {1, 1}, {1, 2} },
    { {0, 0}, {0, 1}, {0, 2}, {1, 1} },
    { {0, 0}, {1, 0}, {2, 0}, {1, 1} },
    { {1, 0}, {0, 1}, {1, 1}, {2, 1} },
    { {1, 0}, {0, 1}, {1, 1}, {1, 2} },
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<int>> mino(504, vector<int>(504, 0));
    int mx = 0;
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> mino[i][j];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (auto quad : Quads)
            {
                int a = mino[i + quad.a.first][j + quad.a.second];
                int b = mino[i + quad.b.first][j + quad.b.second];
                int c = mino[i + quad.c.first][j + quad.c.second];
                int d = mino[i + quad.d.first][j + quad.d.second];

                mx = max(mx, a + b + c + d);
            }
        }
    }

    cout << mx << '\n';

    return 0;
}
