#include <vector>
#include <stack>
#include <iostream>
using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    int n = 0;
    stack<int> st;
    
    for (int i = 1; i <= order.size(); i++)
    {
        if (i == order[n])
        {
            answer++;
            n++;
        }
        else
        {
            st.push(i);
        }
        
        while (!st.empty())
        {
            int p = st.top();

            if (p == order[n])
            {
                st.pop();
                answer++;
                n++;
            }
            else
            {
                break;
            }
        }
    }
    
    return answer;
}