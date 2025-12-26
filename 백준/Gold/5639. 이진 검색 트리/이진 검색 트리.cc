#include <bits/stdc++.h>
using namespace std;

vector<int> preordered;

void postorder(int start, int end)
{
    if (start > end)
        return;

    if (start == end)
    {
        cout << preordered[start] << '\n';
        return;
    }

    int root = preordered[start];
    int idx = start + 1;

    while (idx <= end && preordered[idx] < root)
        idx++;

    postorder(start + 1, idx - 1);
    postorder(idx, end);
    cout << root << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (cin >> n)
        preordered.push_back(n);

    postorder(0, preordered.size() - 1);

    return 0;
}
