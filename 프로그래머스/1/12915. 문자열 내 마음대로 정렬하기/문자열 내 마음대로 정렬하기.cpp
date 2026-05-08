#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int M;

bool compare(string s1, string s2)
{
    if (s1[M] == s2[M])
        return s1 < s2;
    return s1[M] < s2[M];
}

vector<string> solution(vector<string> strings, int n) {
    M = n;
    sort(strings.begin(), strings.end(), compare);
    return strings;
}