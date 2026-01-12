#include <bits/stdc++.h>
using namespace std;

bool in[1000001];
int arr[1000001], cnt[1000001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        in[arr[i]] = true;
    }

    for (int i = 0; i < n; i++)
    {
        int p = 2;
        int num = arr[i] * p;

        while (num < 1000001)
        {
            if (in[num])
            {
                cnt[arr[i]]++;
                cnt[num]--;
            }

            num = arr[i] * ++p;
        }
    }
    
    for (int i = 0; i < n; i++)
        cout << cnt[arr[i]] << ' ';

    return 0;
}
