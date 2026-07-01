#include <vector>
#include <set>

using namespace std;

int solution(vector<int> elements) {
    set<int> numset;
    
    for (int i = 1; i <= elements.size(); i++)
    {
        for (int j = 0; j < elements.size(); j++)
        {
            int sum = 0, idx = j;
            for (int k = 0; k < i; k++)
            {
                sum += elements[idx++];
                if (idx >= elements.size())
                    idx = 0;
            }
            numset.insert(sum);
        }
    }
    
    return numset.size();
}