#include <string>
#include <vector>

using namespace std;

int m, answer;
vector<bool> col, diag1, diag2;

void nqueen(int r)
{
    if (r == m)
    {
        answer++;
        return;
    }
    
    for (int c = 0; c < m; c++)
    {
        if (col[c] || diag1[r + c] || diag2[r - c + m])
            continue;
        
        col[c] = true;
        diag1[r + c] = true;
        diag2[r - c + m] = true;
        
        nqueen(r + 1);
        
        col[c] = false;
        diag1[r + c] = false;
        diag2[r - c + m] = false;
    }
}

int solution(int n) {
    m = n;
    col.resize(m);
    diag1.resize(m + m);
    diag2.resize(m + m);
    nqueen(0);
    return answer;
}