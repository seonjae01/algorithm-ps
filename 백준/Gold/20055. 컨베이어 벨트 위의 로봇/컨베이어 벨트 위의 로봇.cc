#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    int m = n * 2;
    deque<int> A;
    deque<bool> robot(m, false);

    for (int i = 0; i < m; i++)
    {
        int a;
        cin >> a;
        A.push_back(a);
    }

    int cnt = 0;

    while (true)
    {
        cnt++;

        A.push_front(A.back());
        A.pop_back();
        robot.push_front(robot.back());
        robot.pop_back();

        if (robot[n - 1])
            robot[n - 1] = false;

        for (int i = n - 2; i >= 0; i--)
        {
            if (robot[i] && !robot[i + 1] && A[i + 1] > 0)
            {
                robot[i] = false;
                robot[i + 1] = true;
                A[i + 1]--;

                if (i + 1 == n - 1)
                    robot[n - 1] = false;
            }
        }

        if (!robot[0] && A[0] > 0)
        {
            robot[0] = true;
            A[0]--;
        }

        int t = 0;
        for (int i = 0; i < m; i++)
        {
            if (A[i] <= 0)
                t++;
        }

        if (t >= k)
            break;
    }

    cout << cnt << '\n';

    return 0;
}
