#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    int col = wallpaper.size();
    int row = wallpaper[0].size();
    int lux = 51, luy = 51, rdx = -1, rdy = -1;

    for (int i = 0 ; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            char file = wallpaper[i][j];
            if (file == '#')
            {
                lux = min(lux, i);
                luy = min(luy, j);
                rdx = max(rdx, i);
                rdy = max(rdy, j);
            }
        }
    }

    answer.push_back(lux);
    answer.push_back(luy);
    answer.push_back(rdx + 1);
    answer.push_back(rdy + 1);
    return answer;
}