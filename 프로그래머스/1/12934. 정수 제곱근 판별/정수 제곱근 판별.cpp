#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(long long n) {
    double sqr = sqrt(n);
    if (sqr == round(sqr))
        return (sqr + 1) * (sqr + 1);
    return -1;
}