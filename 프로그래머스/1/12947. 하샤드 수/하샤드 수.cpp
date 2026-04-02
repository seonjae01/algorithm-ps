#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    int hs = 0;
    string str = to_string(x);
    
    for (char c : str)
        hs += c - '0';
    return x % hs == 0;
}