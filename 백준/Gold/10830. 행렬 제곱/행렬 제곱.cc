#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000;
int n;
long long b;

vector<vector<long long>> mul(vector<vector<long long>> A, vector<vector<long long>> B)
{
    vector<vector<long long>> C(n, vector<long long>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
                C[i][j] %= MOD;
            }
        }
    }

    return C;
}

vector<vector<long long>> power(vector<vector<long long>> m, long long b)
{
    if (b == 1)
        return m;

    auto half = power(m, b / 2);
    auto temp = mul(half, half);

    if (b % 2 == 1)
        return mul(temp, m);

    return temp;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> b;
    vector<vector<long long>> mat(n, vector<long long>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];
    }

    auto res = power(mat, b);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << res[i][j] % MOD << ' ';
        cout << '\n';
    }

    return 0;
}
