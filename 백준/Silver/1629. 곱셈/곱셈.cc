#include <bits/stdc++.h>
using namespace std;

int a, b, c;

long long solve(long long k, long long p)
{
    if (p == 1)
        return k % c;

    long long power = solve(k, p / 2);
    power = (power * power) % c;

    if (p % 2 == 1)
        power = (power * k) % c;

    return power;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> a >> b >> c;
    cout << solve(a, b) << '\n';

    return 0;
}
