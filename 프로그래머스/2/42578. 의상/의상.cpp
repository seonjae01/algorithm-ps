#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> clothmap;
    
    for (auto cloth : clothes)
    {
        clothmap[cloth[1]]++;
    }
    
    for (auto cloth : clothmap)
    {
        answer *= cloth.second + 1;
    }
    
    return answer - 1;
}