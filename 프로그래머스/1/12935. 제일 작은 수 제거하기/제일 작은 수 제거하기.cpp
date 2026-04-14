#include <string>
#include <vector>
#include <climits>

using namespace std;

vector<int> solution(vector<int> arr) {
    if (arr.size() <= 1)
        return { -1 };
    
    int mn = INT_MAX;
    int idx = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        int n = arr[i];
        if (mn > n)
        {
            mn = n;
            idx = i;
        }
    }
    
    arr.erase(arr.begin() + idx);
    return arr;
}