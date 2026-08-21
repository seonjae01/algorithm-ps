#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int base_col;

bool compare(const vector<int>& v1, const vector<int>& v2)
{
    if (v1[base_col] != v2[base_col])
        return v1[base_col] < v2[base_col];
    return v1[0] > v2[0];
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    base_col = col - 1;
    sort(data.begin(), data.end(), compare);
    
    for (int i = row_begin - 1; i < row_end; i++)
    {
        vector<int> d = data[i];
        int h = 0;
        for (int j : d)
        {
            h += j % (i + 1);
        }
        answer = answer ^ h;
    }
    
    return answer;
}