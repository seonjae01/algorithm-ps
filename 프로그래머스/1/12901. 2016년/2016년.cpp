#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    int day = b;
    
    for (int i = 1; i < a; i++)
    {
        switch (i)
        {
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                day += 31;
                break;
                
            case 2:
                day += 29;
                break;
                
            default:
                day += 30;
                break;
        }
    }
    
    switch (day % 7)
    {
        case 0:
            return "THU";
        case 1:
            return "FRI";
        case 2:
            return "SAT";
        case 3:
            return "SUN";
        case 4:
            return "MON";
        case 5:
            return "TUE";
        case 6:
            return "WED";
    }
    
    return "";
}