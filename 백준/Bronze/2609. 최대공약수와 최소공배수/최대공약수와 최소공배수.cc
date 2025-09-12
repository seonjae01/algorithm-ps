#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    while (b)
    {
        int r = a % b;
        a = b;
        b = r;
    }

    return a;
}

int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    if (n < m)
    {
        int r = n;
        n = m;
        m = r;
    }

    cout << gcd(n, m) << '\n' << lcm(n, m) << '\n';
}
