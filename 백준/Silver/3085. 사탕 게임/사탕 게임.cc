#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<char>> candy;

void swap(int i, int j, int u, int v)
{
    int r = candy[i][j];
    candy[i][j] = candy[u][v];
    candy[u][v] = r;
}

int maxline(int i, int j)
{
    int mx = 1;
    int count = 1;
    char c = candy[i][0];

    for (int v = 1; v < n; v++)
    {
        if (candy[i][v] != c)
        {
            c = candy[i][v];
            count = 1;
        }
        else
        {
            count++;
        }
        mx = max(mx, count);
    }

    count = 1;
    c = candy[0][j];

    for (int v = 1; v < n; v++)
    {
        if (candy[v][j] != c)
        {
            c = candy[v][j];
            count = 1;
        }
        else
        {
            count++;
        }
        mx = max(mx, count);
    }

    return mx;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int mx = 0;
    cin >> n;
    candy.resize(n, vector<char>(n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> candy[i][j];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i > 0)
            {
                swap(i, j, i - 1, j);
                mx = max(mx, maxline(i, j));
                swap(i, j, i - 1, j);
            }

            if (i < n - 1)
            {
                swap(i, j, i + 1, j);
                mx = max(mx, maxline(i, j));
                swap(i, j, i + 1, j);
            }

            if (j > 0)
            {
                swap(i, j, i, j - 1);
                mx = max(mx, maxline(i, j));
                swap(i, j, i, j - 1);
            }

            if (j < n - 1)
            {
                swap(i, j, i, j + 1);
                mx = max(mx, maxline(i, j));
                swap(i, j, i, j + 1);
            }
        }
    }

    cout << mx << '\n';
    
    return 0;
}
