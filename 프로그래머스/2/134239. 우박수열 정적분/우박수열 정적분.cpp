#include <string>
#include <vector>

using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
    int n = 0;
    vector<int> graph = { k };
    vector<double> sum = { 0 };
    
    while (k != 1)
    {
        n++;
        if (k % 2 == 0) k /= 2;
        else k = k * 3 + 1;
        graph.push_back(k);
        sum.push_back(sum[n - 1] + (((double)graph[n - 1] + k) / 2));
    }
    
    vector<double> answer;
    for (auto range : ranges)
    {
        int a = range[0];
        int b = range[1];
        
        if (a <= n + b)
            answer.push_back(sum[n + b] - sum[a]);
        else
            answer.push_back(-1);
    }
    
    return answer;
}