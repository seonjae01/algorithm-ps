#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    for (int i = 1; i < sqrt(n); ++i)
    {
        if (n % i == 1)
            return i;
    }
    
    return n - 1;
}