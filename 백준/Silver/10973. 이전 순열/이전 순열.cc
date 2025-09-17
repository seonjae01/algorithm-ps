#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, pivot = -1;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++)
        cin >> nums[i];

    for (int i = n - 2; i >= 0; i--)
    {
        if (nums[i] > nums[i + 1])
        {
            pivot = i;
            break;
        }
    }

    if (pivot == -1)
    {
        cout << -1 << '\n';
        return 0;
    }

    for (int i = n - 1; i > pivot; i--)
    {
        if (nums[i] < nums[pivot])
        {
            int r = nums[i];
            nums[i] = nums[pivot];
            nums[pivot] = r;
            break;
        }
    }

    reverse(nums.begin() + pivot + 1, nums.end());

    for (auto num : nums)
        cout << num << ' ';
    cout << '\n';

    return 0;
}
