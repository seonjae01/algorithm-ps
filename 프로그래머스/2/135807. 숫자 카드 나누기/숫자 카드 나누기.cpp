#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    
    return gcd(b, a % b);
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int gcdA = arrayA[0];
    for (int i = 0; i < arrayA.size(); i++)
        gcdA = gcd(gcdA, arrayA[i]);
    
    int gcdB = arrayB[0];
    for (int i = 0; i < arrayB.size(); i++)
        gcdB = gcd(gcdB, arrayB[i]);
    
    bool notDividedA = true;
    for (int a : arrayA)
    {
        if (a % gcdB == 0)
        {
            notDividedA = false;
            break;
        }
    }
    
    bool notDividedB = true;
    for (int b : arrayB)
    {
        if (b % gcdA == 0)
        {
            notDividedB = false;
            break;
        }
    }
    
    if (notDividedA && notDividedB)
        return max(gcdA, gcdB);
    else if (notDividedA)
        return gcdB;
    else if (notDividedB)
        return gcdA;
    else
        return 0;
}