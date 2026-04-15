#include <string>
#include <vector>
#include <string>

using namespace std;

string solution(string s) {
    int len = s.length();
    return s.substr(len / 2 - (len % 2 == 0), 1 + (len % 2 == 0));
}