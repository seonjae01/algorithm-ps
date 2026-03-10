#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> keyinput, vector<int> board) {
    vector<int> answer;
    int x = 0, y = 0;
    int ox = board[0] / 2;
    int oy = board[1] / 2;

    for (string cmd : keyinput)
    {
        char dir = cmd[0];
        if (dir == 'u' && y < oy)
            y++;
        else if (dir == 'd' && y > -oy)
            y--;
        else if (dir == 'r' && x < ox)
            x++;
        else if (dir == 'l' && x > -ox)
            x--;
    }

    answer.push_back(x);
    answer.push_back(y);
    return answer;
}