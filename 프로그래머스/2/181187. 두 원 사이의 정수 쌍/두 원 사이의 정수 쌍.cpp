#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;
    long long sqr1 = (long long)r1 * r1;
    long long sqr2 = (long long)r2 * r2;
    
    for (long long i = 1; i <= r2; i++)
    {
        long long maxY = floor(sqrt(sqr2 - i * i));
        long long minY = 0;
        
        if (i < r1)
            minY = ceil(sqrt(sqr1 - i * i));

        answer += (maxY - minY + 1);
    }

    return answer * 4;
}