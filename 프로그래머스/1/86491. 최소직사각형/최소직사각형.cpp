#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int w = 0, h = 0;
    for (auto v : sizes)
    {
        sort(v.begin(), v.end());
        w = max(w, v[0]);
        h = max(h, v[1]);
    }
    return w * h;
}