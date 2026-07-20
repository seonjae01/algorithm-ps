#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers) {
    int len = numbers.size();
    vector<int> answer(len, -1);
    stack<int> st;
    st.push(numbers[len - 1]);
    
    for (int i = len - 2; i >= 0; i--)
    {
        while (!st.empty())
        {
            int n = st.top();
            st.pop();
            
            if (n > numbers[i])
            {
                answer[i] = n;
                st.push(n);
                break;
            }
        }
        
        st.push(numbers[i]);
    }
    
    return answer;
}