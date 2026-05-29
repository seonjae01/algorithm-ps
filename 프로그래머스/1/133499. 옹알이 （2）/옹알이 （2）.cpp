#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    
    for (string bab : babbling)
    {
        int len = bab.length(), idx = 0;
        bool cont = true;
        int prev = -1;
        
        while (idx < len && cont)
        {
            switch (bab[idx])
            {
                case 'a':
                    if (prev == 0 || idx + 2 >= len || bab[idx + 1] != 'y' || bab[idx + 2] != 'a')
                        cont = false;
                    else
                        idx += 3;
                    prev = 0;
                    break;
                    
                case 'y':
                    if (prev == 1 || idx + 1 >= len || bab[idx + 1] != 'e')
                        cont = false;
                    else
                        idx += 2;
                    prev = 1;
                    break;
                    
                case 'w':
                    if (prev == 2 || idx + 2 >= len || bab[idx + 1] != 'o' || bab[idx + 2] != 'o')
                        cont = false;
                    else
                        idx += 3;
                    prev = 2;
                    break;
                    
                case 'm':
                    if (prev == 3 || idx + 1 >= len || bab[idx + 1] != 'a')
                        cont = false;
                    else
                        idx += 2;
                    prev = 3;
                    break;
                    
                default:
                    cont = false;
                    break;
            }
        }
        
        if (cont) answer++;
    }
    return answer;
}