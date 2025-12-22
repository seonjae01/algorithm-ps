#include <bits/stdc++.h>
using namespace std;

map<char, pair<char, char>> graph;

void preorder(char c)
{
    if (c == '.')
        return;

    cout << c;
    preorder(graph[c].first);
    preorder(graph[c].second);
}

void inorder(char c)
{
    if (c == '.')
        return;

    inorder(graph[c].first);
    cout << c;
    inorder(graph[c].second);
}

void postorder(char c)
{
    if (c == '.')
        return;

    postorder(graph[c].first);
    postorder(graph[c].second);
    cout << c;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        char e, l, r;
        cin >> e >> l >> r;
        graph[e].first = l;
        graph[e].second = r;
    }

    preorder('A');
    cout << '\n';
    inorder('A');
    cout << '\n';
    postorder('A');
    cout << '\n';

    return 0;
}
